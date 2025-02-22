/*
 * SPDX-FileCopyrightText: 2017-2017 CSSlayer <wengxt@gmail.com>
 *
 * SPDX-License-Identifier: LGPL-2.1-or-later
 *
 */
#ifndef _FCITX_UI_CLASSIC_WAYLANDSHMWINDOW_H_
#define _FCITX_UI_CLASSIC_WAYLANDSHMWINDOW_H_

#include <cstdint>
#include <memory>
#include <vector>
#include <cairo.h>
#include "fcitx-utils/eventloopinterface.h"
#include "buffer.h"
#include "waylandui.h"
#include "waylandwindow.h"

namespace fcitx::classicui {

class WaylandShmWindow : public WaylandWindow {
public:
    WaylandShmWindow(WaylandUI *ui);
    ~WaylandShmWindow();

    void destroyWindow();
    cairo_surface_t *prerender() override;
    void render() override;
    void hide() override;

private:
    void newBuffer(uint32_t width, uint32_t height);

    std::shared_ptr<wayland::WlShm> shm_;
    std::vector<std::unique_ptr<wayland::Buffer>> buffers_;
    // Pointer to the current buffer.
    wayland::Buffer *buffer_ = nullptr;
    bool pending_ = false;
    std::unique_ptr<EventSource> deferEvent_;
};

} // namespace fcitx::classicui

#endif // _FCITX_UI_CLASSIC_WAYLANDSHMWINDOW_H_

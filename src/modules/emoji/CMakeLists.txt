if (ENABLE_EMOJI)
    add_fcitx5_addon(emoji emoji.cpp)
    target_link_libraries(emoji Fcitx5::Core ZLIB::ZLIB)
    install(TARGETS emoji DESTINATION "${FCITX_INSTALL_ADDONDIR}")
    install(FILES "${CMAKE_CURRENT_BINARY_DIR}/emoji.conf" DESTINATION "${FCITX_INSTALL_PKGDATADIR}/addon"
            COMPONENT config)
    add_subdirectory(data)
endif()

configure_file(emoji.conf.in.in emoji.conf.in @ONLY)
fcitx5_translate_desktop_file(${CMAKE_CURRENT_BINARY_DIR}/emoji.conf.in emoji.conf)
fcitx5_export_module(Emoji TARGET emoji BUILD_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_SOURCE_DIR}" HEADERS emoji_public.h INSTALL)

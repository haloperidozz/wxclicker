add_executable(wxclicker
    application/ClickerApplication.cxx
    mouse/MouseInputBackendRegistry.cxx
    mouse/RegisterPlatformBackends.cxx
    services/AutoClicker.cxx
    ui/generated/BaseClickerFrame.cpp
    ui/PickScreenPointDialog.cxx
    ui/ClickerFrame.cxx
)

target_compile_features(wxclicker PRIVATE cxx_std_20)

target_include_directories(wxclicker PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/buildinfo/BuildInfo.hxx.in
    ${CMAKE_CURRENT_SOURCE_DIR}/buildinfo/BuildInfo.hxx
    @ONLY
)

target_link_libraries(wxclicker PRIVATE wx::core wx::base)

if (WIN32)
    target_compile_definitions(wxclicker PRIVATE WXCLICKER_WIN32)
    target_sources(wxclicker PRIVATE
        mouse/win32/BaseMouseInputBackend.cxx
        mouse/win32/NtUserSendInputBackend.cxx
        mouse/win32/SendInputBackend.cxx
        resource/WxClicker.rc
    )
    set_target_properties(wxclicker PROPERTIES WIN32_EXECUTABLE TRUE)
elseif (UNIX AND NOT APPLE) # Linux
    find_package(X11 REQUIRED COMPONENTS Xtst)
    target_compile_definitions(wxclicker PRIVATE WXCLICKER_LINUX)
    target_sources(wxclicker PRIVATE
        mouse/gnulinux/UinputMouseInputBackend.cxx
        mouse/x11/XTestMouseInputBackend.cxx
    )
    target_link_libraries(wxclicker PRIVATE X11::X11 X11::Xtst)
else ()
    message(FATAL_ERROR "${CMAKE_SYSTEM_NAME} not supported")
endif ()

if (MINGW AND CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_link_options(wxclicker PRIVATE
        $<$<CONFIG:Release>:-s>
        -static-libgcc
        -static-libstdc++
        -static
    )
endif ()

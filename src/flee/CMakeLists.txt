add_executable(
    flee
        frame_timer.cpp
        main.cpp
        scene.cpp
        view.cpp
)

target_link_libraries(flee PRIVATE sfml-graphics)
add_dependencies(flee prepare_gfx)

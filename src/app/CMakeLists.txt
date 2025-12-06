add_executable(app
    main.cpp
    # other source files for UI, etc.
)

target_link_libraries(app
    PRIVATE
        core
        vision
        image
        robotics
        Qt6::Widgets
        ${OpenCV_LIBS}   # if app links OpenCV directly
)

add_executable(avisys
    main.cpp
    MainWindow.cpp
)

target_link_libraries(avisys
    PRIVATE
        core
        Qt6::Widgets
        ${OpenCV_LIBS}
)

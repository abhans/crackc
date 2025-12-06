add_library(robotics
    # src/*.cpp files for vision module
)

target_link_libraries(robotics
    PUBLIC
        ${OpenCV_LIBS}
)

target_include_directories(robotics
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_library(robotics
    # src/*.cpp ...
)

target_include_directories(robotics
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Vision depends on core
target_link_libraries(robotics
    PUBLIC
        core
        ${OpenCV_LIBS}
)

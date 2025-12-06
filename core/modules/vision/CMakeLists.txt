add_library(vision
    # src/*.cpp ...
)

target_include_directories(vision
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Vision depends on core
target_link_libraries(vision
    PUBLIC
        core
        ${OpenCV_LIBS}
)

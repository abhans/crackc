add_library(image
    # src/*.cpp ...
)

target_include_directories(image
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Vision depends on core
target_link_libraries(image
    PUBLIC
        core
        ${OpenCV_LIBS}
)

add_library(vision
    # src/*.cpp files for vision module
)

target_link_libraries(vision
    PUBLIC
        ${OpenCV_LIBS}
)

target_include_directories(vision
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

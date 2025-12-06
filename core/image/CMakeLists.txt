add_library(image
    # src/*.cpp files for vision module
)

target_link_libraries(image
    PUBLIC
        ${OpenCV_LIBS}
)

target_include_directories(image
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

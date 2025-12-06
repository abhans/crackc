add_library(core
    # src/*.cpp ...
)

target_include_directories(core
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)
# Link external libs if core needs them
target_link_libraries(core
    PUBLIC
        ${OpenCV_LIBS}   # if core uses OpenCV
)

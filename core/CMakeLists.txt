# Add subdirectories for internal modules
add_subdirectory(vision)
add_subdirectory(image)
add_subdirectory(robotics)

# Create a core library
add_library(core INTERFACE)

# Link all internal modules to core
target_link_libraries(core
    INTERFACE
        vision
        image
        robotics
)

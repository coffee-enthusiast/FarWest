cmake_minimum_required(VERSION 3.28.0)

project(FarWest)

# Include the subdirectories
add_subdirectory(UF)
add_subdirectory(GE)
add_subdirectory(GCE)
add_subdirectory(FS)
add_subdirectory(CE)
add_subdirectory(UI)

# Main executable
add_executable(main main.cpp)

# Link the libraries from comp1 and comp2
target_link_libraries(main PRIVATE GE UI)

# Include directories for main executable
target_include_directories(main PUBLIC GE/include UI/include )
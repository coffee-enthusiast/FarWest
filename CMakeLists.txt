cmake_minimum_required(VERSION 3.28.0)

project(FarWest)

# Include the subdirectories
add_subdirectory(UI)
add_subdirectory(UF)
add_subdirectory(GE)
add_subdirectory(GCE)
add_subdirectory(FS)
add_subdirectory(CE)


# Main executable
add_executable(main main.cpp)

# Link the libraries from comp1 and comp2
target_link_libraries(main PRIVATE GE UI)

# Include directories for main executable
target_include_directories(main PUBLIC GE/include UI/include)

# Enable testing in the project
enable_testing()

# Add Google Test subdirectory
add_subdirectory(external/googletest)

# Link each component's tests with Google Test
add_executable(comp1Tests tests/ItemTest.cpp)
target_link_libraries(comp1Tests gtest gtest_main UI CE) # Link with comp1 library
target_include_directories(comp1Tests PUBLIC UI/include  CE/include)


add_test(NAME my_test COMMAND comp1Tests)  # Add the test to CTest
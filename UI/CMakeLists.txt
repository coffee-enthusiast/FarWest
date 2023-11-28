
file(GLOB My_Source_Files src/*.cpp)
add_library(UI STATIC ${My_Source_Files})

# Include directories for GameEngine
target_include_directories(UI PUBLIC include)

# Include directories for Component 1
target_include_directories(UI PUBLIC UF/include)

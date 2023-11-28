# GameEngine, using Player class from CharactersAndEntities

file(GLOB My_Source_Files src/*.cpp)
add_library(GE STATIC ${My_Source_Files})

# Include directories for Component 1
target_include_directories(GE PUBLIC include)
target_include_directories(GE PUBLIC UF/include)
target_link_libraries(GE PUBLIC UF)

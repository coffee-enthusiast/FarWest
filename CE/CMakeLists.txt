# GameEngine, using Player class from CharactersAndEntities

file(GLOB My_Source_Files src/*.cpp)

# Component 1: CharactersAndEntities library
add_library(CE STATIC
    ${My_Source_Files}
)

# Include directories for Component 1
target_include_directories(CE PUBLIC include)
target_include_directories(CE PUBLIC UF/include)
target_include_directories(CE PUBLIC UI/include)

target_link_libraries(CE PUBLIC UI)

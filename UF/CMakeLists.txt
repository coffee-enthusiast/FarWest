
file(GLOB My_Source_Files src/*.cpp)

# Component 1: CharactersAndEntities library
add_library(UF STATIC
    ${My_Source_Files}
)

# Include directories for Component 1
target_include_directories(UF PUBLIC include)
target_include_directories(UF PUBLIC CE/include)

target_link_libraries(UF PUBLIC CE)
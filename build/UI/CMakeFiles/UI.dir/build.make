# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.28

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\mario\Documents\Code\FarWest

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\mario\Documents\Code\FarWest\build

# Include any dependencies generated for this target.
include UI/CMakeFiles/UI.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include UI/CMakeFiles/UI.dir/compiler_depend.make

# Include the progress variables for this target.
include UI/CMakeFiles/UI.dir/progress.make

# Include the compile flags for this target's objects.
include UI/CMakeFiles/UI.dir/flags.make

UI/CMakeFiles/UI.dir/src/IOFunctions.cpp.obj: UI/CMakeFiles/UI.dir/flags.make
UI/CMakeFiles/UI.dir/src/IOFunctions.cpp.obj: UI/CMakeFiles/UI.dir/includes_CXX.rsp
UI/CMakeFiles/UI.dir/src/IOFunctions.cpp.obj: C:/Users/mario/Documents/Code/FarWest/UI/src/IOFunctions.cpp
UI/CMakeFiles/UI.dir/src/IOFunctions.cpp.obj: UI/CMakeFiles/UI.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\mario\Documents\Code\FarWest\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object UI/CMakeFiles/UI.dir/src/IOFunctions.cpp.obj"
	cd /d C:\Users\mario\Documents\Code\FarWest\build\UI && C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT UI/CMakeFiles/UI.dir/src/IOFunctions.cpp.obj -MF CMakeFiles\UI.dir\src\IOFunctions.cpp.obj.d -o CMakeFiles\UI.dir\src\IOFunctions.cpp.obj -c C:\Users\mario\Documents\Code\FarWest\UI\src\IOFunctions.cpp

UI/CMakeFiles/UI.dir/src/IOFunctions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/UI.dir/src/IOFunctions.cpp.i"
	cd /d C:\Users\mario\Documents\Code\FarWest\build\UI && C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\mario\Documents\Code\FarWest\UI\src\IOFunctions.cpp > CMakeFiles\UI.dir\src\IOFunctions.cpp.i

UI/CMakeFiles/UI.dir/src/IOFunctions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/UI.dir/src/IOFunctions.cpp.s"
	cd /d C:\Users\mario\Documents\Code\FarWest\build\UI && C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\mario\Documents\Code\FarWest\UI\src\IOFunctions.cpp -o CMakeFiles\UI.dir\src\IOFunctions.cpp.s

UI/CMakeFiles/UI.dir/src/Trace.cpp.obj: UI/CMakeFiles/UI.dir/flags.make
UI/CMakeFiles/UI.dir/src/Trace.cpp.obj: UI/CMakeFiles/UI.dir/includes_CXX.rsp
UI/CMakeFiles/UI.dir/src/Trace.cpp.obj: C:/Users/mario/Documents/Code/FarWest/UI/src/Trace.cpp
UI/CMakeFiles/UI.dir/src/Trace.cpp.obj: UI/CMakeFiles/UI.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\mario\Documents\Code\FarWest\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object UI/CMakeFiles/UI.dir/src/Trace.cpp.obj"
	cd /d C:\Users\mario\Documents\Code\FarWest\build\UI && C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT UI/CMakeFiles/UI.dir/src/Trace.cpp.obj -MF CMakeFiles\UI.dir\src\Trace.cpp.obj.d -o CMakeFiles\UI.dir\src\Trace.cpp.obj -c C:\Users\mario\Documents\Code\FarWest\UI\src\Trace.cpp

UI/CMakeFiles/UI.dir/src/Trace.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/UI.dir/src/Trace.cpp.i"
	cd /d C:\Users\mario\Documents\Code\FarWest\build\UI && C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\mario\Documents\Code\FarWest\UI\src\Trace.cpp > CMakeFiles\UI.dir\src\Trace.cpp.i

UI/CMakeFiles/UI.dir/src/Trace.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/UI.dir/src/Trace.cpp.s"
	cd /d C:\Users\mario\Documents\Code\FarWest\build\UI && C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\mario\Documents\Code\FarWest\UI\src\Trace.cpp -o CMakeFiles\UI.dir\src\Trace.cpp.s

# Object files for target UI
UI_OBJECTS = \
"CMakeFiles/UI.dir/src/IOFunctions.cpp.obj" \
"CMakeFiles/UI.dir/src/Trace.cpp.obj"

# External object files for target UI
UI_EXTERNAL_OBJECTS =

UI/libUI.a: UI/CMakeFiles/UI.dir/src/IOFunctions.cpp.obj
UI/libUI.a: UI/CMakeFiles/UI.dir/src/Trace.cpp.obj
UI/libUI.a: UI/CMakeFiles/UI.dir/build.make
UI/libUI.a: UI/CMakeFiles/UI.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\mario\Documents\Code\FarWest\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libUI.a"
	cd /d C:\Users\mario\Documents\Code\FarWest\build\UI && $(CMAKE_COMMAND) -P CMakeFiles\UI.dir\cmake_clean_target.cmake
	cd /d C:\Users\mario\Documents\Code\FarWest\build\UI && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\UI.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
UI/CMakeFiles/UI.dir/build: UI/libUI.a
.PHONY : UI/CMakeFiles/UI.dir/build

UI/CMakeFiles/UI.dir/clean:
	cd /d C:\Users\mario\Documents\Code\FarWest\build\UI && $(CMAKE_COMMAND) -P CMakeFiles\UI.dir\cmake_clean.cmake
.PHONY : UI/CMakeFiles/UI.dir/clean

UI/CMakeFiles/UI.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\mario\Documents\Code\FarWest C:\Users\mario\Documents\Code\FarWest\UI C:\Users\mario\Documents\Code\FarWest\build C:\Users\mario\Documents\Code\FarWest\build\UI C:\Users\mario\Documents\Code\FarWest\build\UI\CMakeFiles\UI.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : UI/CMakeFiles/UI.dir/depend

# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\STEAM\Documents\GitHub\Swamphacks2k22

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\STEAM\Documents\GitHub\Swamphacks2k22\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Swamphacks2k22.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/Swamphacks2k22.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Swamphacks2k22.dir/flags.make

CMakeFiles/Swamphacks2k22.dir/src/main.cpp.obj: CMakeFiles/Swamphacks2k22.dir/flags.make
CMakeFiles/Swamphacks2k22.dir/src/main.cpp.obj: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\STEAM\Documents\GitHub\Swamphacks2k22\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Swamphacks2k22.dir/src/main.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Swamphacks2k22.dir\src\main.cpp.obj -c C:\Users\STEAM\Documents\GitHub\Swamphacks2k22\src\main.cpp

CMakeFiles/Swamphacks2k22.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Swamphacks2k22.dir/src/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\STEAM\Documents\GitHub\Swamphacks2k22\src\main.cpp > CMakeFiles\Swamphacks2k22.dir\src\main.cpp.i

CMakeFiles/Swamphacks2k22.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Swamphacks2k22.dir/src/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\STEAM\Documents\GitHub\Swamphacks2k22\src\main.cpp -o CMakeFiles\Swamphacks2k22.dir\src\main.cpp.s

# Object files for target Swamphacks2k22
Swamphacks2k22_OBJECTS = \
"CMakeFiles/Swamphacks2k22.dir/src/main.cpp.obj"

# External object files for target Swamphacks2k22
Swamphacks2k22_EXTERNAL_OBJECTS =

Swamphacks2k22.exe: CMakeFiles/Swamphacks2k22.dir/src/main.cpp.obj
Swamphacks2k22.exe: CMakeFiles/Swamphacks2k22.dir/build.make
Swamphacks2k22.exe: CMakeFiles/Swamphacks2k22.dir/linklibs.rsp
Swamphacks2k22.exe: CMakeFiles/Swamphacks2k22.dir/objects1.rsp
Swamphacks2k22.exe: CMakeFiles/Swamphacks2k22.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\STEAM\Documents\GitHub\Swamphacks2k22\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Swamphacks2k22.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Swamphacks2k22.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Swamphacks2k22.dir/build: Swamphacks2k22.exe
.PHONY : CMakeFiles/Swamphacks2k22.dir/build

CMakeFiles/Swamphacks2k22.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Swamphacks2k22.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Swamphacks2k22.dir/clean

CMakeFiles/Swamphacks2k22.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\STEAM\Documents\GitHub\Swamphacks2k22 C:\Users\STEAM\Documents\GitHub\Swamphacks2k22 C:\Users\STEAM\Documents\GitHub\Swamphacks2k22\cmake-build-debug C:\Users\STEAM\Documents\GitHub\Swamphacks2k22\cmake-build-debug C:\Users\STEAM\Documents\GitHub\Swamphacks2k22\cmake-build-debug\CMakeFiles\Swamphacks2k22.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Swamphacks2k22.dir/depend


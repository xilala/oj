# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.14

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "F:\Program Files\JetBrains\CLion 2019.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "F:\Program Files\JetBrains\CLion 2019.2.1\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\ldx\oj\l715

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\ldx\oj\l715\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/l715.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/l715.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/l715.dir/flags.make

CMakeFiles/l715.dir/main.cpp.obj: CMakeFiles/l715.dir/flags.make
CMakeFiles/l715.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\ldx\oj\l715\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/l715.dir/main.cpp.obj"
	E:\ldx\env\clion\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\l715.dir\main.cpp.obj -c E:\ldx\oj\l715\main.cpp

CMakeFiles/l715.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/l715.dir/main.cpp.i"
	E:\ldx\env\clion\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\ldx\oj\l715\main.cpp > CMakeFiles\l715.dir\main.cpp.i

CMakeFiles/l715.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/l715.dir/main.cpp.s"
	E:\ldx\env\clion\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\ldx\oj\l715\main.cpp -o CMakeFiles\l715.dir\main.cpp.s

# Object files for target l715
l715_OBJECTS = \
"CMakeFiles/l715.dir/main.cpp.obj"

# External object files for target l715
l715_EXTERNAL_OBJECTS =

l715.exe: CMakeFiles/l715.dir/main.cpp.obj
l715.exe: CMakeFiles/l715.dir/build.make
l715.exe: CMakeFiles/l715.dir/linklibs.rsp
l715.exe: CMakeFiles/l715.dir/objects1.rsp
l715.exe: CMakeFiles/l715.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\ldx\oj\l715\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable l715.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\l715.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/l715.dir/build: l715.exe

.PHONY : CMakeFiles/l715.dir/build

CMakeFiles/l715.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\l715.dir\cmake_clean.cmake
.PHONY : CMakeFiles/l715.dir/clean

CMakeFiles/l715.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\ldx\oj\l715 E:\ldx\oj\l715 E:\ldx\oj\l715\cmake-build-debug E:\ldx\oj\l715\cmake-build-debug E:\ldx\oj\l715\cmake-build-debug\CMakeFiles\l715.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/l715.dir/depend


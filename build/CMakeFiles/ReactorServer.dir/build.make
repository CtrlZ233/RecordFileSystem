# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ctrlz/workSpace/RecordFileSystem

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ctrlz/workSpace/RecordFileSystem/build

# Include any dependencies generated for this target.
include CMakeFiles/ReactorServer.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ReactorServer.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ReactorServer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ReactorServer.dir/flags.make

CMakeFiles/ReactorServer.dir/main.cpp.o: CMakeFiles/ReactorServer.dir/flags.make
CMakeFiles/ReactorServer.dir/main.cpp.o: ../main.cpp
CMakeFiles/ReactorServer.dir/main.cpp.o: CMakeFiles/ReactorServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ctrlz/workSpace/RecordFileSystem/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ReactorServer.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ReactorServer.dir/main.cpp.o -MF CMakeFiles/ReactorServer.dir/main.cpp.o.d -o CMakeFiles/ReactorServer.dir/main.cpp.o -c /home/ctrlz/workSpace/RecordFileSystem/main.cpp

CMakeFiles/ReactorServer.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ReactorServer.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ctrlz/workSpace/RecordFileSystem/main.cpp > CMakeFiles/ReactorServer.dir/main.cpp.i

CMakeFiles/ReactorServer.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ReactorServer.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ctrlz/workSpace/RecordFileSystem/main.cpp -o CMakeFiles/ReactorServer.dir/main.cpp.s

# Object files for target ReactorServer
ReactorServer_OBJECTS = \
"CMakeFiles/ReactorServer.dir/main.cpp.o"

# External object files for target ReactorServer
ReactorServer_EXTERNAL_OBJECTS =

ReactorServer: CMakeFiles/ReactorServer.dir/main.cpp.o
ReactorServer: CMakeFiles/ReactorServer.dir/build.make
ReactorServer: CMakeFiles/ReactorServer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ctrlz/workSpace/RecordFileSystem/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ReactorServer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ReactorServer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ReactorServer.dir/build: ReactorServer
.PHONY : CMakeFiles/ReactorServer.dir/build

CMakeFiles/ReactorServer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ReactorServer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ReactorServer.dir/clean

CMakeFiles/ReactorServer.dir/depend:
	cd /home/ctrlz/workSpace/RecordFileSystem/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ctrlz/workSpace/RecordFileSystem /home/ctrlz/workSpace/RecordFileSystem /home/ctrlz/workSpace/RecordFileSystem/build /home/ctrlz/workSpace/RecordFileSystem/build /home/ctrlz/workSpace/RecordFileSystem/build/CMakeFiles/ReactorServer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ReactorServer.dir/depend


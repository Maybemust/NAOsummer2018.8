# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/chen/Naoqi/worktree/avoidcollision1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/chen/Naoqi/worktree/avoidcollision1/build-mytoolchain

# Include any dependencies generated for this target.
include CMakeFiles/avoidcollision.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/avoidcollision.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/avoidcollision.dir/flags.make

CMakeFiles/avoidcollision.dir/avoidcollision.cpp.o: CMakeFiles/avoidcollision.dir/flags.make
CMakeFiles/avoidcollision.dir/avoidcollision.cpp.o: ../avoidcollision.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/chen/Naoqi/worktree/avoidcollision1/build-mytoolchain/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/avoidcollision.dir/avoidcollision.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/avoidcollision.dir/avoidcollision.cpp.o -c /home/chen/Naoqi/worktree/avoidcollision1/avoidcollision.cpp

CMakeFiles/avoidcollision.dir/avoidcollision.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/avoidcollision.dir/avoidcollision.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/chen/Naoqi/worktree/avoidcollision1/avoidcollision.cpp > CMakeFiles/avoidcollision.dir/avoidcollision.cpp.i

CMakeFiles/avoidcollision.dir/avoidcollision.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/avoidcollision.dir/avoidcollision.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/chen/Naoqi/worktree/avoidcollision1/avoidcollision.cpp -o CMakeFiles/avoidcollision.dir/avoidcollision.cpp.s

CMakeFiles/avoidcollision.dir/avoidcollision.cpp.o.requires:
.PHONY : CMakeFiles/avoidcollision.dir/avoidcollision.cpp.o.requires

CMakeFiles/avoidcollision.dir/avoidcollision.cpp.o.provides: CMakeFiles/avoidcollision.dir/avoidcollision.cpp.o.requires
	$(MAKE) -f CMakeFiles/avoidcollision.dir/build.make CMakeFiles/avoidcollision.dir/avoidcollision.cpp.o.provides.build
.PHONY : CMakeFiles/avoidcollision.dir/avoidcollision.cpp.o.provides

CMakeFiles/avoidcollision.dir/avoidcollision.cpp.o.provides.build: CMakeFiles/avoidcollision.dir/avoidcollision.cpp.o

CMakeFiles/avoidcollision.dir/ycylib2.cpp.o: CMakeFiles/avoidcollision.dir/flags.make
CMakeFiles/avoidcollision.dir/ycylib2.cpp.o: ../ycylib2.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/chen/Naoqi/worktree/avoidcollision1/build-mytoolchain/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/avoidcollision.dir/ycylib2.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/avoidcollision.dir/ycylib2.cpp.o -c /home/chen/Naoqi/worktree/avoidcollision1/ycylib2.cpp

CMakeFiles/avoidcollision.dir/ycylib2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/avoidcollision.dir/ycylib2.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/chen/Naoqi/worktree/avoidcollision1/ycylib2.cpp > CMakeFiles/avoidcollision.dir/ycylib2.cpp.i

CMakeFiles/avoidcollision.dir/ycylib2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/avoidcollision.dir/ycylib2.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/chen/Naoqi/worktree/avoidcollision1/ycylib2.cpp -o CMakeFiles/avoidcollision.dir/ycylib2.cpp.s

CMakeFiles/avoidcollision.dir/ycylib2.cpp.o.requires:
.PHONY : CMakeFiles/avoidcollision.dir/ycylib2.cpp.o.requires

CMakeFiles/avoidcollision.dir/ycylib2.cpp.o.provides: CMakeFiles/avoidcollision.dir/ycylib2.cpp.o.requires
	$(MAKE) -f CMakeFiles/avoidcollision.dir/build.make CMakeFiles/avoidcollision.dir/ycylib2.cpp.o.provides.build
.PHONY : CMakeFiles/avoidcollision.dir/ycylib2.cpp.o.provides

CMakeFiles/avoidcollision.dir/ycylib2.cpp.o.provides.build: CMakeFiles/avoidcollision.dir/ycylib2.cpp.o

CMakeFiles/avoidcollision.dir/main.cpp.o: CMakeFiles/avoidcollision.dir/flags.make
CMakeFiles/avoidcollision.dir/main.cpp.o: ../main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/chen/Naoqi/worktree/avoidcollision1/build-mytoolchain/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/avoidcollision.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/avoidcollision.dir/main.cpp.o -c /home/chen/Naoqi/worktree/avoidcollision1/main.cpp

CMakeFiles/avoidcollision.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/avoidcollision.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/chen/Naoqi/worktree/avoidcollision1/main.cpp > CMakeFiles/avoidcollision.dir/main.cpp.i

CMakeFiles/avoidcollision.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/avoidcollision.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/chen/Naoqi/worktree/avoidcollision1/main.cpp -o CMakeFiles/avoidcollision.dir/main.cpp.s

CMakeFiles/avoidcollision.dir/main.cpp.o.requires:
.PHONY : CMakeFiles/avoidcollision.dir/main.cpp.o.requires

CMakeFiles/avoidcollision.dir/main.cpp.o.provides: CMakeFiles/avoidcollision.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/avoidcollision.dir/build.make CMakeFiles/avoidcollision.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/avoidcollision.dir/main.cpp.o.provides

CMakeFiles/avoidcollision.dir/main.cpp.o.provides.build: CMakeFiles/avoidcollision.dir/main.cpp.o

# Object files for target avoidcollision
avoidcollision_OBJECTS = \
"CMakeFiles/avoidcollision.dir/avoidcollision.cpp.o" \
"CMakeFiles/avoidcollision.dir/ycylib2.cpp.o" \
"CMakeFiles/avoidcollision.dir/main.cpp.o"

# External object files for target avoidcollision
avoidcollision_EXTERNAL_OBJECTS =

sdk/bin/avoidcollision: CMakeFiles/avoidcollision.dir/avoidcollision.cpp.o
sdk/bin/avoidcollision: CMakeFiles/avoidcollision.dir/ycylib2.cpp.o
sdk/bin/avoidcollision: CMakeFiles/avoidcollision.dir/main.cpp.o
sdk/bin/avoidcollision: CMakeFiles/avoidcollision.dir/build.make
sdk/bin/avoidcollision: /home/chen/Naoqi/naoqi-sdk-2.1.2.17-linux64/lib/libalvision.so
sdk/bin/avoidcollision: /home/chen/Naoqi/naoqi-sdk-2.1.2.17-linux64/lib/libalextractor.so
sdk/bin/avoidcollision: /home/chen/Naoqi/naoqi-sdk-2.1.2.17-linux64/lib/libalthread.so
sdk/bin/avoidcollision: /home/chen/Naoqi/naoqi-sdk-2.1.2.17-linux64/lib/libalproxies.so
sdk/bin/avoidcollision: /home/chen/Naoqi/naoqi-sdk-2.1.2.17-linux64/lib/libalcommon.so
sdk/bin/avoidcollision: /home/chen/Naoqi/naoqi-sdk-2.1.2.17-linux64/lib/libboost_signals.so
sdk/bin/avoidcollision: /home/chen/Naoqi/naoqi-sdk-2.1.2.17-linux64/lib/librttools.so
sdk/bin/avoidcollision: /home/chen/Naoqi/naoqi-sdk-2.1.2.17-linux64/lib/libalvalue.so
sdk/bin/avoidcollision: /home/chen/Naoqi/naoqi-sdk-2.1.2.17-linux64/lib/libalerror.so
sdk/bin/avoidcollision: /home/chen/Naoqi/naoqi-sdk-2.1.2.17-linux64/lib/libqimessaging.so
sdk/bin/avoidcollision: /home/chen/Naoqi/naoqi-sdk-2.1.2.17-linux64/lib/libqitype.so
sdk/bin/avoidcollision: /home/chen/Naoqi/naoqi-sdk-2.1.2.17-linux64/lib/libqi.so
sdk/bin/avoidcollision: /home/chen/Naoqi/naoqi-sdk-2.1.2.17-linux64/lib/libboost_chrono.so
sdk/bin/avoidcollision: /home/chen/Naoqi/naoqi-sdk-2.1.2.17-linux64/lib/libboost_filesystem.so
sdk/bin/avoidcollision: /home/chen/Naoqi/naoqi-sdk-2.1.2.17-linux64/lib/libboost_program_options.so
sdk/bin/avoidcollision: /home/chen/Naoqi/naoqi-sdk-2.1.2.17-linux64/lib/libboost_regex.so
sdk/bin/avoidcollision: /usr/lib/x86_64-linux-gnu/libdl.so
sdk/bin/avoidcollision: /usr/lib/x86_64-linux-gnu/librt.so
sdk/bin/avoidcollision: /home/chen/Naoqi/naoqi-sdk-2.1.2.17-linux64/lib/libboost_date_time.so
sdk/bin/avoidcollision: /home/chen/Naoqi/naoqi-sdk-2.1.2.17-linux64/lib/libboost_system.so
sdk/bin/avoidcollision: /home/chen/Naoqi/naoqi-sdk-2.1.2.17-linux64/lib/libboost_locale.so
sdk/bin/avoidcollision: /home/chen/Naoqi/naoqi-sdk-2.1.2.17-linux64/lib/libboost_thread.so
sdk/bin/avoidcollision: /home/chen/Naoqi/naoqi-sdk-2.1.2.17-linux64/lib/libopencv_highgui.so
sdk/bin/avoidcollision: /home/chen/Naoqi/naoqi-sdk-2.1.2.17-linux64/lib/libopencv_imgproc.so
sdk/bin/avoidcollision: /home/chen/Naoqi/naoqi-sdk-2.1.2.17-linux64/lib/libopencv_core.so
sdk/bin/avoidcollision: /home/chen/Naoqi/naoqi-sdk-2.1.2.17-linux64/lib/libz.so
sdk/bin/avoidcollision: CMakeFiles/avoidcollision.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable sdk/bin/avoidcollision"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/avoidcollision.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/avoidcollision.dir/build: sdk/bin/avoidcollision
.PHONY : CMakeFiles/avoidcollision.dir/build

CMakeFiles/avoidcollision.dir/requires: CMakeFiles/avoidcollision.dir/avoidcollision.cpp.o.requires
CMakeFiles/avoidcollision.dir/requires: CMakeFiles/avoidcollision.dir/ycylib2.cpp.o.requires
CMakeFiles/avoidcollision.dir/requires: CMakeFiles/avoidcollision.dir/main.cpp.o.requires
.PHONY : CMakeFiles/avoidcollision.dir/requires

CMakeFiles/avoidcollision.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/avoidcollision.dir/cmake_clean.cmake
.PHONY : CMakeFiles/avoidcollision.dir/clean

CMakeFiles/avoidcollision.dir/depend:
	cd /home/chen/Naoqi/worktree/avoidcollision1/build-mytoolchain && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/chen/Naoqi/worktree/avoidcollision1 /home/chen/Naoqi/worktree/avoidcollision1 /home/chen/Naoqi/worktree/avoidcollision1/build-mytoolchain /home/chen/Naoqi/worktree/avoidcollision1/build-mytoolchain /home/chen/Naoqi/worktree/avoidcollision1/build-mytoolchain/CMakeFiles/avoidcollision.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/avoidcollision.dir/depend


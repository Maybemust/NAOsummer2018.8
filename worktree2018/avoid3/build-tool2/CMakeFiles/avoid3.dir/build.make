# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/liyang/worktree2018/avoid3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/liyang/worktree2018/avoid3/build-tool2

# Include any dependencies generated for this target.
include CMakeFiles/avoid3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/avoid3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/avoid3.dir/flags.make

CMakeFiles/avoid3.dir/avoidcollision.cpp.o: CMakeFiles/avoid3.dir/flags.make
CMakeFiles/avoid3.dir/avoidcollision.cpp.o: ../avoidcollision.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/liyang/worktree2018/avoid3/build-tool2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/avoid3.dir/avoidcollision.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/avoid3.dir/avoidcollision.cpp.o -c /home/liyang/worktree2018/avoid3/avoidcollision.cpp

CMakeFiles/avoid3.dir/avoidcollision.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/avoid3.dir/avoidcollision.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/liyang/worktree2018/avoid3/avoidcollision.cpp > CMakeFiles/avoid3.dir/avoidcollision.cpp.i

CMakeFiles/avoid3.dir/avoidcollision.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/avoid3.dir/avoidcollision.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/liyang/worktree2018/avoid3/avoidcollision.cpp -o CMakeFiles/avoid3.dir/avoidcollision.cpp.s

CMakeFiles/avoid3.dir/avoidcollision.cpp.o.requires:

.PHONY : CMakeFiles/avoid3.dir/avoidcollision.cpp.o.requires

CMakeFiles/avoid3.dir/avoidcollision.cpp.o.provides: CMakeFiles/avoid3.dir/avoidcollision.cpp.o.requires
	$(MAKE) -f CMakeFiles/avoid3.dir/build.make CMakeFiles/avoid3.dir/avoidcollision.cpp.o.provides.build
.PHONY : CMakeFiles/avoid3.dir/avoidcollision.cpp.o.provides

CMakeFiles/avoid3.dir/avoidcollision.cpp.o.provides.build: CMakeFiles/avoid3.dir/avoidcollision.cpp.o


CMakeFiles/avoid3.dir/ycylib2.cpp.o: CMakeFiles/avoid3.dir/flags.make
CMakeFiles/avoid3.dir/ycylib2.cpp.o: ../ycylib2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/liyang/worktree2018/avoid3/build-tool2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/avoid3.dir/ycylib2.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/avoid3.dir/ycylib2.cpp.o -c /home/liyang/worktree2018/avoid3/ycylib2.cpp

CMakeFiles/avoid3.dir/ycylib2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/avoid3.dir/ycylib2.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/liyang/worktree2018/avoid3/ycylib2.cpp > CMakeFiles/avoid3.dir/ycylib2.cpp.i

CMakeFiles/avoid3.dir/ycylib2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/avoid3.dir/ycylib2.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/liyang/worktree2018/avoid3/ycylib2.cpp -o CMakeFiles/avoid3.dir/ycylib2.cpp.s

CMakeFiles/avoid3.dir/ycylib2.cpp.o.requires:

.PHONY : CMakeFiles/avoid3.dir/ycylib2.cpp.o.requires

CMakeFiles/avoid3.dir/ycylib2.cpp.o.provides: CMakeFiles/avoid3.dir/ycylib2.cpp.o.requires
	$(MAKE) -f CMakeFiles/avoid3.dir/build.make CMakeFiles/avoid3.dir/ycylib2.cpp.o.provides.build
.PHONY : CMakeFiles/avoid3.dir/ycylib2.cpp.o.provides

CMakeFiles/avoid3.dir/ycylib2.cpp.o.provides.build: CMakeFiles/avoid3.dir/ycylib2.cpp.o


CMakeFiles/avoid3.dir/main.cpp.o: CMakeFiles/avoid3.dir/flags.make
CMakeFiles/avoid3.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/liyang/worktree2018/avoid3/build-tool2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/avoid3.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/avoid3.dir/main.cpp.o -c /home/liyang/worktree2018/avoid3/main.cpp

CMakeFiles/avoid3.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/avoid3.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/liyang/worktree2018/avoid3/main.cpp > CMakeFiles/avoid3.dir/main.cpp.i

CMakeFiles/avoid3.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/avoid3.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/liyang/worktree2018/avoid3/main.cpp -o CMakeFiles/avoid3.dir/main.cpp.s

CMakeFiles/avoid3.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/avoid3.dir/main.cpp.o.requires

CMakeFiles/avoid3.dir/main.cpp.o.provides: CMakeFiles/avoid3.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/avoid3.dir/build.make CMakeFiles/avoid3.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/avoid3.dir/main.cpp.o.provides

CMakeFiles/avoid3.dir/main.cpp.o.provides.build: CMakeFiles/avoid3.dir/main.cpp.o


CMakeFiles/avoid3.dir/wxzSVM.cpp.o: CMakeFiles/avoid3.dir/flags.make
CMakeFiles/avoid3.dir/wxzSVM.cpp.o: ../wxzSVM.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/liyang/worktree2018/avoid3/build-tool2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/avoid3.dir/wxzSVM.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/avoid3.dir/wxzSVM.cpp.o -c /home/liyang/worktree2018/avoid3/wxzSVM.cpp

CMakeFiles/avoid3.dir/wxzSVM.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/avoid3.dir/wxzSVM.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/liyang/worktree2018/avoid3/wxzSVM.cpp > CMakeFiles/avoid3.dir/wxzSVM.cpp.i

CMakeFiles/avoid3.dir/wxzSVM.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/avoid3.dir/wxzSVM.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/liyang/worktree2018/avoid3/wxzSVM.cpp -o CMakeFiles/avoid3.dir/wxzSVM.cpp.s

CMakeFiles/avoid3.dir/wxzSVM.cpp.o.requires:

.PHONY : CMakeFiles/avoid3.dir/wxzSVM.cpp.o.requires

CMakeFiles/avoid3.dir/wxzSVM.cpp.o.provides: CMakeFiles/avoid3.dir/wxzSVM.cpp.o.requires
	$(MAKE) -f CMakeFiles/avoid3.dir/build.make CMakeFiles/avoid3.dir/wxzSVM.cpp.o.provides.build
.PHONY : CMakeFiles/avoid3.dir/wxzSVM.cpp.o.provides

CMakeFiles/avoid3.dir/wxzSVM.cpp.o.provides.build: CMakeFiles/avoid3.dir/wxzSVM.cpp.o


# Object files for target avoid3
avoid3_OBJECTS = \
"CMakeFiles/avoid3.dir/avoidcollision.cpp.o" \
"CMakeFiles/avoid3.dir/ycylib2.cpp.o" \
"CMakeFiles/avoid3.dir/main.cpp.o" \
"CMakeFiles/avoid3.dir/wxzSVM.cpp.o"

# External object files for target avoid3
avoid3_EXTERNAL_OBJECTS =

sdk/bin/avoid3: CMakeFiles/avoid3.dir/avoidcollision.cpp.o
sdk/bin/avoid3: CMakeFiles/avoid3.dir/ycylib2.cpp.o
sdk/bin/avoid3: CMakeFiles/avoid3.dir/main.cpp.o
sdk/bin/avoid3: CMakeFiles/avoid3.dir/wxzSVM.cpp.o
sdk/bin/avoid3: CMakeFiles/avoid3.dir/build.make
sdk/bin/avoid3: /home/liyang/naoqi-sdk-2.1.4.13-linux64/lib/libalvision.so
sdk/bin/avoid3: /home/liyang/naoqi-sdk-2.1.4.13-linux64/lib/libalextractor.so
sdk/bin/avoid3: /home/liyang/naoqi-sdk-2.1.4.13-linux64/lib/libalthread.so
sdk/bin/avoid3: /home/liyang/naoqi-sdk-2.1.4.13-linux64/lib/libalproxies.so
sdk/bin/avoid3: /home/liyang/naoqi-sdk-2.1.4.13-linux64/lib/libalcommon.so
sdk/bin/avoid3: /home/liyang/naoqi-sdk-2.1.4.13-linux64/lib/libboost_signals.so
sdk/bin/avoid3: /home/liyang/naoqi-sdk-2.1.4.13-linux64/lib/librttools.so
sdk/bin/avoid3: /home/liyang/naoqi-sdk-2.1.4.13-linux64/lib/libalvalue.so
sdk/bin/avoid3: /home/liyang/naoqi-sdk-2.1.4.13-linux64/lib/libalerror.so
sdk/bin/avoid3: /home/liyang/naoqi-sdk-2.1.4.13-linux64/lib/libqimessaging.so
sdk/bin/avoid3: /home/liyang/naoqi-sdk-2.1.4.13-linux64/lib/libqitype.so
sdk/bin/avoid3: /home/liyang/naoqi-sdk-2.1.4.13-linux64/lib/libqi.so
sdk/bin/avoid3: /home/liyang/naoqi-sdk-2.1.4.13-linux64/lib/libboost_chrono.so
sdk/bin/avoid3: /home/liyang/naoqi-sdk-2.1.4.13-linux64/lib/libboost_filesystem.so
sdk/bin/avoid3: /home/liyang/naoqi-sdk-2.1.4.13-linux64/lib/libboost_program_options.so
sdk/bin/avoid3: /home/liyang/naoqi-sdk-2.1.4.13-linux64/lib/libboost_regex.so
sdk/bin/avoid3: /usr/lib/x86_64-linux-gnu/libdl.so
sdk/bin/avoid3: /usr/lib/x86_64-linux-gnu/librt.so
sdk/bin/avoid3: /home/liyang/naoqi-sdk-2.1.4.13-linux64/lib/libboost_date_time.so
sdk/bin/avoid3: /home/liyang/naoqi-sdk-2.1.4.13-linux64/lib/libboost_system.so
sdk/bin/avoid3: /home/liyang/naoqi-sdk-2.1.4.13-linux64/lib/libboost_locale.so
sdk/bin/avoid3: /home/liyang/naoqi-sdk-2.1.4.13-linux64/lib/libboost_thread.so
sdk/bin/avoid3: /home/liyang/naoqi-sdk-2.1.4.13-linux64/lib/libopencv_world.so
sdk/bin/avoid3: /home/liyang/naoqi-sdk-2.1.4.13-linux64/lib/libz.so
sdk/bin/avoid3: CMakeFiles/avoid3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/liyang/worktree2018/avoid3/build-tool2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable sdk/bin/avoid3"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/avoid3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/avoid3.dir/build: sdk/bin/avoid3

.PHONY : CMakeFiles/avoid3.dir/build

CMakeFiles/avoid3.dir/requires: CMakeFiles/avoid3.dir/avoidcollision.cpp.o.requires
CMakeFiles/avoid3.dir/requires: CMakeFiles/avoid3.dir/ycylib2.cpp.o.requires
CMakeFiles/avoid3.dir/requires: CMakeFiles/avoid3.dir/main.cpp.o.requires
CMakeFiles/avoid3.dir/requires: CMakeFiles/avoid3.dir/wxzSVM.cpp.o.requires

.PHONY : CMakeFiles/avoid3.dir/requires

CMakeFiles/avoid3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/avoid3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/avoid3.dir/clean

CMakeFiles/avoid3.dir/depend:
	cd /home/liyang/worktree2018/avoid3/build-tool2 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/liyang/worktree2018/avoid3 /home/liyang/worktree2018/avoid3 /home/liyang/worktree2018/avoid3/build-tool2 /home/liyang/worktree2018/avoid3/build-tool2 /home/liyang/worktree2018/avoid3/build-tool2/CMakeFiles/avoid3.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/avoid3.dir/depend


# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /mnt/c/Users/ethan/CLionProjects/22s-2341-EthanChou1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/ethan/CLionProjects/22s-2341-EthanChou1/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/pa01_sentiment.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/pa01_sentiment.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pa01_sentiment.dir/flags.make

CMakeFiles/pa01_sentiment.dir/main.cpp.o: CMakeFiles/pa01_sentiment.dir/flags.make
CMakeFiles/pa01_sentiment.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/ethan/CLionProjects/22s-2341-EthanChou1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/pa01_sentiment.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pa01_sentiment.dir/main.cpp.o -c /mnt/c/Users/ethan/CLionProjects/22s-2341-EthanChou1/main.cpp

CMakeFiles/pa01_sentiment.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pa01_sentiment.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/ethan/CLionProjects/22s-2341-EthanChou1/main.cpp > CMakeFiles/pa01_sentiment.dir/main.cpp.i

CMakeFiles/pa01_sentiment.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pa01_sentiment.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/ethan/CLionProjects/22s-2341-EthanChou1/main.cpp -o CMakeFiles/pa01_sentiment.dir/main.cpp.s

CMakeFiles/pa01_sentiment.dir/DSString.cpp.o: CMakeFiles/pa01_sentiment.dir/flags.make
CMakeFiles/pa01_sentiment.dir/DSString.cpp.o: ../DSString.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/ethan/CLionProjects/22s-2341-EthanChou1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/pa01_sentiment.dir/DSString.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pa01_sentiment.dir/DSString.cpp.o -c /mnt/c/Users/ethan/CLionProjects/22s-2341-EthanChou1/DSString.cpp

CMakeFiles/pa01_sentiment.dir/DSString.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pa01_sentiment.dir/DSString.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/ethan/CLionProjects/22s-2341-EthanChou1/DSString.cpp > CMakeFiles/pa01_sentiment.dir/DSString.cpp.i

CMakeFiles/pa01_sentiment.dir/DSString.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pa01_sentiment.dir/DSString.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/ethan/CLionProjects/22s-2341-EthanChou1/DSString.cpp -o CMakeFiles/pa01_sentiment.dir/DSString.cpp.s

CMakeFiles/pa01_sentiment.dir/tweetData.cpp.o: CMakeFiles/pa01_sentiment.dir/flags.make
CMakeFiles/pa01_sentiment.dir/tweetData.cpp.o: ../tweetData.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/ethan/CLionProjects/22s-2341-EthanChou1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/pa01_sentiment.dir/tweetData.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pa01_sentiment.dir/tweetData.cpp.o -c /mnt/c/Users/ethan/CLionProjects/22s-2341-EthanChou1/tweetData.cpp

CMakeFiles/pa01_sentiment.dir/tweetData.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pa01_sentiment.dir/tweetData.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/ethan/CLionProjects/22s-2341-EthanChou1/tweetData.cpp > CMakeFiles/pa01_sentiment.dir/tweetData.cpp.i

CMakeFiles/pa01_sentiment.dir/tweetData.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pa01_sentiment.dir/tweetData.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/ethan/CLionProjects/22s-2341-EthanChou1/tweetData.cpp -o CMakeFiles/pa01_sentiment.dir/tweetData.cpp.s

CMakeFiles/pa01_sentiment.dir/fileReader.cpp.o: CMakeFiles/pa01_sentiment.dir/flags.make
CMakeFiles/pa01_sentiment.dir/fileReader.cpp.o: ../fileReader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/ethan/CLionProjects/22s-2341-EthanChou1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/pa01_sentiment.dir/fileReader.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pa01_sentiment.dir/fileReader.cpp.o -c /mnt/c/Users/ethan/CLionProjects/22s-2341-EthanChou1/fileReader.cpp

CMakeFiles/pa01_sentiment.dir/fileReader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pa01_sentiment.dir/fileReader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/ethan/CLionProjects/22s-2341-EthanChou1/fileReader.cpp > CMakeFiles/pa01_sentiment.dir/fileReader.cpp.i

CMakeFiles/pa01_sentiment.dir/fileReader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pa01_sentiment.dir/fileReader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/ethan/CLionProjects/22s-2341-EthanChou1/fileReader.cpp -o CMakeFiles/pa01_sentiment.dir/fileReader.cpp.s

CMakeFiles/pa01_sentiment.dir/test.cpp.o: CMakeFiles/pa01_sentiment.dir/flags.make
CMakeFiles/pa01_sentiment.dir/test.cpp.o: ../test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/ethan/CLionProjects/22s-2341-EthanChou1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/pa01_sentiment.dir/test.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pa01_sentiment.dir/test.cpp.o -c /mnt/c/Users/ethan/CLionProjects/22s-2341-EthanChou1/test.cpp

CMakeFiles/pa01_sentiment.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pa01_sentiment.dir/test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/ethan/CLionProjects/22s-2341-EthanChou1/test.cpp > CMakeFiles/pa01_sentiment.dir/test.cpp.i

CMakeFiles/pa01_sentiment.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pa01_sentiment.dir/test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/ethan/CLionProjects/22s-2341-EthanChou1/test.cpp -o CMakeFiles/pa01_sentiment.dir/test.cpp.s

# Object files for target pa01_sentiment
pa01_sentiment_OBJECTS = \
"CMakeFiles/pa01_sentiment.dir/main.cpp.o" \
"CMakeFiles/pa01_sentiment.dir/DSString.cpp.o" \
"CMakeFiles/pa01_sentiment.dir/tweetData.cpp.o" \
"CMakeFiles/pa01_sentiment.dir/fileReader.cpp.o" \
"CMakeFiles/pa01_sentiment.dir/test.cpp.o"

# External object files for target pa01_sentiment
pa01_sentiment_EXTERNAL_OBJECTS =

pa01_sentiment: CMakeFiles/pa01_sentiment.dir/main.cpp.o
pa01_sentiment: CMakeFiles/pa01_sentiment.dir/DSString.cpp.o
pa01_sentiment: CMakeFiles/pa01_sentiment.dir/tweetData.cpp.o
pa01_sentiment: CMakeFiles/pa01_sentiment.dir/fileReader.cpp.o
pa01_sentiment: CMakeFiles/pa01_sentiment.dir/test.cpp.o
pa01_sentiment: CMakeFiles/pa01_sentiment.dir/build.make
pa01_sentiment: CMakeFiles/pa01_sentiment.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/ethan/CLionProjects/22s-2341-EthanChou1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable pa01_sentiment"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pa01_sentiment.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pa01_sentiment.dir/build: pa01_sentiment

.PHONY : CMakeFiles/pa01_sentiment.dir/build

CMakeFiles/pa01_sentiment.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pa01_sentiment.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pa01_sentiment.dir/clean

CMakeFiles/pa01_sentiment.dir/depend:
	cd /mnt/c/Users/ethan/CLionProjects/22s-2341-EthanChou1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/ethan/CLionProjects/22s-2341-EthanChou1 /mnt/c/Users/ethan/CLionProjects/22s-2341-EthanChou1 /mnt/c/Users/ethan/CLionProjects/22s-2341-EthanChou1/cmake-build-debug /mnt/c/Users/ethan/CLionProjects/22s-2341-EthanChou1/cmake-build-debug /mnt/c/Users/ethan/CLionProjects/22s-2341-EthanChou1/cmake-build-debug/CMakeFiles/pa01_sentiment.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/pa01_sentiment.dir/depend


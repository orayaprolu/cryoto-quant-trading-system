# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.27.7/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.27.7/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ojasr/Documents/Repos/cryoto-quant-trading-system

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ojasr/Documents/Repos/cryoto-quant-trading-system/build

# Include any dependencies generated for this target.
include CMakeFiles/data_loader.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/data_loader.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/data_loader.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/data_loader.dir/flags.make

CMakeFiles/data_loader.dir/backtesting_engine/data_loader.cpp.o: CMakeFiles/data_loader.dir/flags.make
CMakeFiles/data_loader.dir/backtesting_engine/data_loader.cpp.o: /Users/ojasr/Documents/Repos/cryoto-quant-trading-system/backtesting_engine/data_loader.cpp
CMakeFiles/data_loader.dir/backtesting_engine/data_loader.cpp.o: CMakeFiles/data_loader.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/ojasr/Documents/Repos/cryoto-quant-trading-system/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/data_loader.dir/backtesting_engine/data_loader.cpp.o"
	/opt/homebrew/bin/aarch64-apple-darwin24-g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/data_loader.dir/backtesting_engine/data_loader.cpp.o -MF CMakeFiles/data_loader.dir/backtesting_engine/data_loader.cpp.o.d -o CMakeFiles/data_loader.dir/backtesting_engine/data_loader.cpp.o -c /Users/ojasr/Documents/Repos/cryoto-quant-trading-system/backtesting_engine/data_loader.cpp

CMakeFiles/data_loader.dir/backtesting_engine/data_loader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/data_loader.dir/backtesting_engine/data_loader.cpp.i"
	/opt/homebrew/bin/aarch64-apple-darwin24-g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ojasr/Documents/Repos/cryoto-quant-trading-system/backtesting_engine/data_loader.cpp > CMakeFiles/data_loader.dir/backtesting_engine/data_loader.cpp.i

CMakeFiles/data_loader.dir/backtesting_engine/data_loader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/data_loader.dir/backtesting_engine/data_loader.cpp.s"
	/opt/homebrew/bin/aarch64-apple-darwin24-g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ojasr/Documents/Repos/cryoto-quant-trading-system/backtesting_engine/data_loader.cpp -o CMakeFiles/data_loader.dir/backtesting_engine/data_loader.cpp.s

CMakeFiles/data_loader.dir/backtesting_engine/CandleStream.cpp.o: CMakeFiles/data_loader.dir/flags.make
CMakeFiles/data_loader.dir/backtesting_engine/CandleStream.cpp.o: /Users/ojasr/Documents/Repos/cryoto-quant-trading-system/backtesting_engine/CandleStream.cpp
CMakeFiles/data_loader.dir/backtesting_engine/CandleStream.cpp.o: CMakeFiles/data_loader.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/ojasr/Documents/Repos/cryoto-quant-trading-system/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/data_loader.dir/backtesting_engine/CandleStream.cpp.o"
	/opt/homebrew/bin/aarch64-apple-darwin24-g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/data_loader.dir/backtesting_engine/CandleStream.cpp.o -MF CMakeFiles/data_loader.dir/backtesting_engine/CandleStream.cpp.o.d -o CMakeFiles/data_loader.dir/backtesting_engine/CandleStream.cpp.o -c /Users/ojasr/Documents/Repos/cryoto-quant-trading-system/backtesting_engine/CandleStream.cpp

CMakeFiles/data_loader.dir/backtesting_engine/CandleStream.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/data_loader.dir/backtesting_engine/CandleStream.cpp.i"
	/opt/homebrew/bin/aarch64-apple-darwin24-g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ojasr/Documents/Repos/cryoto-quant-trading-system/backtesting_engine/CandleStream.cpp > CMakeFiles/data_loader.dir/backtesting_engine/CandleStream.cpp.i

CMakeFiles/data_loader.dir/backtesting_engine/CandleStream.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/data_loader.dir/backtesting_engine/CandleStream.cpp.s"
	/opt/homebrew/bin/aarch64-apple-darwin24-g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ojasr/Documents/Repos/cryoto-quant-trading-system/backtesting_engine/CandleStream.cpp -o CMakeFiles/data_loader.dir/backtesting_engine/CandleStream.cpp.s

# Object files for target data_loader
data_loader_OBJECTS = \
"CMakeFiles/data_loader.dir/backtesting_engine/data_loader.cpp.o" \
"CMakeFiles/data_loader.dir/backtesting_engine/CandleStream.cpp.o"

# External object files for target data_loader
data_loader_EXTERNAL_OBJECTS =

data_loader: CMakeFiles/data_loader.dir/backtesting_engine/data_loader.cpp.o
data_loader: CMakeFiles/data_loader.dir/backtesting_engine/CandleStream.cpp.o
data_loader: CMakeFiles/data_loader.dir/build.make
data_loader: CMakeFiles/data_loader.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/ojasr/Documents/Repos/cryoto-quant-trading-system/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable data_loader"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/data_loader.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/data_loader.dir/build: data_loader
.PHONY : CMakeFiles/data_loader.dir/build

CMakeFiles/data_loader.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/data_loader.dir/cmake_clean.cmake
.PHONY : CMakeFiles/data_loader.dir/clean

CMakeFiles/data_loader.dir/depend:
	cd /Users/ojasr/Documents/Repos/cryoto-quant-trading-system/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ojasr/Documents/Repos/cryoto-quant-trading-system /Users/ojasr/Documents/Repos/cryoto-quant-trading-system /Users/ojasr/Documents/Repos/cryoto-quant-trading-system/build /Users/ojasr/Documents/Repos/cryoto-quant-trading-system/build /Users/ojasr/Documents/Repos/cryoto-quant-trading-system/build/CMakeFiles/data_loader.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/data_loader.dir/depend


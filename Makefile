# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_SOURCE_DIR = /home/code/Desktop/To-do-list

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/code/Desktop/To-do-list

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/code/Desktop/To-do-list/CMakeFiles /home/code/Desktop/To-do-list/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/code/Desktop/To-do-list/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named tasktest

# Build rule for target.
tasktest: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 tasktest
.PHONY : tasktest

# fast build rule for target.
tasktest/fast:
	$(MAKE) -f CMakeFiles/tasktest.dir/build.make CMakeFiles/tasktest.dir/build
.PHONY : tasktest/fast

EntryMD5.o: EntryMD5.c.o

.PHONY : EntryMD5.o

# target to build an object file
EntryMD5.c.o:
	$(MAKE) -f CMakeFiles/tasktest.dir/build.make CMakeFiles/tasktest.dir/EntryMD5.c.o
.PHONY : EntryMD5.c.o

EntryMD5.i: EntryMD5.c.i

.PHONY : EntryMD5.i

# target to preprocess a source file
EntryMD5.c.i:
	$(MAKE) -f CMakeFiles/tasktest.dir/build.make CMakeFiles/tasktest.dir/EntryMD5.c.i
.PHONY : EntryMD5.c.i

EntryMD5.s: EntryMD5.c.s

.PHONY : EntryMD5.s

# target to generate assembly for a file
EntryMD5.c.s:
	$(MAKE) -f CMakeFiles/tasktest.dir/build.make CMakeFiles/tasktest.dir/EntryMD5.c.s
.PHONY : EntryMD5.c.s

add_name2file.o: add_name2file.cpp.o

.PHONY : add_name2file.o

# target to build an object file
add_name2file.cpp.o:
	$(MAKE) -f CMakeFiles/tasktest.dir/build.make CMakeFiles/tasktest.dir/add_name2file.cpp.o
.PHONY : add_name2file.cpp.o

add_name2file.i: add_name2file.cpp.i

.PHONY : add_name2file.i

# target to preprocess a source file
add_name2file.cpp.i:
	$(MAKE) -f CMakeFiles/tasktest.dir/build.make CMakeFiles/tasktest.dir/add_name2file.cpp.i
.PHONY : add_name2file.cpp.i

add_name2file.s: add_name2file.cpp.s

.PHONY : add_name2file.s

# target to generate assembly for a file
add_name2file.cpp.s:
	$(MAKE) -f CMakeFiles/tasktest.dir/build.make CMakeFiles/tasktest.dir/add_name2file.cpp.s
.PHONY : add_name2file.cpp.s

deleteSpace.o: deleteSpace.cpp.o

.PHONY : deleteSpace.o

# target to build an object file
deleteSpace.cpp.o:
	$(MAKE) -f CMakeFiles/tasktest.dir/build.make CMakeFiles/tasktest.dir/deleteSpace.cpp.o
.PHONY : deleteSpace.cpp.o

deleteSpace.i: deleteSpace.cpp.i

.PHONY : deleteSpace.i

# target to preprocess a source file
deleteSpace.cpp.i:
	$(MAKE) -f CMakeFiles/tasktest.dir/build.make CMakeFiles/tasktest.dir/deleteSpace.cpp.i
.PHONY : deleteSpace.cpp.i

deleteSpace.s: deleteSpace.cpp.s

.PHONY : deleteSpace.s

# target to generate assembly for a file
deleteSpace.cpp.s:
	$(MAKE) -f CMakeFiles/tasktest.dir/build.make CMakeFiles/tasktest.dir/deleteSpace.cpp.s
.PHONY : deleteSpace.cpp.s

task.o: task.cpp.o

.PHONY : task.o

# target to build an object file
task.cpp.o:
	$(MAKE) -f CMakeFiles/tasktest.dir/build.make CMakeFiles/tasktest.dir/task.cpp.o
.PHONY : task.cpp.o

task.i: task.cpp.i

.PHONY : task.i

# target to preprocess a source file
task.cpp.i:
	$(MAKE) -f CMakeFiles/tasktest.dir/build.make CMakeFiles/tasktest.dir/task.cpp.i
.PHONY : task.cpp.i

task.s: task.cpp.s

.PHONY : task.s

# target to generate assembly for a file
task.cpp.s:
	$(MAKE) -f CMakeFiles/tasktest.dir/build.make CMakeFiles/tasktest.dir/task.cpp.s
.PHONY : task.cpp.s

test.o: test.cpp.o

.PHONY : test.o

# target to build an object file
test.cpp.o:
	$(MAKE) -f CMakeFiles/tasktest.dir/build.make CMakeFiles/tasktest.dir/test.cpp.o
.PHONY : test.cpp.o

test.i: test.cpp.i

.PHONY : test.i

# target to preprocess a source file
test.cpp.i:
	$(MAKE) -f CMakeFiles/tasktest.dir/build.make CMakeFiles/tasktest.dir/test.cpp.i
.PHONY : test.cpp.i

test.s: test.cpp.s

.PHONY : test.s

# target to generate assembly for a file
test.cpp.s:
	$(MAKE) -f CMakeFiles/tasktest.dir/build.make CMakeFiles/tasktest.dir/test.cpp.s
.PHONY : test.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... tasktest"
	@echo "... edit_cache"
	@echo "... EntryMD5.o"
	@echo "... EntryMD5.i"
	@echo "... EntryMD5.s"
	@echo "... add_name2file.o"
	@echo "... add_name2file.i"
	@echo "... add_name2file.s"
	@echo "... deleteSpace.o"
	@echo "... deleteSpace.i"
	@echo "... deleteSpace.s"
	@echo "... task.o"
	@echo "... task.i"
	@echo "... task.s"
	@echo "... test.o"
	@echo "... test.i"
	@echo "... test.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.29

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2024.2.0.1\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2024.2.0.1\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Asus\Documents\Programacion_Proyects\repoPROGRA

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Asus\Documents\Programacion_Proyects\repoPROGRA\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/proyecto2.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/proyecto2.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/proyecto2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/proyecto2.dir/flags.make

CMakeFiles/proyecto2.dir/main.cpp.obj: CMakeFiles/proyecto2.dir/flags.make
CMakeFiles/proyecto2.dir/main.cpp.obj: C:/Users/Asus/Documents/Programacion_Proyects/repoPROGRA/main.cpp
CMakeFiles/proyecto2.dir/main.cpp.obj: CMakeFiles/proyecto2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\Asus\Documents\Programacion_Proyects\repoPROGRA\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/proyecto2.dir/main.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/proyecto2.dir/main.cpp.obj -MF CMakeFiles\proyecto2.dir\main.cpp.obj.d -o CMakeFiles\proyecto2.dir\main.cpp.obj -c C:\Users\Asus\Documents\Programacion_Proyects\repoPROGRA\main.cpp

CMakeFiles/proyecto2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/proyecto2.dir/main.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Asus\Documents\Programacion_Proyects\repoPROGRA\main.cpp > CMakeFiles\proyecto2.dir\main.cpp.i

CMakeFiles/proyecto2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/proyecto2.dir/main.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Asus\Documents\Programacion_Proyects\repoPROGRA\main.cpp -o CMakeFiles\proyecto2.dir\main.cpp.s

CMakeFiles/proyecto2.dir/trie.cpp.obj: CMakeFiles/proyecto2.dir/flags.make
CMakeFiles/proyecto2.dir/trie.cpp.obj: C:/Users/Asus/Documents/Programacion_Proyects/repoPROGRA/trie.cpp
CMakeFiles/proyecto2.dir/trie.cpp.obj: CMakeFiles/proyecto2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\Asus\Documents\Programacion_Proyects\repoPROGRA\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/proyecto2.dir/trie.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/proyecto2.dir/trie.cpp.obj -MF CMakeFiles\proyecto2.dir\trie.cpp.obj.d -o CMakeFiles\proyecto2.dir\trie.cpp.obj -c C:\Users\Asus\Documents\Programacion_Proyects\repoPROGRA\trie.cpp

CMakeFiles/proyecto2.dir/trie.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/proyecto2.dir/trie.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Asus\Documents\Programacion_Proyects\repoPROGRA\trie.cpp > CMakeFiles\proyecto2.dir\trie.cpp.i

CMakeFiles/proyecto2.dir/trie.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/proyecto2.dir/trie.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Asus\Documents\Programacion_Proyects\repoPROGRA\trie.cpp -o CMakeFiles\proyecto2.dir\trie.cpp.s

# Object files for target proyecto2
proyecto2_OBJECTS = \
"CMakeFiles/proyecto2.dir/main.cpp.obj" \
"CMakeFiles/proyecto2.dir/trie.cpp.obj"

# External object files for target proyecto2
proyecto2_EXTERNAL_OBJECTS =

proyecto2.exe: CMakeFiles/proyecto2.dir/main.cpp.obj
proyecto2.exe: CMakeFiles/proyecto2.dir/trie.cpp.obj
proyecto2.exe: CMakeFiles/proyecto2.dir/build.make
proyecto2.exe: CMakeFiles/proyecto2.dir/linkLibs.rsp
proyecto2.exe: CMakeFiles/proyecto2.dir/objects1.rsp
proyecto2.exe: CMakeFiles/proyecto2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\Asus\Documents\Programacion_Proyects\repoPROGRA\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable proyecto2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\proyecto2.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/proyecto2.dir/build: proyecto2.exe
.PHONY : CMakeFiles/proyecto2.dir/build

CMakeFiles/proyecto2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\proyecto2.dir\cmake_clean.cmake
.PHONY : CMakeFiles/proyecto2.dir/clean

CMakeFiles/proyecto2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Asus\Documents\Programacion_Proyects\repoPROGRA C:\Users\Asus\Documents\Programacion_Proyects\repoPROGRA C:\Users\Asus\Documents\Programacion_Proyects\repoPROGRA\cmake-build-debug C:\Users\Asus\Documents\Programacion_Proyects\repoPROGRA\cmake-build-debug C:\Users\Asus\Documents\Programacion_Proyects\repoPROGRA\cmake-build-debug\CMakeFiles\proyecto2.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/proyecto2.dir/depend


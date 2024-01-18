# @file Makefile
# @brief This file is responsible for controlling the GNU Make command for easier building.
#
# @author Willow Ciesialka
# @date 2024-01-17

# Executable name
EXEC = falling_sand

# Compiler command
CC = g++

# Compiler flags
CFLAGS = -std=c++11 -Wall -Wextra -Wpedantic -Werror

# Linker flags
LFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

# Source/Build Directories
SDIR = ./src
BDIR = ./build

# Source Files
SOURCE_PATHS = $(shell find $(SDIR) -iname "*.cpp")

# Sources/Build Object paths
CLASSES = main sandrenderer/Pixel sandrenderer/Renderer
OBJECTS = $(addprefix $(BDIR)/,$(addsuffix .o, $(CLASSES)))

.PHONY: all run clean

# Build everything - default
all: $(EXEC).out

# Build and run
run: $(EXEC).out
	./$<

# Clean - Delete build files and executables
clean:
	rm -rf $(BDIR)
	rm -f $(EXEC).out

# Executable
$(EXEC).out: $(OBJECTS)
	$(CC) $^ -o $@ $(LFLAGS)

# Build files
$(BDIR)/%.o: $(SDIR)/%.cpp
	@# Make the build directory if it doesn't exist
	@if ! [ -d $(@D) ]; then mkdir -p $(@D); fi
	$(CC) -c $^ -o $@ $(CFLAGS) 
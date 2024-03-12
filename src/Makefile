# Define the C++ compiler to use
CXX = g++

# Define any compile-time flags
CXXFLAGS = -std=c++17 -Wall -Wextra -g $(shell sdl2-config --cflags)

# Define library paths in addition to /usr/lib and the libraries to link against
LFLAGS = $(shell sdl2-config --libs) -lSDL2_image -lSDL2_mixer -lSDL2_ttf

# Define output directory
OUTPUT := /home/default/private_place/src/output

# Define source directory
SRC_DIR := /home/default/private_place/src

# Define include directory
INCLUDE_DIR := /home/default/private_place/src/include

# Define lib directory
LIB_DIR := /home/default/private_place/src/lib

# OS-specific part
ifeq ($(OS),Windows_NT)
    RM := del /q /f
    MD := mkdir
else
    RM = rm -f
    MD := mkdir -p
endif

# Adding paths for includes and libraries
INCLUDES := -I$(INCLUDE_DIR)
LIBS := -L$(LIB_DIR)

# Define the C++ source files
SOURCES := $(wildcard $(SRC_DIR)/*.cpp)

# Define the C++ object files 
OBJECTS := $(SOURCES:$(SRC_DIR)/%.cpp=$(OUTPUT)/%.o)

# Define the dependency output files
DEPS := $(OBJECTS:.o=.d)

# Define the executable file
EXECUTABLE := $(OUTPUT)/main

# The default target
all: $(EXECUTABLE)
    @echo Executing 'all' complete!

# Ensure the output directory exists
$(OUTPUT):
    $(MD) $(OUTPUT)

# Rule for linking the final executable
$(EXECUTABLE): $(OBJECTS)
    $(CXX) $(CXXFLAGS) -o $@ $(OBJECTS) $(LFLAGS) $(LIBS)

# Rule for object file generation
$(OUTPUT)/%.o: $(SRC_DIR)/%.cpp
    $(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@ -MMD -MP

.PHONY: clean
clean:
    $(RM) -r $(OUTPUT)/* $(OUTPUT)/*.d $(EXECUTABLE)
    @echo Cleanup complete!
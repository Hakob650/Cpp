# Compiler and flags
CXX := g++
CXXFLAGS := -std=c++17 -Iinclude -Wall -Wextra -pedantic

# Project files
SRC_DIR := src
INC_DIR := include
OBJ_DIR := obj
BIN := weather_system

# Source files
SRCS := $(wildcard $(SRC_DIR)/*.cpp) main.cpp
OBJS := $(SRCS:.cpp=.o)

# Rule to convert .cpp -> obj/filename.o
OBJ_FILES := $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SRCS))

# Default target
all: $(BIN)

# Link objects into binary
$(BIN): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile source files into object files
$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build artifacts
clean:
	rm -rf $(OBJ_DIR) $(BIN)

# Optional: run program
run: all
	./$(BIN)

.PHONY: all clean run

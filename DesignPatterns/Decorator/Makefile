# Compiler and flags
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Iinclude

# Directories
SRC_DIR := src
INC_DIR := include
OBJ_DIR := obj

# Output names
TARGET := message_transformer
TEST_BIN := test_runner

# Source and object files
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

# Main file
MAIN := main.cpp

# Default build target
all: $(TARGET)

# App binary
$(TARGET): $(OBJS) $(MAIN)
	$(CXX) $(CXXFLAGS) -o $@ $(MAIN) $(OBJS)

# Object files from src/
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Object dir creation
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Clean all builds
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

# Run program
run: all
	./$(TARGET)

.PHONY: all clean run test

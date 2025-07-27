# Compiler and flags
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Iinclude

# Output binary name
TARGET := bridge_remote_control

# Directories
SRC_DIR := src
OBJ_DIR := obj

# Source and object files
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

# Main application entry
MAIN := main.cpp

# Default target
all: $(TARGET)

# Link the main app
$(TARGET): $(OBJS) $(MAIN)
	$(CXX) $(CXXFLAGS) $(MAIN) $(OBJS) -o $@

# Compile .cpp to .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create obj directory
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Clean build artifacts
clean:
	rm -rf $(OBJ_DIR) $(TARGET)
# Run main program
run: all
	./$(TARGET)

.PHONY: all clean run test

# Compiler and flags
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Iinclude

# Output binary name
TARGET := bridge_remote_control

# Directories
SRC_DIR := src
OBJ_DIR := obj
TEST_DIR := tests

# Source and object files
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

# Main application entry
MAIN := main.cpp

# --- TEST CONFIG ---
TEST_SRC := $(wildcard $(TEST_DIR)/*.cpp)
TEST_BIN := test_runner
GTEST_FLAGS := /usr/lib/libgtest.a /usr/lib/libgtest_main.a -pthread
TEST_OBJS := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))  # reuse core obj files

# Default target
all: $(TARGET)

# Link the main app
$(TARGET): $(OBJS) $(MAIN)
	$(CXX) $(CXXFLAGS) $(MAIN) $(OBJS) -o $@

# Compile .cpp to .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile test files separately (optional)
$(OBJ_DIR)/%.o: $(TEST_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create obj directory
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# --- TEST TARGET ---
test: $(TEST_BIN)
	./$(TEST_BIN)

# Link test binary
$(TEST_BIN): $(TEST_SRC) $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(GTEST_FLAGS)

# Clean build artifacts
clean:
	rm -rf $(OBJ_DIR) $(TARGET) $(TEST_BIN)

# Run main program
run: all
	./$(TARGET)

.PHONY: all clean run test

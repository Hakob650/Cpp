# Compiler and flags
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Iinclude

# Directories
SRC_DIR := src
INC_DIR := include
OBJ_DIR := obj
TEST_DIR := tests

# Output names
TARGET := message_transformer
TEST_BIN := test_runner

# Source and object files
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

# Main file
MAIN := main.cpp

# GTest config (using static libraries)
GTEST_FLAGS := /usr/lib/libgtest.a /usr/lib/libgtest_main.a -pthread
TEST_SRC := $(wildcard $(TEST_DIR)/*.cpp)

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

# ---------- Google Test ----------
test: $(TEST_BIN)
	./$(TEST_BIN)

$(TEST_BIN): $(TEST_SRC) $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(GTEST_FLAGS)

# Clean all builds
clean:
	rm -rf $(OBJ_DIR) $(TARGET) $(TEST_BIN)

# Run program
run: all
	./$(TARGET)

.PHONY: all clean run test

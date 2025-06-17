# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude -I/usr/local/include

# Linker flags - add pthread and gtest/gmock libs
LDFLAGS = -L/usr/local/lib -lgtest -lgtest_main -lgmock -lgmock_main -pthread

# Source files
SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:.cpp=.o)

# Test source and object
TEST_SRC = googletests/taskmanager_test.cpp
TEST_OBJ = $(TEST_SRC:.cpp=.o)

# Target executable for tests
TEST_EXEC = test_exec

.PHONY: all clean

all: $(TEST_EXEC)

# Compile source files to object files
src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile test file
googletests/%.o: googletests/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Link test executable
$(TEST_EXEC): $(OBJ) $(TEST_OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

clean:
	rm -f src/*.o googletests/*.o $(TEST_EXEC)

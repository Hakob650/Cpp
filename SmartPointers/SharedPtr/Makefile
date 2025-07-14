# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -g

# Source and object files
SRC_MAIN = main.cpp my_shared_ptr_exceptions.cpp
OBJ_MAIN = $(SRC_MAIN:.cpp=.o)

SRC_TEST = test_shared_ptr.cpp my_shared_ptr_exceptions.cpp
OBJ_TEST = $(SRC_TEST:.cpp=.o)

# Executables
MAIN_EXEC = main
TEST_EXEC = test_shared_ptr

# Header dependencies
HEADERS = control_block.hpp my_shared_ptr.hpp my_shared_ptr_exceptions.hpp

# Default target
all: $(MAIN_EXEC) $(TEST_EXEC)

# Build main executable
$(MAIN_EXEC): $(OBJ_MAIN)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Build test executable
$(TEST_EXEC): $(OBJ_TEST)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile .cpp to .o
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -f *.o $(MAIN_EXEC) $(TEST_EXEC)

.PHONY: all clean

# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

# Targets
TARGET = auto_ptr_demo
TEST_TARGET = test_auto_ptr

# Source files
SRCS = main.cpp my_auto_ptr.cpp my_auto_ptr_exceptions.cpp
OBJS = $(SRCS:.cpp=.o)

# Test sources (add your test file here)
TEST_SRCS = test_auto_ptr.cpp my_auto_ptr.cpp my_auto_ptr_exceptions.cpp
TEST_OBJS = $(TEST_SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(TEST_TARGET): $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET) $(TEST_OBJS) $(TEST_TARGET)

rebuild: clean all


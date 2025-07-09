CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

# Main application
TARGET = unique_ptr_demo
MAIN_SRCS = main.cpp my_unique_ptr.cpp my_unique_ptr_exceptions.cpp
MAIN_OBJS = $(MAIN_SRCS:.cpp=.o)

# Test build
TEST_TARGET = run_tests
TEST_SRCS = test_unique_ptr.cpp my_unique_ptr.cpp my_unique_ptr_exceptions.cpp
TEST_OBJS = $(TEST_SRCS:.cpp=.o)
TEST_LIBS = -lgtest -lgtest_main -pthread

all: $(TARGET)

$(TARGET): $(MAIN_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(TEST_TARGET): $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(TEST_LIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

test: $(TEST_TARGET)
	./$(TEST_TARGET)

clean:
	rm -f $(MAIN_OBJS) $(TEST_OBJS) $(TARGET) $(TEST_TARGET)

rebuild: clean all


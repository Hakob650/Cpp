CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -I/path/to/gtest/include

# You need to link with gtest and pthread
LDFLAGS = -L/path/to/gtest/lib -lgtest -lgtest_main -pthread

TARGET = shared_ptr_demo
TEST_TARGET = test_shared_ptr

SRCS = main.cpp my_shared_ptr.cpp my_shared_ptr_exceptions.cpp
TEST_SRCS = test_shared_ptr.cpp my_shared_ptr.cpp my_shared_ptr_exceptions.cpp

OBJS = $(SRCS:.cpp=.o)
TEST_OBJS = $(TEST_SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(TEST_TARGET): $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET) $(TEST_OBJS) $(TEST_TARGET)

rebuild: clean all

CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

TARGET = unique_ptr_demo
SRCS = main.cpp my_unique_ptr.cpp my_unique_ptr_exceptions.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

rebuild: clean all

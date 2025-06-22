CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic
INCLUDE = -Iinclude

TARGET = resturant_app
TEST_TARGET = test_resturant

SRCS = main.cpp src/Resturant.cpp src/Menu.cpp src/Dishes.cpp src/Orders.cpp src/Customers.cpp src/Appetizers.cpp
HEADERS = include/Resturant.hpp include/Menu.hpp include/Dishes.hpp include/Orders.hpp include/Customers.hpp include/Appetizers.hpp

OBJS = main.o Resturant.o Menu.o Dishes.o Orders.o Customers.o Appetizers.o

TEST_SRCS = Test/test_resturantSystem.cpp src/Resturant.cpp src/Menu.cpp src/Dishes.cpp src/Orders.cpp src/Customers.cpp src/Appetizers.cpp
TEST_OBJS = test_resturantSystem.o Resturant.o Menu.o Dishes.o Orders.o Customers.o Appetizers.o

.PHONY: all clean test

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $@ $(OBJS)

%.o: src/%.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

main.o: main.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c main.cpp -o main.o

# Test build

test: $(TEST_TARGET)
	./$(TEST_TARGET)

$(TEST_TARGET): $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $@ $(TEST_OBJS) -lgtest -lgtest_main -pthread

test_resturantSystem.o: Test/test_resturantSystem.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c Test/test_resturantSystem.cpp -o test_resturantSystem.o

clean:
	rm -f $(OBJS) $(TEST_OBJS) $(TARGET) $(TEST_TARGET)

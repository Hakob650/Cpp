CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic

TARGET = resturant_app

SRCS = main.cpp src/resturant.cpp src/menu.cpp src/dish.cpp src/order.cpp src/customer.cpp src/dishtypes.cpp
HEADERS = include/resturant.hpp include/menu.hpp include/dish.hpp include/order.hpp include/customer.hpp include/dishtypes.hpp

OBJS = main.o resturant.o menu.o dish.o order.o customer.o dishtypes.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

%.o: src/%.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -Iinclude -c $< -o $@

main.o: main.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -Iinclude -c main.cpp -o main.o

clean:
	rm -f $(OBJS) $(TARGET)

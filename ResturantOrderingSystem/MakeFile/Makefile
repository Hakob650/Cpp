CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic

TARGET = restaurant_app

SRCS = main.cpp restaurant.cpp menu.cpp dish.cpp order.cpp customer.cpp dishtypes.cpp
HEADERS = restaurant.hpp menu.hpp dish.hpp order.hpp customer.hpp dishtypes.hpp

OBJS = main.o restaurant.o menu.o dish.o order.o customer.o dishtypes.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

main.o: main.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

restaurant.o: restaurant.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c restaurant.cpp -o restaurant.o

menu.o: menu.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c menu.cpp -o menu.o

dish.o: dish.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c dish.cpp -o dish.o

order.o: order.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c order.cpp -o order.o

customer.o: customer.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c customer.cpp -o customer.o

dishtypes.o: dishtypes.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c dishtypes.cpp -o dishtypes.o

clean:
	rm -f $(OBJS) $(TARGET)



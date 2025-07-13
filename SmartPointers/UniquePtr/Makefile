CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -pthread -I/usr/include/gtest
LDFLAGS := -lgtest -lgtest_main -pthread

# Sources (only .cpp files)
SRC_LIB := my_unique_ptr_exceptions.cpp
SRC_MAIN := main.cpp $(SRC_LIB)
SRC_TEST := test_unique_ptr.cpp $(SRC_LIB)

# Objects
OBJ_MAIN := $(SRC_MAIN:.cpp=.o)
OBJ_TEST := $(SRC_TEST:.cpp=.o)

# Targets
TARGET_MAIN := my_unique_ptr_demo
TARGET_TEST := my_unique_ptr_tests

.PHONY: all clean run_demo run_tests

all: $(TARGET_MAIN) $(TARGET_TEST)

$(TARGET_MAIN): $(OBJ_MAIN)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(TARGET_TEST): $(OBJ_TEST)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_MAIN) $(OBJ_TEST) $(TARGET_MAIN) $(TARGET_TEST)

run_demo: $(TARGET_MAIN)
	./$(TARGET_MAIN)

run_tests: $(TARGET_TEST)
	./$(TARGET_TEST)


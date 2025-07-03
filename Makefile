CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude
GTEST_LIBS = -lgtest -lgtest_main -pthread

SRC = Src/Base.cpp Src/Derived.cpp Src/TypeInfo.cpp
MAIN = Main/main.cpp
TEST_SRC = Tests/test_VTable.cpp

OBJ = $(SRC:.cpp=.o)
MAIN_OBJ = $(MAIN:.cpp=.o)
TEST_OBJ = $(TEST_SRC:.cpp=.o)

TARGET = program
TEST_TARGET = test

# Default build
all: $(TARGET)

# Build main program
$(TARGET): $(OBJ) $(MAIN_OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Build test executable
$(TEST_TARGET): $(OBJ) $(TEST_OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(GTEST_LIBS)

# Compile rules
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(OBJ) $(MAIN_OBJ) $(TEST_OBJ) $(TARGET) $(TEST_TARGET)

# Run the main program
run: $(TARGET)
	./$(TARGET)

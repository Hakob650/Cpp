CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++17 -Iinclude -Ibank_system_exceptions

SRC_DIR := src
MAIN_DIR := main
EXC_DIR := bank_system_exceptions
OBJ_DIR := obj
BIN := bank_app

SOURCES := \
    $(MAIN_DIR)/main.cpp \
    $(SRC_DIR)/BankAccount.cpp \
    $(SRC_DIR)/BankSystem.cpp \
    $(EXC_DIR)/exceptions.cpp

OBJECTS := $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(notdir $(SOURCES)))

all: $(BIN)

$(BIN): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(MAIN_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(EXC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(BIN)

.PHONY: all clean


CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++17 -Iinclude -Ibank_system_exceptions

SRC_DIR := src
EXC_DIR := bank_system_exceptions
TEST_DIR := googletests
OBJ_DIR := obj
BIN := bank_app
TEST_BIN := bank_tests

SOURCES := \
    main.cpp \
    $(SRC_DIR)/BankAccount.cpp \
    $(SRC_DIR)/BankSystem.cpp \
    $(EXC_DIR)/exceptions.cpp

TEST_SOURCES := \
    $(TEST_DIR)/test_bank_management_system.cpp \
    $(SRC_DIR)/BankAccount.cpp \
    $(SRC_DIR)/BankSystem.cpp \
    $(EXC_DIR)/exceptions.cpp

OBJECTS := $(addprefix $(OBJ_DIR)/, $(notdir $(SOURCES:.cpp=.o)))
TEST_OBJECTS := $(addprefix $(OBJ_DIR)/, $(notdir $(TEST_SOURCES:.cpp=.o)))

# Fix paths for objects that need to be in subdirectories
OBJ_DIRS := $(OBJ_DIR) $(OBJ_DIR)/$(SRC_DIR) $(OBJ_DIR)/$(EXC_DIR) $(OBJ_DIR)/$(TEST_DIR)

all: $(BIN)

$(BIN): $(OBJ_DIRS) $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $(addprefix $(OBJ_DIR)/, $(notdir $(OBJECTS)))

$(TEST_BIN): $(OBJ_DIRS) $(TEST_OBJECTS)
	$(CXX) $(CXXFLAGS) -lgtest -lgtest_main -pthread -o $@ $(addprefix $(OBJ_DIR)/, $(notdir $(TEST_OBJECTS)))

$(OBJ_DIRS):
	mkdir -p $@

# Pattern rule for all .o files
$(OBJ_DIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(EXC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(TEST_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(BIN) $(TEST_BIN)

.PHONY: all clean

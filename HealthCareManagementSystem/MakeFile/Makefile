CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic -I.

SRC = main.cpp src/Doctor.cpp src/enums.cpp src/MedicalHistory.cpp src/Patient.cpp src/Person.cpp src/SystemManager.cpp
OBJ = $(SRC::.cpp=.o)

TARGET = EHealthCareSystem

all: $(TARGET)

$(TARGET) : $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)


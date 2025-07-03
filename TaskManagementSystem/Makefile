CXX = g++
CXXFLAGS = -pipe -O2 -std=gnu++1z -Wall -Wextra -D_REENTRANT -fPIC
INCPATH = -I. -I../include
LIBS =
LFLAGS = -Wl,-O1

SOURCES = main.cpp mainwindow.cpp task.cpp taskmanager.cpp user.cpp
OBJECTS = $(SOURCES:.cpp=.o)
TARGET = TaskManagementSystem

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(LFLAGS) -o $@ $(OBJECTS) $(LIBS)

%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<

clean:
	rm -f $(OBJECTS) $(TARGET)


CXX = g++
CXXFLAGS = -std=c++17 -Wall -c
LXXFLAGS = -std=c++17
OBJECTS = main.o box.o truckload.o package.o
TARGET = main


$(TARGET): $(OBJECTS)
	$(CXX) $(LXXFLAGS) $(OBJECTS) -o $(TARGET)
main.o: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp
box.o: box.h box.cpp
	$(CXX) $(CXXFLAGS) box.cpp
truckload.o: truckload.h truckload.cpp
	$(CXX) $(CXXFLAGS) truckload.cpp
package.o: package.h package.cpp
	$(CXX) $(CXXFLAGS) package.cpp
clean:
	rm -f $(TARGET) $(OBJECTS)

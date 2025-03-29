CXX = g++
CXXFLAGS = -Wall -g -std=c++17


SRC = $(wildcard *.cpp)  
OBJ = $(SRC:.cpp=.o)     
TARGET = my_program      

all: $(TARGET)


$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)


%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)


run: $(TARGET)
	./$(TARGET)

SRC = $(shell find src/ -name *.cpp)
OBJ = $(patsubst %.cpp,%.o,$(SRC))
CC = g++
FLAGS = -g -O0 
LIBS = -lsfml-window -lsfml-system -lsfml-graphics
TARGET = bin/main.bin

all: $(OBJ)
	$(CC) $(FLAGS) $^ -o $(TARGET) $(LIBS)

%.o: %.cpp
	$(CC) -c $(FLAGS) $^ -o $@

run_main: all
	$(TARGET)

clean:
	rm -rf $(TARGET) $(OBJ)
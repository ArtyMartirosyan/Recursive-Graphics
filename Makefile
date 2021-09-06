CC = g++
CFLAGS = -std=c++11 -c -g -Og -Wall -Werror -pedantic  
OBJ = Triangle.o TFractal.o
DEPS = Triangle.cpp Triangle.h TFractal.cpp
LIBS = -lsfml-graphics -lsfml-window -lsfml-system
EXE = TFractal

all: $(OBJ)
	$(CC) $(OBJ) -o $(EXE) $(LIBS)

%.o: %.cpp %.h
	$(CC) $(CFLAGS)  -c $< -o $@

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm $(OBJ) $(EXE)

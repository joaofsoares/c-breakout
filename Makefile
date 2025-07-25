CC = gcc
SOURCE = ./src/main.c
INCLUDES = -I/opt/homebrew/Cellar/raylib/5.5/include -L/opt/homebrew/Cellar/raylib/5.5/lib
LIBS = -lraylib

all: 
	$(CC) $(SOURCE) -o ./out/breakout $(INCLUDES) $(LIBS)

clean:
	rm ./out/breakout

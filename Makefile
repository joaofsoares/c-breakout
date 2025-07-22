CC = gcc
SOURCE = main.c
INCLUDES = -I/opt/homebrew/Cellar/raylib/5.5/include -L/opt/homebrew/Cellar/raylib/5.5/lib
LIBS = -lraylib

all: 
	$(CC) $(SOURCE) -o breakout $(INCLUDES) $(LIBS)

clean:
	rm breakout

SRC=sdlanim.c
BIN=sdlanim

$(BIN): $(SRC)
	gcc -Wall -g -std=c99 $(SRC) `sdl-config --cflags --libs` -o $(BIN)

clean:
	rm -f $(BIN)

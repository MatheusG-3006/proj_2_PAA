CC = gcc

CFLAGS = -Wall -Wextra

EXEC = jogo

SRC = jogo_aventura.c arquivo.c merge.c guloso.c

all:
	$(CC) $(SRC) -o $(EXEC) $(CFLAGS)

run:
	./$(EXEC) entrada.txt saida.txt

clean:
	rm -f $(EXEC)
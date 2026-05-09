CC = gcc
CFLAGS = -Wall -I.
TARGET = meu_programa
OBJS = main.o utils.o

# Regra padrão
all: $(TARGET)

# Vincula os objetos para criar o executável
$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

# Regra genérica para compilar .c em .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpeza de arquivos gerados
.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET)   
# Variáveis
CC = gcc                    # Compilador C
CFLAGS = -Wall -g            # Flags de compilação
TARGET = lista              # Nome do executável
OBJ = lista.o               # Arquivos objetos

# Regra principal para compilar o programa
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

# Regra para compilar o arquivo de origem
lista.o: lista.c
	$(CC) $(CFLAGS) -c lista.c

# Regra para limpar os arquivos gerados
clean:
	rm -f $(OBJ) $(TARGET)

# Regra para executar o programa
run: $(TARGET)
	./$(TARGET)

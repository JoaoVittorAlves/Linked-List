
CC = gcc                    
CFLAGS = -Wall -g            
TARGET = lista              
OBJ = lista.o               


$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)


lista.o: lista.c
	$(CC) $(CFLAGS) -c lista.c


clean:
	rm -f $(OBJ) $(TARGET)


run: $(TARGET)
	./$(TARGET)

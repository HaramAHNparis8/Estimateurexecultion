CC = gcc -fsanitize=address -g
CFLAGS = -Wall
SRC = exercices5.c sort.c utils.c
TARGET = exercices5

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)

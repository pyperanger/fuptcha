CC=gcc
CFLAGS=-llept -ltesseract
TARGET=tessefuzz
tessefuzz : tessefuzz.c 
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c
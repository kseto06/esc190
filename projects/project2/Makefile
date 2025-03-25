# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -lm

# Files
SRC = seamcarving.c c_img.c
HEADERS = seamcarving.h c_img.h stb_image.h
TARGET = seamcarving

# Default target
all: $(TARGET)

$(TARGET): $(SRC) $(HEADERS)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

# Clean up build files
clean:
	rm -f $(TARGET)

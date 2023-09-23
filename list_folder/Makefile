# Makefile for list implementation and test file.

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99

# Source files
SRC_FILES = list.c main.c

# Executable
EXECUTABLE = list

# Default target: build the executable
all: $(EXECUTABLE)

# Rule to compile the executable
$(EXECUTABLE): $(SRC_FILES)
	$(CC) $(CFLAGS) $^ -o $@

# Clean target: remove the executable
clean:
	rm -f $(EXECUTABLE)

.PHONY: all clean

# Variables
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = ../
TEST_DIR = tests
SRC_FILES = $(wildcard $(SRC_DIR)/ft_*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, %.o, $(SRC_FILES))
TEST_FILES = $(patsubst $(SRC_DIR)/ft_%.c, $(TEST_DIR)/test_ft_%.c, $(SRC_FILES))
EXE_FILES = $(patsubst $(TEST_DIR)/%.c, %, $(TEST_FILES))

# Default target
all: $(EXE_FILES)

# Compile source files into object files
%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Compile test files into executables
%: $(TEST_DIR)/%.c %.o
	$(CC) $(CFLAGS) $^ -o $@

# Run each executable
run: $(EXE_FILES)
	for exe in $^; do ./$$exe; done

# Clean executables and objects
clean:
	rm -f $(EXE_FILES) $(OBJ_FILES)

.PHONY: all run clean
# Compiler to use
CC = gcc
# Compiler flags, e.g., -I for include path
CFLAGS = -I../ -Wall -Wextra -Werror

# Collect all ft_*.c files from parent directory
SRC = $(wildcard ../ft_*.c)
# Convert ft_*.c filenames to executable names based on the pattern
EXE = $(SRC:../ft_%.c=test_ft_%)

.PHONY: all clean test

# Default target
all: test clean

# Rule to build and run tests
test: $(EXE)
$(EXE): test_ft_% : ../ft_%.c test_ft_%.c
	@$(CC) $(CFLAGS) $^ -o $@
	./$@

# Clean up executables
clean:
	@rm -f $(EXE)
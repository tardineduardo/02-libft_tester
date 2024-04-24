# Compiler to use
CC = gcc

# Compiler flags, e.g., -I for include path
CFLAGS = -I../ -Wall -Wextra -Werror

# Collect all test files from tests folder
SRC_TEST = $(wildcard tests/test_ft_*.c)

# Source files to be tested
SRC_LIBFT = $(wildcard ../ft_*.c)

# Convert test_ft_*.c filenames to executable names based on the pattern
EXE = $(SRC_TEST:tests/test_ft_%.c=test_ft_%)

.PHONY: all clean test

# Default target
all: test clean

# Rule to build and run tests
test: $(EXE)
$(EXE): $(SRC_TEST) $(SRC_LIBFT)
	@$(CC) $(CFLAGS) -I../ $(SRC_TEST) $(SRC_LIBFT) -o $@
	./$@

# Clean up executables
clean:
	@rm -f $(EXE)
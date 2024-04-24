# Makefile inside the test_libft directory

# Compiler to use
CC = gcc
# Compiler flags, e.g., -I for include path
CFLAGS = -I../ -Wall -Wextra -Werror

# Collect all ft_*.c files from parent directory
SRC = $(wildcard ../ft_*.c)

.PHONY: all clean part1 part2 bonus

# Default target
all: part1 part2 bonus clean

# Rule to build and run tests for part1
part1: $(SRC:../ft_%.c=part1/test_ft_%)
	@echo "Running part1 tests..."
$(SRC:../ft_%.c=part1/test_ft_%): part1/test_ft_% : ../ft_%.c part1/test_ft_%.c
	@$(CC) $(CFLAGS) $^ -o $@
	./$@

# Rule to build and run tests for part2
part2: $(SRC:../ft_%.c=part2/test_ft_%)
	@echo "Running part2 tests..."
$(SRC:../ft_%.c=part2/test_ft_%): part2/test_ft_% : ../ft_%.c part2/test_ft_%.c
	@$(CC) $(CFLAGS) $^ -o $@
	./$@

# Rule to build and run tests for bonus
bonus: $(SRC:../ft_%.c=bonus/test_ft_%)
	@echo "Running bonus tests..."
$(SRC:../ft_%.c=bonus/test_ft_%): bonus/test_ft_% : ../ft_%.c bonus/test_ft_%.c
	@$(CC) $(CFLAGS) $^ -o $@
	./$@

# Clean up executables
clean:
	@rm -f part1/test_ft_* part2/test_ft_* bonus/test_ft_*
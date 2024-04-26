C = gcc
CFLAGS = -I../ -Wall -Wextra -Werror
RED = \033[0;31m
NC = \033[0m

# Collect all ft_*.c files from parent directory
SRC = $(wildcard ../ft_*.c)

# Convert ft_*.c filenames to executable names based on the pattern
EXE = $(SRC:../ft_%.c=test_ft_%)

.PHONY: all clean test

# Default target
all: test clean

# Rule to build and run tests
test: $(EXE)
$(EXE): test_ft_% : ../ft_%.c ./tests/test_ft_%.c
	@if $(CC) $(CFLAGS) $^ -o $@ 2> /dev/null; then \
		echo "$^"; \
		./$@ || true; \
	else \
		echo "$(RED)FAILED to compile or run test on $^$(NC)\n"; \
	fi

# Clean up executables
clean:
	@rm -f $(EXE)
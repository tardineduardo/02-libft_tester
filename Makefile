# Compiler and linker
CC := gcc
CFLAGS := -Wall -Wextra -Werror
LDFLAGS := -ldl  # Link against the dynamic loading library

# Directory containing the student's libft files
LIBFT_DIR := ..

# Directory containing the test files
TEST_DIR := tests

# Include paths for the header files
INCLUDES := -I$(LIBFT_DIR) -I$(TEST_DIR)

# Path to the libft.a library
LIBFT := $(LIBFT_DIR)/libft.a

# Source files for the tester
TEST_SRC := $(wildcard $(TEST_DIR)/*.c)
TEST_OBJ := $(TEST_SRC:.c=.o)

# Name of the executable that will run the tests
TEST_EXEC := tester

# Default target
all: $(TEST_EXEC)

# Linking the test executable
$(TEST_EXEC): $(LIBFT) $(TEST_OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) $(INCLUDES) -o $@ $(TEST_OBJ) $(LIBFT)

# Compiling object files
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Running the tester to execute all tests
run: $(TEST_EXEC)
	./$(TEST_EXEC)

# Cleaning up the build files
clean:
	rm -f $(TEST_OBJ) $(TEST_EXEC)
	$(MAKE) -C $(LIBFT_DIR) clean

# Removing everything including the static library
fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean

# Rebuilding everything from scratch
re: fclean all

# Phony targets
.PHONY: all run clean fclean re

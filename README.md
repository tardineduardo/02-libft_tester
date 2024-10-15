# Libft Tester

This is a **libft tester** created by Eduardo. It's my first tester! My goal is to learn how to create our own testers, how to create Makefiles, how compilation works, and how to collaborate on git.

## Overview
This tester checks each function individually. We are not checking the compilation requirements of the exercise.

**Note**: Don't rely on us to check if your functions work! Expect all types of compilation errors, logic errors, and inaccurate results. We accept constructive feedback. This is my baby; it's ugly, but I love it anyway.

## How to Use

1. From inside your libft folder, clone this repository:
`git clone https://github.com/tardineduardo/02-libft_tester.git`

3. Open the test folder:
`cd 02-libft_tester`

4. Run the tests:
`make`

5. To update the existing /libft_tester folder, from inside it run:
`git pull origin main`

## Important Notes
I'm still learning how to create more complex and dynamic Makefiles, so for this version, you need to follow stricter rules:
- Your main libft folder can't have any `.c` files other than the ones expected by the exercise.
- All `.c` files to be tested need to be on the same root folder.
- All `.c` files to be tested must include this header:
 ```c
 #include "libft.h"
 ```
## Tests available
- ft_atoi
- ft_bzero
- ft_isalpha
- ft_islanum
- ft_isascii
- ft_isprint
- ft_isdigit
- ft_memset
- ft_memcpy
- ft_memmove
- ft_memset
- ft_memcmp
- ft_strlen
- ft_toupper
- ft_tolower
- ft_strchar
- ft_strrchar
- ft_strdup
- ft_striteri
- ft_strlcat
- ft_strlcpy
- ft_strtrim
- ft_strjoin

## Unavailable
- ft_calloc
- ft_itoa
- ft_split
- ft_strncmp
- ft_strmapi
- ft_lstclear
- ft_lstdelone
- ft_lstiter
- ft_lstlast
- ft_lstmap
- ft_lstnew
- ft_lstsize
- ft_putchar_fd
- ft_putendl_fd
- ft_putnbr_fd
- ft_putstr_fd
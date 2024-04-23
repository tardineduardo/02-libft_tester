# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/21 20:10:52 by eduribei          #+#    #+#              #
#    Updated: 2024/04/23 19:30:20 by eduribei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = libft.a
SRCS    = ./srcs/*.c
HEAD    = ./includes
OBJS    = $(SRCS:.c=.o)
CFLAGS  = -Wall -Wextra -Werror -I$(HEAD)
GCC     = cc

all:    $(NAME)

.c.o:
	${GCC} ${CFLAGS} -c $< -o $@

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
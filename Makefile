.IGNORE:

NAMEL	= libft.a
SRC1	= $(wildcard ../ft_*.c)
SRC2	= $(patsubst ../%.o,tests/test_%.c,$(OBJS2))
OBJS1	= $(SRC1:.c=.o)
OBJS2	= $(wildcard ../ft_*.o)
CFLAGS	= -Wall -Wextra -Werror -I.
GCC		= cc

all:	$(NAMEL) exec

.c.o:
	${GCC} ${CFLAGS} -c $< -o $@

$(NAMEL): $(OBJS1)
	ar rc $(NAMEL) $(OBJS1)
	ranlib $(NAMEL)

exec:	$(NAMEL) $(OBJS2) $(SRC2)
	$(GCC) $(CFLAGS) -o exec $^
	./exec

clean:
	rm -f $(OBJS1) $(OBJS2) 

fclean: clean
	rm -f $(NAMEL)

re: fclean all

.PHONY: all clean fclean re
NAMEL	= libft.a

SRC_F	= $(wildcard ../ft_*.c)
OBJ_F	= $(SRC_F:.c=.o)

SRC_T	= $(patsubst ../%.o,tests/test_%.c,$(OBJ_F))
OBJ_T	= $(SRC_T:.c=.o)

SRC_CHECK	= $(wildcard ../ft_*.c)
OBJ_CHECK	= $(SRC_F:.c=.o)

EXEC	= $(patsubst ../%.o,tests/test_%,$(OBJ_F))

CFLAGS	= -Wall -Wextra -Werror -I.
GCC		= cc

RED = \033[0;31m
BLUE = \033[0;34m
GREEN = \033[0;92m
YELLOW = \033[0;93m
PINK = \033[0;35m
GRAY = \033[0;90m
NC = \033[0m


all:	check $(NAMEL) $(OBJ_F) $(OBJ_T) $(EXEC) results fclean

check:
	@echo "\nChecking if your functions compile...\n"
	@for file in $(SRC_CHECK); do \
		${GCC} ${CFLAGS} -c $$file > /dev/null 2> temp.txt && echo -n "$(GREEN)[$$file compiles]$(NC)" || { \
		cat temp.txt >> errors/errors.txt; echo -n "$(RED)[$$file FAILED]$(NC)"; \
		}; \
		rm -f temp.txt; \
	done
	@echo "\n"
	@rm -f *.o
	@if [ -f errors/errors.txt ]; then \
		mv errors/errors.txt errors/errors_`date +%Y%m%d_%H%M%S`.txt; \
		echo "$(RED)ALL FT_*.C FILES MUST COMPILE. CHECK ERRORS/ERRORS*.TXT\n$(NC)";\
		awk 'BEGIN { printf "$(RED)" } { print $$0 } END { printf "$(NC)" }' messages/m1.txt;\
		exit 1;\
	fi
	@awk 'BEGIN { printf "$(BLUE)" } { print $$0 } END { printf "$(NC)" }' messages/m2.txt
	@echo "\n\nNow let's check if they work..."
	@echo "\n"
	
.c.o:
	@${GCC} ${CFLAGS} -c $< -o $@

$(NAMEL):	$(OBJ_F)
	@ar rc $(NAMEL) $(OBJ_F)
	@ranlib $(NAMEL)

tests/%.o: tests/%.c
	@${GCC} ${CFLAGS} -c $< -o $@

$(EXEC): $(OBJ_T) $(NAMEL)
	-@${GCC} ${CFLAGS} -o $@ $@.o ./tests/results.c $(NAMEL) -lbsd
	-@./$@ 2> /dev/null || echo "$(RED)[$@ crashed with SIGSEGV]$(NC)"

results:
	@awk 'BEGIN { printf "$(BLUE)" } { print $$0 } END { printf "$(NC)" }' messages/m3.txt
	@echo "\n"
	@awk 'BEGIN { RS = ","; ORS = " " } \
	{ \
	if ($$0 ~ /\[ft_.*: OK\]/) \
		print "\033[32m" $$0 "\033[0m"; \
	else if ($$0 ~ /\[ft_.*: FAIL\]/) \
		print "\033[31m" $$0 "\033[0m"; \
	else if ($$0 ~ /\[ft_.*: not ready\]/) \
		print "$(GRAY)" $$0 "$(NC)"; \
	else \
		print $$0; \
	}' results.txt
	@rm -f results.txt
	@echo "\n\n"
	@awk 'BEGIN { printf "$(PINK)" } { print $$0 } END { printf "$(NC)" }' messages/m4.txt
	@echo "\n"

clean:
	@rm -f $(OBJ_F) $(OBJ_T) $(EXEC)

fclean: clean
	@rm -f $(NAMEL)

re: fclean all
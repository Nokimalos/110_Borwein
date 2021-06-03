##
## EPITECH PROJECT, 2021
## 110
## File description:
## Makefile
##

SRC		=	src/midpoint.c		\
			src/simpson.c		\
			src/trapezoidal.c	\
			src/utils.c

OBJ		=	$(SRC:.c=.o)

NAME		=	110borwein

CPPFLAGS	= -I include/

CFLAGS	=	  -g3 -lm

LDFLAGS	=	-L lib/my -l my

all:	$(NAME)

$(NAME): $(OBJ)
	cd lib/my && $(MAKE)
	gcc -o $(NAME) $(OBJ) src/main.c $(CPPFLAGS) $(LDFLAGS) $(CFLAGS)

tests_run: $(OBJ)
	gcc -o unit_tests $(SRC) tests/tests_110borwein.c $(CPPFLAGS) $(LDFLAGS) $(CFLAGS) -lcriterion --coverage
	./unit_tests && gcovr . --html-details --html -o covr.html --exclude tests/

clean:
	rm -f *.o
	rm -f lib/my/*.o
	rm -f src/*.o
	rm -f *~
	rm -f *.html
	rm -f lib/libmy.a
	rm -f lib/my/libmy.a
	rm -f *.gcda
	rm -f *.gcno

fclean: clean
	rm -f $(NAME)
	rm -f unit_tests

re:	fclean all tests_run

.PHONY: all clean fclean re

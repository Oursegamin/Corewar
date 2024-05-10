##
## EPITECH PROJECT, 2023
## Makefiles
## File description:
## solostumper
##

MAIN =	 	main.c								\

SRC =	 	src/error_handling.c				\
			src/open_file.c						\
			src/corewar.c						\
			src/load_in_arena.c

PARSING	=	src/parsing/parsing.c				\
			src/parsing/champion_parsing.c		\

INSTRUCTION	=	src/instruct/parse_instruct.c	\
				src/instruct/op.c				\


SRCTEST = 	tests/test.c						\

OBJ =	$(MAIN:.c=.o) $(SRC:.c=.o) $(PARSING:.c=.o) $(INSTRUCTION:.c=.o)

OBJTEST = $(SRCTEST:.c=.o)

NAME =		corewar

NAMETEST = 	unit_tests

CFLAGS = -Wall -Wextra -g3

CPPFLAGS	=	-I./include

LDFLAGS	= -L./lib/my

LDLIBS = -lmy

CC = gcc

all: buildlib $(NAME)

$(NAME):	$(OBJ)
	$(CC) $(LDFLAGS) -o $@ $(OBJ) $(LDLIBS)

buildlib:
	make -C ./lib/my

buildlibtest:
	make -C ./lib/my CFLAGS='$(CFLAGS) --coverage'

buildtest: CFLAGS += --coverage
buildtest: buildlibtest $(OBJTEST)
	$(CC) $(LDFLAGS) -o $(NAMETEST) $(OBJTEST) $(LDLIBS)	\
	--coverage -lcriterion

clean:
	rm -f $(OBJ)
	find . -name "*~" -delete
	find . -name "#*#" -delete
	find . -name "vgcore*" -delete
	find . -name "*.gcno" -delete
	find . -name "*.gcda" -delete
	find . -name "*.gcov" -delete
	find . -name "coding-style-reports.log" -delete

fclean: clean cleantest
	rm -f $(NAME)
	make fclean -C ./lib/my

cleantest:
		rm -f $(NAMETEST)
		rm -f $(OBJTEST)

re: fclean all

valgrind: buildlib $(OBJ)
	$(CC) -g3 $(LDFLAGS) -o $(NAME) $(OBJ) $(LDLIBS)

unit_tests: buildtest

run_tests:
	./unit_tests
	gcovr

.PHONY: all clean fclean re valgrind unit_tests run_tests cleantest
		buildlibtest buildtest buildlib

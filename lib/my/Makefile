##
## EPITECH PROJECT, 2023
## makefile
## File description:
## task01
##

SRC     =	my_putchar.c			\
			my_put_errchar.c		\
			my_put_errstr.c			\
			my_putstr.c				\
			my_revstr.c				\
			my_strlen.c				\
			my_revstr.c				\
			my_getnbr.c				\
			my_strcmp.c				\
			my_strncmp.c			\
			my_strcpy.c				\
			my_strncpy.c			\
			my_strdup.c				\
			my_strndup.c			\
			my_strcat.c				\
			my_strtok.c				\
			my_strstr.c				\
			my_arraylen.c			\
			my_int_to_base.c		\
			my_bin_to_dec.c			\
			my_compute_power_rec.c	\
			my_hton.c				\
			my_memcpy.c				\
			my_swap.c				\

OBJ     =	$(SRC:.c=.o)

NAME    =	libmy.a

CPPFLAGS	=	-I../../include

CFLAGS  =	-W -Wall -Wextra

CC      =	 gcc

all: $(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
	find . -name "*~" -delete
	find . -name "#*#" -delete
	find . -name "vgcor*" -delete

fclean:		clean
	rm -f $(NAME)

re:	fclean all

auteur:
	echo $(USER) > auteur

.PHONY:-all clean fclean re

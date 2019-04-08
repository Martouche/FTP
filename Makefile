##
## EPITECH PROJECT, 2019
## my ftp Makefile
## File description:
## made by Martin Vantalon
##

NAME= myftp

CC= gcc

CFLAGS  = -W -Wall -Wextra -I./include

SRC=	srcs/my_ftp.c\
	srcs/main.c

OBJ=    $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(OBJ) -o $(NAME)

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

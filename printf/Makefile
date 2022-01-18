SRC = ft_printf.c ft_putchar.c ft_putnbr.c ft_putstr.c printpoint.c exa.c

OBJ = ${SRC:.c=.o}

NAME = libftprintf.a


all:	${NAME}
		
${NAME}:
	gcc -Wall -Wextra -Werror -c ${SRC}
	ar rc ${NAME} ${OBJ}

bonus:
	
clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all
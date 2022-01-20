CC = gcc
CFLAGS = -Wextra -Wall -Werror

SRC = fdf.c gnl/get_next_line.c gnl/get_next_line_utils.c segment.c main.c

OBJ = ${SRC:.c=.o} ${SRS:.c=.o}

NAME = fdf
LIBMLX = minilibx/libmlx.a
LIBPRINTF = printf/libftprintf.a
LIBFT = libft/libft.a

all:	${NAME}

${LIBMLX}:
		@make -C minilibx/

${LIBPRINTF}:
		@make -C printf/

${LIBFT}:
	@make -C libft/

${NAME}: ${LIBPRINTF} ${LIBFT} ${OBJ}
	gcc -o ${NAME} ${OBJ} ${LIBPRINTF} ${LIBFT}  -lmlx -framework OpenGl -framework AppKit

clean:
	rm -f ${OBJ}
	@make clean -C minilibx/
	@make clean -C printf/
	@make clean -C libft/

fclean: clean
	rm -f ${NAME}
	@make clean -C minilibx/
	@make fclean -C printf/
	@make fclean -C libft/

re: fclean all
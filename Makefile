CC = gcc
CFLAGS = -Wextra -Wall -Werror

SRC = fdf.c gnl/get_next_line.c gnl/get_next_line_utils.c segment.c main.c line.c depla.c color.c mul.c

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

${NAME}: ${LIBMLX} ${LIBPRINTF} ${LIBFT} ${OBJ}
	gcc -o ${NAME} ${OBJ} ${LIBMLX} ${LIBPRINTF} ${LIBFT}  -Lmlx_linux -lXext -lX11 -fsanitize=address

macos: ${LIBPRINTF} ${LIBFT} ${OBJ}
	gcc -o ${NAME} ${OBJ} ${LIBPRINTF} ${LIBFT} -lmlx -framework OpenGl -framework AppKit -fsanitize=address

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
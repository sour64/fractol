NAME	= fractol

SRCS	= main.c draw.c fractals.c tools.c controls.c

HEADER	= fractal.h

OBJS 	= ${SRCS:%.c=%.o}

CC 		= gcc

FLAGS 	= -Wall -Wextra -Werror -O3

all		: ${NAME}

${NAME} : $(OBJS)
		$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)


%.o		: %.c
		$(CC) $(FLAGS) -Imlx -c $< -o $@

clean	:
		rm -f ${OBJS}

fclean	: clean
		rm -f ${NAME}

re		: fclean all

.PHONY: all clean fclean re bonus
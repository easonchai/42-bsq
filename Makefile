NAME = bsq

SRCS = srcs/ft_solve.c srcs/ft_display.c srcs/main.c srcs/ft_utils.c

CFLAGS = -Wall -Wextra -Werror

all:	${NAME}

clean:
		rm -f ${NAME}

fclean:	clean

re:		fclean all

${NAME}:	${SRCS}
			gcc ${CFLAGS} ${SRCS} -o ${NAME}

.PHONY:		all clean fclean re

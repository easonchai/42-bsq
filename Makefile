NAME = bsq

SRCS = srcs/ft_solve.c srcs/ft_display.c srcs/main.c srcs/ft_utils.c \
	   srcs/ft_checkinput.c srcs/ft_makegrid.c

CFLAGS = -Wall -Wextra -Werror

all:	${NAME}

clean:
		rm -f ${NAME}

fclean:	clean

re:		fclean all

${NAME}:	${SRCS}
			gcc ${CFLAGS} ${SRCS} -o ${NAME}
			rm srcs/*.o

.PHONY:		all clean fclean re

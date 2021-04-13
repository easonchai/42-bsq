NAME = bsq

SRCS = srcs/ft_solve.c srcs/ft_display.c srcs/main.c srcs/ft_utils.c \
	   srcs/ft_checkinput.c srcs/ft_makegrid.c

CFLAGS = -Wall -Wextra -Werror

OBJS = ${SRCS:.c=.o}

.c.o:
	gcc ${CFLAGS} -c $< -o ${<:.c=.o}

all:	${NAME}

clean:
		rm -f ${OBJS}

fclean:	clean
		rm -f ${NAME}

re:		fclean all

${NAME}:	${OBJS}
			gcc -o ${NAME} ${OBJS}

.PHONY:		all clean fclean re

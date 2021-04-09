NAME = bsq

SRCS = srcs/ft_solve.c srcs/ft_display.c srcs/main.c srcs/ft_utils.c

INCLUDES = includes

OBJS = ${SRCS:.c=.o}

CFLAGS = -Wall -Wextra -Werror

.c.o: 
		gcc ${CFLAGS} -I -c $< 

all:	${NAME}

clean:
		rm -f ${OBJS}

fclean:	clean
		rm -f ${NAME}

re:		fclean all

${NAME}:	${OBJS}
		

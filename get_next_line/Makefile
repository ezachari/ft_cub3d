NAME	=	libgnl.a

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra

HEAD	=	get_next_line.h

HFLAG	=	-I${HEAD}

SRCS	=	get_next_line.c \
			get_next_line_utils.c

OBJS	=	${SRCS:.c=.o}

RM		=	rm -f


all: 		${NAME}

.c.o:
	@${CC} ${CFLAGS} -c ${HFLAG} $< -o $@ 

${NAME}:	${OBJS}
	@ar rc ${NAME} ${OBJS}
	@ranlib ${NAME}

clean:
	@${RM} ${OBJS} ${OBJSB}

fclean:		clean
	@${RM} ${NAME}

re: 	fclean all

.PHONY: clean fclean re all

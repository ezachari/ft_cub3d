.PHONY: all clean fclean re
NAME	=	cub3D
CUBSRCS	=	main.c \
			srcs/cub3d.c srcs/raycast.c srcs/draw.c \
			utils/move.c utils/move1.c utils/utils1.c \
			init/init.c init/init1.c init/init2.c init/init_z.c \
			utils/color.c utils/errors.c utils/utils.c utils/sort.c \
			srcs/sprite.c srcs/screenshot.c \
			parser/map.c parser/parser.c parser/check.c parser/extract.c
LIBOBJ	=	libft/ft_atoi.o libft/ft_bzero.o \
			libft/ft_isalnum.o libft/ft_isalpha.o \
			libft/ft_isascii.o libft/ft_isdigit.o \
			libft/ft_isprint.o libft/ft_memccpy.o \
			libft/ft_memchr.o libft/ft_memcmp.o \
			libft/ft_memcpy.o libft/ft_memmove.o \
			libft/ft_memset.o libft/ft_strchr.o \
			libft/ft_strlcat.o libft/ft_strlcpy.o \
			libft/ft_strlen.o libft/ft_strrchr.o \
			libft/ft_calloc.o libft/ft_strdup.o \
			libft/ft_strnstr.o libft/ft_strncmp.o \
			libft/ft_toupper.o libft/ft_tolower.o \
			libft/ft_putchar_fd.o libft/ft_putstr_fd.o \
			libft/ft_putnbr_fd.o libft/ft_putendl_fd.o \
			libft/ft_itoa.o libft/ft_substr.o \
			libft/ft_strjoin.o libft/ft_strtrim.o \
			libft/ft_strmapi.o libft/ft_split.o \
			libft/ft_lstnew.o libft/ft_lstadd_front.o \
			libft/ft_lstsize.o libft/ft_lstlast.o \
			libft/ft_lstadd_back.o libft/ft_lstdelone.o \
			libft/ft_lstclear.o libft/ft_lstiter.c libft/ft_lstmap.o
GNLOBJ	=	get_next_line/get_next_line.o \
			get_next_line/get_next_line_utils.o
CUBOBJ	=	${CUBSRCS:.c=.o}
CC		=	gcc
INC		=	./includes
CFLAGS	=	-Wall -Wextra -Werror
FWORK	=	-framework OpenGL -framework AppKit
LIB		=	-L. -lmlx -lft -lgnl
LIBFT	=	./libft
LIBGNL	=	./get_next_line
LIBMLX	=	./mlx
all:	${NAME}
${NAME}: ${OBJ} ${LIBOBJ} ${GNLOBJ} ${CUBOBJ} ${INC}/*.h
	make -C ${LIBFT}
	cp ${LIBFT}/libft.a .
	make -C ${LIBGNL}
	cp ${LIBGNL}/libgnl.a .
	make -C ${LIBMLX}
	cp ${LIBMLX}/libmlx.dylib .
	${CC} ${CFLAGS} ${FWORK} -I${INC} -o ${NAME} ${LIB} ${CUBOBJ}
%.o : %.c
	${CC} ${CFLAGS} -I${INC} -c $< -o $@
clean:
	make -C ${LIBFT} clean
	make -C ${LIBGNL} clean
	make -C ${LIBMLX} clean
	rm -f ${CUBOBJ}
fclean:	clean
	make -C ${LIBFT} fclean
	make -C ${LIBGNL} fclean
	make -C ${LIBMLX} clean
	rm -f libft.a libgnl.a libmlx.dylib
	rm -f ${NAME}
re:		fclean all

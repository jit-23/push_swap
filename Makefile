NAME =  ps
CFLAGS = -Wall -Werror -Wextra
FUN = src/main.c src/utils.c src/handle_string.c src/handle_args.c
OBJ = ${FUN:.c=.o}
LIBFT = -L libft -lft
MAKE = make -C

all: ${NAME}

${NAME} : ${OBJ}
			${MAKE} libft
			cc ${CFLAGS} -I. ${FUN}  ${LIBFT} -o ${NAME}
clean:
	rm -f ${OBJ}
	${MAKE} libft clean

fclean: clean
	rm -f ${NAME}	   
	${MAKE} libft fclean

re : fclean all

.PHONY: fclean clean re all
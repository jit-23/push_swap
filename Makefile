NAME =  push_swap

CFLAGS = -Wall -Werror -Wextra
FUN = src/main.c src/utils.c src/handle_string.c src/handle_args.c \
		src/quick_sort.c src/utils2.c src/utils3.c src/utils4.c src/turk.c \
		moves/swap.c moves/rotate.c moves/reverse_rotate.c moves/push.c \
		 
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

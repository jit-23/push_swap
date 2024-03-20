NAME =  push_swap
CHECKER = checker
CFLAGS = -Wall -Werror -Wextra
FUN:= $(wildcard src/*.c) $(wildcard moves/*.c)
CHECKER_BONUS:= $(wildcard checker/*.c)
#FUN = src/main.c src/utils.c src/handle_string.c src/handle_args.c \
		src/quick_sort.c src/utils2.c src/utils3.c src/utils4.c src/turk.c \
		moves/swap.c moves/rotate.c moves/reverse_rotate.c moves/push.c \

OBJ_BONUS:= ${patsubst %.c, %.o, ${FUN}}
OBJ:= ${patsubst %.c, %.o, ${FUN}}
#MAKE_LIBFT = make -C libftm
MAKE_LIBFT:= make -C ./libft
LIBFT:= ./libft/libft.a
all: ${OBJ} ${NAME}

${NAME} :
			${MAKE_LIBFT}
			cc ${CFLAGS} -I. ${FUN}  ${LIBFT} -o ${NAME}
${CHECKER}: ${CHECKER_BONUS}
	cc ${CFLAGS} ${CHECKER_BONUS} ${LIBFT} -o ${CHECKER}
clean:
	rm -f ${OBJ}
	rm -f ${OBJ_BONUS}
	${MAKE_LIBFT} clean

fclean: clean
	rm -f ${NAME}   
	rm -f ${CHECKER}   
	${MAKE_LIBFT} fclean

re : fclean all

bonus : ${CHECKER}
bonus re
.PHONY: fclean clean re all checker
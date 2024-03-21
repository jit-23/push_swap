NAME =  push_swap
CHECKER = checker
CFLAGS = -Wall -Werror -Wextra

UTILS:=	src/push_swap.c src/fill_stack.c src/utils.c src/handle_str.c src/handle_args.c \
		src/quick_sort.c src/utils2.c src/utils3.c src/utils4.c src/turk.c \
		moves/swap.c moves/rotate.c moves/reverse_rotate.c moves/push.c \

MAIN:= src/main.c

FUN = ${MAIN} ${UTILS}

CHECKER_FUN:=  ${UTILS} bonus/checker.c bonus/checker_utils.c

OBJ_BONUS:= ${patsubst %.c, %.o, ${CHECKER_FUN}}
OBJ:= ${patsubst %.c, %.o, ${FUN}}

MAKE_LIBFT:= make -C ./libft
LIBFT:= ./libft/libft.a

all: ${NAME}

${NAME} : ${OBJ}
			${MAKE_LIBFT}
			cc ${CFLAGS} -I. ${FUN}  ${LIBFT} -o ${NAME}

bonus : ${CHECKER}

${CHECKER}: ${OBJ_BONUS} 
	cc ${CFLAGS}  ${CHECKER_FUN} ${LIBFT} -o ${CHECKER}

clean:
	rm -f ${OBJ}
	rm -f ${OBJ_BONUS} 
	${MAKE_LIBFT} clean

fclean: clean
	rm -f ${NAME}   
	rm -f ${CHECKER}
	${MAKE_LIBFT} fclean

re : fclean all

bonus_re : fclean all bonus

.PHONY: fclean clean re all bonus
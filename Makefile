NAME =  push_swap
CHECKER = checker
CFLAGS = -Wall -Werror -Wextra

#FUN:= $(wildcard src/*.c) $(wildcard moves/*.c)


UTILS:=	src/push_swap.c src/fill_stack.c src/utils.c src/handle_str.c src/handle_args.c \
		src/quick_sort.c src/utils2.c src/utils3.c src/utils4.c src/turk.c \
		moves/swap.c moves/rotate.c moves/reverse_rotate.c moves/push.c \

MAIN:= src/main.c

FUN = ${MAIN} ${UTILS}
#CHECKER_BONUS:= $(wildcard bonus/src/*.c)
CHECKER_FUN:=  ${UTILS} bonus/checker.c bonus/checker_utils.c

OBJ_BONUS:= ${patsubst %.c, %.o, ${CHECKER_FUN}}
OBJ:= ${patsubst %.c, %.o, ${FUN}}

MAKE_LIBFT:= make -C ./libft
LIBFT:= ./libft/libft.a

all: ${NAME}

${NAME} : ${OBJ}
			${MAKE_LIBFT}
			cc ${CFLAGS} -I. ${OBJ}  ${LIBFT} -o ${NAME}



${CHECKER} : ${OBJ_BONUS}
			cc ${OBJ_BONUS} ${LIBFT} -o ${CHECKER}

bonus : ${CHECKER}

#${CHECKER}: ${OBJ_BONUS} 
#	cc ${CFLAGS}  ${OBJ_BONUS} ${LIBFT} -o ${CHECKER}

clean:
	rm -f ${OBJ}
	rm -f ${OBJ_BONUS} 
	${MAKE_LIBFT} clean

fclean: clean
	rm -f ${NAME}   
	rm -f ${CHECKER}
	${MAKE_LIBFT} fclean


re : fclean all

r : fclean all bonus

.PHONY: fclean clean re all bonus
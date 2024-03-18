NAME =  push_swap
CFLAGS = -Wall -Werror -Wextra
FUN:= $(wildcard src/*.c) $(wildcard moves/*.c)
#FUN = src/main.c src/utils.c src/handle_string.c src/handle_args.c \
		src/quick_sort.c src/utils2.c src/utils3.c src/utils4.c src/turk.c \
		moves/swap.c moves/rotate.c moves/reverse_rotate.c moves/push.c \
		 
OBJ:= ${patsubst %.c, %.o, ${FUN}}
#MAKE_LIBFT = make -C libftm
MAKE_LIBFT:= make -C ./libft
LIBFT:= ./libft/libft.a
all: ${OBJ} ${NAME}

${NAME} :
			${MAKE_LIBFT}
			cc ${CFLAGS} -I. ${FUN}  ${LIBFT} -o ${NAME}
clean:
	rm -f ${OBJ}
	${MAKE_LIBFT} clean

fclean: clean
	rm -f ${NAME}	   
	${MAKE_LIBFT} fclean

re : fclean all

.PHONY: fclean clean re all


#SOURCES = file1.c file2.c file3.c
#OBJECTS = $(patsubst %.c, %.o, $(SOURCES))
#
#all: $(OBJECTS)
#
#$(OBJECTS): %.o: %.c
#    gcc -c $< -o $@
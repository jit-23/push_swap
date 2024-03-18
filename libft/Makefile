# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/23 21:29:48 by fde-jesu          #+#    #+#              #
#    Updated: 2024/03/18 17:18:22 by fde-jesu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
HEADER = libft.h
CFLAGS = -Wall -Werror -Wextra

FUN = $(wildcard *.c)

OBJ = ${FUN:.c=.o}

all: $(NAME)

$(NAME):
	      cc -g ${CFLAGS} -c -I. ${HEADER} ${FUN}
		 ar rcs ${NAME} ${OBJ}
clean:
	rm -f $(OBJ) 

fclean: clean
	rm -f $(NAME)
      
re: fclean all

.PHONY: all clean fclean re
.SILENT:
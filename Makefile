# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/11 12:46:12 by msavelie          #+#    #+#              #
#    Updated: 2024/06/11 14:51:18 by msavelie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = \
	push_swap.c \
	convert_args.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra

LIBFT_NAME = ./libft/libft.a
LIBFT_DIR = ./libft

RM = rm -rf
AR = ar -rcs
LIB = ranlib

.PHONY = all clean fclean re

all: ${LIBFT_NAME} ${NAME}

${LIBFT_NAME}:
	make -C ${LIBFT_DIR}


${NAME}: ${OBJS}
	cp ${LIBFT_DIR}/libft.a .
	cc ${FLAGS} ${SRCS} libft.a -o ${NAME}
	@chmod 777 ${NAME}

clean: 
	${RM} ${OBJS}
	make clean -C ${LIBFT_DIR}

fclean: clean
	${RM} ${NAME}
	make fclean -C ${LIBFT_DIR}
	${RM} libft.a

re: fclean all
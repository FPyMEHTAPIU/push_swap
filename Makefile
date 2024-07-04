# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/11 12:46:12 by msavelie          #+#    #+#              #
#    Updated: 2024/07/04 12:21:02 by msavelie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

INSTR_DIR = ./Instructions
LIST_DIR = ./Stack_operations
SORT_DIR = ./Sorting

SRCS = \
	main.c \
	convert_args.c \
	check_args.c \
	${INSTR_DIR}/instructions_ps.c  \
	${INSTR_DIR}/instructions_rotate.c \
	${LIST_DIR}/ft_add_back.c \
	${LIST_DIR}/ft_add_front.c \
	${LIST_DIR}/ft_clear.c \
	${LIST_DIR}/ft_first.c \
	${LIST_DIR}/ft_last.c \
	${LIST_DIR}/ft_stack_new.c \
	${SORT_DIR}/sort_small.c \
	${SORT_DIR}/moves_calculator.c \
	${SORT_DIR}/sorting.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra

LIBFT_NAME = ./libft/libft.a
LIBFT_DIR = ./libft

RM = rm -rf

.PHONY = all clean fclean re

all: ${LIBFT_NAME} ${NAME}

${LIBFT_NAME}:
	@make -C ${LIBFT_DIR}

${NAME}: ${OBJS}
	@cp ${LIBFT_DIR}/libft.a .
	@cc -g ${FLAGS} ${SRCS} libft.a -o ${NAME}
	@chmod 777 ${NAME}

clean: 
	@${RM} ${OBJS}
	@make clean -C ${LIBFT_DIR}

fclean: clean
	@${RM} ${NAME}
	@make fclean -C ${LIBFT_DIR}
	@${RM} libft.a

re: fclean all
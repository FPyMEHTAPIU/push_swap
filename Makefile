# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/11 12:46:12 by msavelie          #+#    #+#              #
#    Updated: 2024/07/16 16:07:36 by msavelie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_LIB = bonus_lib.a
BONUS_NAME = checker

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
	${LIST_DIR}/ft_alloc_stack.c \
	${LIST_DIR}/ft_clear.c \
	${LIST_DIR}/ft_first.c \
	${LIST_DIR}/ft_last.c \
	${LIST_DIR}/ft_stack_new.c \
	${LIST_DIR}/holder.c \
	${SORT_DIR}/sort_small.c \
	${SORT_DIR}/moves_ab.c \
	${SORT_DIR}/moves_calculator.c \
	${SORT_DIR}/rotate_actions.c \
	${SORT_DIR}/sorting.c \
	${SORT_DIR}/is_ordered.c \
	${SORT_DIR}/max_min.c \
	${SORT_DIR}/to_pos.c

BONUS_DIR = ./Checker

BONUS = \
	${BONUS_DIR}/checker_bonus.c \
	${BONUS_DIR}/main_bonus.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS:.c=.o)

CFLAGS = -Wall -Werror -Wextra

LIBFT_NAME = ./libft/libft.a
LIBFT_DIR = ./libft

RM = rm -rf
AR = ar -rcs
LIB = ranlib

.PHONY = all clean fclean re bonus

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
	@${RM} ${BONUS_OBJS}
	@${RM} ${BONUS_LIB}

fclean: clean
	@${RM} ${NAME}
	@make fclean -C ${LIBFT_DIR}
	@${RM} libft.a
	@${RM} .bonus
	@${RM} ${BONUS_NAME}

re: fclean all

${BONUS_LIB}: ${OBJS} ${BONUS_OBJS}
	@${AR} ${BONUS_LIB} ${OBJS} ${BONUS_OBJS}
	@${LIB} ${BONUS_LIB}

${BONUS_NAME}: ${BONUS_LIB} ${BONUS_OBJS}
	@touch .bonus
	@cp ${LIBFT_DIR}/libft.a .
	@cc -g ${FLAGS} ${BONUS} ${BONUS_LIB} libft.a -o ${BONUS_NAME}
	@chmod 777 ${BONUS_NAME}

bonus: ${BONUS_NAME}
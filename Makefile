# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: armajchr <armajchr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/01 14:58:34 by armajchr          #+#    #+#              #
#    Updated: 2019/10/31 14:09:39 by armajchr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Binaries
CC		= /usr/bin/gcc
AR		= /usr/bin/ar
RANLIB	= /usr/bin/ranlib
RM		= /bin/rm
FLAG	= -Wall -Wextra -Werror

NAME	= push_swap
NAME2	= checker
LIB1	= Libft/libft.a
LIB2	= ft_printf/libftprintf.a
SRC		= push_swap.c		\
		basic.c				\
		basic2.c			\
		rules_swap.c		\
		rules_push.c		\
		rules_rotate.c		\
		rules_rev_rotates.c	\
		sort_ope.c			\
		sort_ope2.c			\
		sort_ope3.c			\
		nb_ope2.c			\
		nb_ope3.c			\
		nb_ope4.c			\
		ft_create_elem.c	\
		final_ope.c			\
		check_list.c		\
		push_swap2.c		\
		push_swap3.c		\
		free_stack.c		\

SRC2	= checker.c			\
		basic.c				\
		basic2.c			\
		rules_swap.c		\
		rules_push.c		\
		rules_rotate.c		\
		rules_rev_rotates.c	\
		ft_create_elem.c	\
		check_list.c		\
		free_stack.c		\

HFILES	= push_swap.h

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(NAME2) $(LIB1) $(LIB2) $(SRC)
	@gcc $(FLAG) -o $(NAME) $(SRC) $(LIB1) $(LIB2)
	@echo "\033[01;34m$(NAME) is ready\033[0m"

$(NAME2): $(LIB1) $(LIB2) $(SRC2)
	@gcc $(FLAG) -o $(NAME2) $(SRC2) $(LIB1) $(LIB2)
	@echo "\033[01;34m$(NAME2) is ready\033[0m"

$(LIB1): $(LIB2)
	@make -C libft

$(LIB2):
	@make -C ft_printf

clean:
	@make -C libft clean
	@make -C ft_printf clean

fclean: clean
	@make -C libft fclean
	@make -C ft_printf fclean
	@$(RM) -f $(NAME)
	@$(RM) -f $(NAME2)

re: fclean all

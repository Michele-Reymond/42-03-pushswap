# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mreymond <mreymond@42lausanne.ch>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/11 19:48:18 by mreymond          #+#    #+#              #
#    Updated: 2022/02/17 12:43:01 by mreymond         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= src/push_swap.c \
			src/ps_errors.c \
			src/ps_linked_list.c \
			src/ps_push.c \
			src/ps_rotate.c \
			src/ps_swap.c \
			src/ps_utils.c \
			src/ps_algo_bubble.c \
			src/ps_algo_pivot.c

OBJS		= $(SRCS:.c=.o)

LBFT_PATH 	= ./src/libft/

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
NAME		= push_swap
RM			= rm -f


all:		$(NAME)

$(NAME):	$(OBJS)
			@$(MAKE) --silent -C $(LBFT_PATH)
			$(CC) $(CFLAGS) $(OBJS) -L $(LBFT_PATH) -lft -o $(NAME)

%.o: %.c
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

run:		
			./$(NAME) -3 -4 6 20 -12 -1 0 -2 1 2 4 3 -5 5 77 65 29 -32 -43 19 487 22 -44 -21

# -1 2 -5 1 -3 4 -2 -4 3 0 5
# -3 -4 -1 0 -2 1 2 4 3 -5 5
# 4 67 3 87 23 58 7 12

test:
			ARG="-3 -4 6 20 -12 -1 0 -2 1 2 4 3 -5 5"; ./$(NAME) $$ARG | wc -l
			ARG="-3 -4 6 20 -12 -1 0 -2 1 2 4 3 -5 5"; ./$(NAME) $$ARG | ./checker_Mac $$ARG

visu:
			python3 pyviz.py `ruby -e "puts (-200..200).to_a.shuffle.join(' ')"`

clean:
			$(RM) $(OBJS)
			@$(MAKE) -C $(LBFT_PATH) clean

fclean:		clean
			$(RM) $(NAME)
			@$(MAKE) -C $(LBFT_PATH) fclean

re:			fclean all

.PHONY:		all clean fclean re run test visu
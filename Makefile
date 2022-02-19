# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mreymond <mreymond@42lausanne.ch>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/11 19:48:18 by mreymond          #+#    #+#              #
#    Updated: 2022/02/19 11:28:33 by mreymond         ###   ########.fr        #
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
			src/ps_algo_pivot.c \
			src/ps_algo_pivot2.c \
			src/ps_algo_pivot_3.c

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
			./$(NAME) -2 -9 23 -25 -13 11 4 8 -29 5 19 30 1 -17 -24 20 -16 -18 13 3 12 17 -4 0 -5 2 -21 -23 -12 -20 14 -26 -22 27 18 22 -27 -1 -30 -8 -15 28 24 16 7 21 25 9 -14 -28 26 29 -11 15 -7 -19 -6 6 10 -3

# -1 2 -5 1 -3 4 -2 -4 3 0 5
# -3 -4 -1 0 -2 1 2 4 3 -5 5
# 4 67 3 87 23 58 7 12

test:
			ARG="4 67 3 87 2"; ./$(NAME) $$ARG | wc -l
			ARG="4 67 3 87 2"; ./$(NAME) $$ARG | ./checker_Mac $$ARG

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
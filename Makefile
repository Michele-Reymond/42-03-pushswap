# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mreymond <mreymond@42lausanne.ch>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/11 19:48:18 by mreymond          #+#    #+#              #
#    Updated: 2022/02/24 22:40:45 by mreymond         ###   ########.fr        #
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
			src/ps_algo_pivot_find.c \
			src/ps_algo_utils.c \
			src/ps_algo.c

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
			./$(NAME) "0 13 -45 -6 -4 18 34 46 30 -17 33 -39 21 -18 24 41 48 5 3 25 -48 -47 -33 11 -32 29 -49 -40 6 -41 19 23 -30 -35 -3 -14 28 26 -23 36 -15 27 38 -19 45 37 -16 -26 49 -44 -22 -46 1 22 39 -36 -34 -29 2 8 9 47 -5 -28 -13 -37 40 43 15 20 -11 -2 -43 -7 16 50 44 32 -10 35 -27 -12 4 -8 -25 -31 12 -50 17 -9 -24 -38 -20 -1 14 -21 31 -42 10 7"

test:
			ARG="318 -181 25"; ./$(NAME) $$ARG | wc -l
			ARG="318 -181 25"; ./$(NAME) $$ARG | ./checker_Mac $$ARG

clean:
			$(RM) $(OBJS)
			@$(MAKE) -C $(LBFT_PATH) clean

fclean:		clean
			$(RM) $(NAME)
			@$(MAKE) -C $(LBFT_PATH) fclean

re:			fclean all

.PHONY:		all clean fclean re run test visu
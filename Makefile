# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mreymond <mreymond@42lausanne.ch>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/11 19:48:18 by mreymond          #+#    #+#              #
#    Updated: 2022/02/15 16:07:45 by mreymond         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= src/push_swap.c \
			src/ps_errors.c \
			src/ps_linked_list.c \
			src/ps_push.c \
			src/ps_rotate.c \
			src/ps_swap.c \
			src/ps_utils.c

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
			./$(NAME) "64 2 -8 54 3"

clean:
			$(RM) $(OBJS)
			@$(MAKE) -C $(LBFT_PATH) clean

fclean:		clean
			$(RM) $(NAME)
			@$(MAKE) -C $(LBFT_PATH) fclean

re:			fclean all

.PHONY:		all clean fclean re run
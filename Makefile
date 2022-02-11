# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mreymond <mreymond@42lausanne.ch>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/11 19:48:18 by mreymond          #+#    #+#              #
#    Updated: 2022/02/11 20:09:06 by mreymond         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= src/push_swap.c

OBJS		= ${SRCS:.c=.o}

LBFT_PATH 	= ./src/libft/

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
NAME		= push_swap
RM			= rm -f


all:		${NAME}

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			@${MAKE} --silent -C ${LBFT_PATH}
			$(CC) $(CFLAGS) -o $(NAME) ${OBJS} -L $(LBFT_PATH) -lft

run:		
			./${NAME} 64 2 8 52 3

clean:
			${RM} ${OBJS}
			@$(MAKE) -C $(LBFT_PATH) clean

fclean:		clean
			${RM} ${NAME}
			@$(MAKE) -C $(LBFT_PATH) fclean

re:			fclean all

.PHONY:		all clean fclean re run
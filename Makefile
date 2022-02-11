# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mreymond <mreymond@42lausanne.ch>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/11 17:05:13 by mreymond          #+#    #+#              #
#    Updated: 2022/02/11 18:44:40 by mreymond         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = src/push_swap.c
CFLAGS = -Wall -Werror -Wextra
CC = gcc
NAME = push_swap
OBJS = ${SRCS:.c=.o}
LIBFT_PATH = ./libft
LIBFT = libft/libft.a
RM = rm -f

all: ${NAME}

$(NAME):	${OBJS}
		@$(MAKE) -C $(LBFT_PATH)
		${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBFT}

%.o : %.c
	${CC} $(CFLAGS) -I$(LBFT_PATH) -c $< -o $@

run: all
	./$(NAME) 9 4 8 7

clean: 
	${RM} ${OBJS}
	@$(MAKE) -C $(LBFT_PATH) clean

fclean: clean
	${RM} ${NAME}
	@$(MAKE) -C $(LBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
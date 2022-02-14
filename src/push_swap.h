/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:08:35 by mreymond          #+#    #+#             */
/*   Updated: 2022/02/14 19:08:01 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>

# define SA "sa"
# define SB "sb"
# define SS "ss"
# define PA "pa"
# define PB "pb"
# define RA "ra"
# define RB "rb"
# define RR "rr"
# define RRA "rra"
# define RRB "rrb"
# define RRR "rrr"

int *stock_args(int count, char **arguments);
void swap(int *stack);
void what_to_swap(int *stack_a, int *stack_b, char *move);
long	ft_atol(const char *str);
int check_args(int argc);
int check_doubles(int *stack, long entry, int pos);
int check_max(long entry);
void check_entry(int *stack, long entry, int pos);
void check_nbr(char *nbr, int *stack);

typedef struct tabs
{
    int	*a;
	int	*b;
    int size_a;
    int size_b;
}   t_tabs;

#endif
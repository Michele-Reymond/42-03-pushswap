/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:08:35 by mreymond          #+#    #+#             */
/*   Updated: 2022/02/15 14:09:18 by mreymond         ###   ########.fr       */
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

typedef struct tabs
{
    int	*a;
	int	*b;
    int size_a;
    int size_b;
}   t_tabs;

typedef struct Nombre t_nbr;
struct Nombre
{
    int     nombre;
    t_nbr   *suivant;
};

typedef struct Liste
{
    t_nbr   *premier;
    int     size;
} t_list;

int *stock_args(int count, char **arguments, int start);
int *stock_string(char **av);
void swap(int *stack);
void what_to_swap(int *stack_a, int *stack_b, char *move);
void what_to_push(t_tabs *stack, char *move);
long	ft_atol(const char *str);
int check_args(int argc, char *string);
int check_doubles(int *stack, long entry, int pos);
int check_max(long entry);
void check_entry(int *stack, long entry, int pos);
void check_nbr(char *nbr, int *stack);
void free_stack( t_tabs *stack);

#endif
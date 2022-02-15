/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:08:35 by mreymond          #+#    #+#             */
/*   Updated: 2022/02/15 21:25:48 by mreymond         ###   ########.fr       */
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

typedef struct Number t_nbr;
struct Number
{
    int     number;
    t_nbr   *next;
};

typedef struct Liste
{
    t_nbr   *first;
    int     size;
} t_list;

t_list *stock_args(int count, char **arguments, int start);
t_list *stock_string(char **av);
void delete_last(t_list *stack);
void insert_after(t_list *liste, long nbr);
t_nbr *find_last(t_list *stack);
void swap(t_list *stack);
void push(t_list *src_stack, t_list **dst_stack);
void what_to_swap(int *stack_a, int *stack_b, char *move);
long	ft_atol(const char *str);
int check_args(int argc, char *string);
int check_doubles(t_list *stack, long entry);
t_list *list_init(long nbr);
void free_list(t_list *liste);
void afficherListe(t_list *liste);
void insert_befor(t_list *liste, long nbr);
int check_max(long entry);
void check_entry(t_list *stack, long entry);
void check_nbr(char *nbr, t_list *stack);
void rotate(t_list *stack);
void rotate_reverse(t_list *stack);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:08:35 by mreymond          #+#    #+#             */
/*   Updated: 2022/02/25 11:02:40 by mreymond         ###   ########.fr       */
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

typedef struct s_number	t_nbr;
struct	s_number
{
	int		number;
	t_nbr	*next;
};

typedef struct s_liste
{
	t_nbr	*first;
	int		size;
	int		last;
	int		first_n;
	int		biggest;
	int		somme;
	int		smallest;
}	t_list;

typedef struct s_pivot
{
	int	high;
	int	low;
	int	add;
}	t_pivot;

t_list	*stock_args(int count, char **arguments, int start);
t_list	*stock_string(char **av);
void	check_begin_order(t_list *stack);
int		pivot_is_in_stack(t_list *stack_a, int pivot);
int		check_order(t_list *stack, int nbr_to_check);
int		check_order_reverse(t_list *stack, int nbr_to_check);
void	delete_last(t_list *stack);
void	insert_after(t_list *liste, long nbr);
t_nbr	*find_last(t_list *stack);
void	bubble_sort(t_list *stack, char *move);
void	bubble_sort_big(t_list *stack, char *move);
void	swap(t_list *stack, char *move);
void	push(t_list *src_stack, t_list **dst_stack, char *move);
long	ft_atol(const char *str);
void	delete_first(t_list *stack);
int		check_args(int argc, char *string);
int		check_doubles(t_list *stack, long entry);
t_list	*list_init(long nbr);
void	free_list(t_list *liste);
void	afficherListe(t_list *liste);
void	insert_befor(t_list *liste, long nbr);
void	check_max(long entry, t_list *liste);
void	check_entry(t_list *stack, long entry);
void	check_nbr(char *nbr, t_list *stack);
void	rotate(t_list *stack, char *move);
void	rotate_reverse(t_list *stack, char *move);
void    stock_stack_infos(t_list **stack);
t_pivot *make_pivot(t_list *stack);
void	algo_pivot_push(t_list **stack_a, t_list **stack_b);
int		is_smaller(int nbr, int pivot);
void	bubble_sort_a(t_list **stack, int size);
int		is_bigger(int nbr, int pivot);
void    algo_pivot_back(t_list **stack_a, t_list **stack_b);
int		heart(t_list ***a, t_list ***b, t_pivot	*pivot, int size);
int		heart_r(t_list ***a, t_list ***b, t_pivot *pivot, int size);
void	is_smaller_algo(t_list ***stack_a, t_list ***stack_b);
void	is_bigger_algo(t_list ***stack_a, t_list ***stack_b);
void	algo_three(t_list **stack);
void	algo_five(t_list **stack_a, t_list **stack_b);

#endif
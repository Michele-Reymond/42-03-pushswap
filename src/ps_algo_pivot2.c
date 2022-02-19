/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algo_pivot2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:02:01 by mreymond          #+#    #+#             */
/*   Updated: 2022/02/19 13:09:12 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_order(t_list *stack, int nbr_to_check)
{
	t_nbr	*li_next;
	t_nbr	*li_pos;
    int     i;

    i = 0;
	li_pos = stack->first;
	li_next = li_pos->next;
	while (i < nbr_to_check - 1)
	{
		if (li_pos->number > li_next->number)
			return (0);
		li_pos = li_pos->next;
		li_next = li_pos->next;
        i++;
	}
	return (1);
}

int	check_order_reverse(t_list *stack, int nbr_to_check)
{
	t_nbr	*li_next;
	t_nbr	*li_pos;
    int     i;

    i = 0;
	li_pos = stack->first;
	li_next = li_pos->next;
	while (i < nbr_to_check - 1)
	{
		if (li_pos->number < li_next->number)
			return (0);
		li_pos = li_pos->next;
		li_next = li_pos->next;
        i++;
	}
	return (1);
}

char *algo_bubble_opti_sort(t_list **stack, char *moves)
{
    int i;
    int size;
    char *new_moves;
    char *new_moves_rr;
    char *new_moves_bubble;
  
    size = (*stack)->size - 1;
    while (check_order(*stack, (*stack)->size) == 0)
    {
        i = 0;
        while (i < size)
        {
            new_moves_bubble = bubble_sort(*stack, SA, moves);
            new_moves = rotate(*stack, RA, new_moves_bubble);
            moves = new_moves;
            i++;
        }
        i = size;
        while (i > 0)
        {
            new_moves_rr = rotate_reverse(*stack, RRA, moves);
            moves = new_moves_rr;
            i--;
        }
        size--;
    } 
    return (moves);
}

char *algo_bubble_opti_sort_reverse(t_list **stack_a, t_list **stack_b, int size, char *moves)
{
    int i;
    char *new_moves_b;
    char *new_moves_a;
    char *new_moves_rr_b;
    char *new_moves_rr_a;
    char *new_moves_bubble_b;
    char *new_moves_bubble_a;

    // while (check_order_reverse(*stack_b, (*stack_b)->size) == 0)
    // {
        i = 0;
        while (i < size)
        {
            new_moves_bubble_b = bubble_sort_big(*stack_b, SB, moves);
            new_moves_bubble_a = bubble_sort(*stack_a, SA, new_moves_bubble_b);
            new_moves_b = rotate(*stack_b, RB, new_moves_bubble_a);     
            new_moves_a = rotate(*stack_a, RA, new_moves_b);
            moves = new_moves_a;   
            i++;
        }
        i = size;
        while (i > 0)
        {
            new_moves_rr_b = rotate_reverse(*stack_b, RRB, moves);
            new_moves_rr_a = rotate_reverse(*stack_a, RRA, new_moves_rr_b);
            moves = new_moves_rr_a;
            i--;
        }
        size--;
    // } 
    return (new_moves_rr_a);
}
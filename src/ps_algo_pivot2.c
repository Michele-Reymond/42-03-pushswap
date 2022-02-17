/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algo_pivot2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:02:01 by mreymond          #+#    #+#             */
/*   Updated: 2022/02/17 19:27:01 by mreymond         ###   ########.fr       */
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

void algo_bubble_opti_sort(t_list **stack)
{
    int i;
    int size;
  
    size = (*stack)->size - 1;
    while (check_order(*stack, (*stack)->size) == 0)
    {
        i = 0;
        while (i < size)
        {
            bubble_sort(*stack, SA);
            rotate(*stack, RA);
            i++;
        }
        i = size;
        while (i > 0)
        {
            rotate_reverse(*stack, RRA);
            i--;
        }
        size--;
    } 
}

void algo_bubble_opti_sort_reverse(t_list **stack_a, t_list **stack_b, int size)
{
    int i;

    while (check_order_reverse(*stack_b, (*stack_b)->size) == 0)
    {
        i = 0;
        while (i < size)
        {
            bubble_sort_big(*stack_b, SB);
            bubble_sort(*stack_a, SA);
            rotate(*stack_b, RB);
            rotate(*stack_a, RA);
            i++;
        }
        i = size;
        while (i > 0)
        {
            rotate_reverse(*stack_b, RRB);
            rotate_reverse(*stack_a, RRA);
            i--;
        }
        size--;
    } 
}
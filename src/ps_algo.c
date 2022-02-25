/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 21:33:14 by mreymond          #+#    #+#             */
/*   Updated: 2022/02/25 10:38:41 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_pivot_push(t_list **stack_a, t_list **stack_b)
{
	t_pivot	*pivot;
	int		pushed_small;
	int		i;

	pivot = make_pivot(*stack_a);
	heart_r(&stack_a, &stack_b, pivot, (*stack_a)->size);
	pivot->low = pivot->high + (pivot->add / 2); 
	pivot->high = pivot->high + pivot->add;
	while (pivot->high < (*stack_a)->biggest)
	{
		i = -1;
		pushed_small = heart(&stack_a, &stack_b, pivot, (*stack_a)->size);
		while (++i < pushed_small && (*stack_b)->size > 4)
			rotate_reverse(*stack_b, RRB);
		pivot->low = pivot->high + (pivot->add / 2); 
		pivot->high = pivot->high + pivot->add;
	}
	free(pivot);
}

void    algo_pivot_back(t_list **stack_a, t_list **stack_b)
{
	bubble_sort_a(stack_a, (*stack_a)->size);
	while ((*stack_b)->size > 0)
	{
		stock_stack_infos(stack_b);
		stock_stack_infos(stack_a);
		if ((*stack_b)->first->number < (*stack_a)->first->number)
			is_smaller_algo(&stack_a, &stack_b);
		else if ((*stack_b)->first->number > (*stack_a)->first->number)
			is_bigger_algo(&stack_a, &stack_b);
	}
	while ((*stack_a)->last != (*stack_a)->biggest)
	{
		rotate_reverse(*stack_a, RRA);
		stock_stack_infos(stack_a);
	}
}

void algo_three(t_list **stack)
{
	if ((*stack)->last == (*stack)->biggest)
        bubble_sort(*stack, SA);
	else if ((*stack)->first->number == (*stack)->biggest)
	{
		rotate(*stack, RA);
        bubble_sort(*stack, SA);
	}
	else
	{
		rotate_reverse(*stack, RRA);
        bubble_sort(*stack, SA);
	}
}

void algo_five(t_list **stack_a, t_list **stack_b)
{
	int i;

	i = -1;
	while (++i < 2)
	{
		if ((*stack_a)->first->next->number == (*stack_a)->smallest)
			rotate(*stack_a, RA);
		else {
			while ((*stack_a)->first->number != (*stack_a)->smallest)
				rotate_reverse(*stack_a, RRA);
		}
		if (check_order(*stack_a, (*stack_a)->size) && (*stack_b) == NULL)
			return;
		push(*stack_a, stack_b, PB);
		stock_stack_infos(stack_a);
	}
	algo_three(stack_a);
	push(*stack_b, stack_a, PA);
	push(*stack_b, stack_a, PA);
}
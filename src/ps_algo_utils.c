/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algo_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:02:01 by mreymond          #+#    #+#             */
/*   Updated: 2022/02/25 10:06:40 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int heart_r(t_list ***a, t_list ***b, t_pivot *pivot, int size)
{
	int		i;
	int		pushed_back;

	i = 0;
	pushed_back = 0;
	while (i <= size && pivot_is_in_stack(**a, pivot->high))
	{
		if (is_smaller((**a)->first->number, pivot->high))
		{
			push(**a, *b, PB);
			if ((**b) && is_smaller((**b)->first->number, pivot->low))
			{
				rotate(**b, RB);
				pushed_back++;
			}
		}
		else
			rotate(**a, RA);
		i++;
	}
	return (pushed_back);
}

int heart(t_list ***a, t_list ***b, t_pivot	*pivot, int size)
{
	int		i;
	int		pushed_back;

	i = 0;
	pushed_back = 0;
	while (i <= size && pivot_is_in_stack(**a, pivot->high))
	{
		if (is_smaller((**a)->first->number, pivot->high))
		{
			push(**a, *b, PB);
			if ((**b) && is_bigger((**b)->first->number, pivot->low))
			{
				rotate(**b, RB);
				pushed_back++;
			}
		}
		else
			rotate(**a, RA);
		i++;
	}
	return (pushed_back);
}

void is_smaller_algo(t_list ***stack_a, t_list ***stack_b)
{
	while ((**stack_b)->first->number < (**stack_a)->first->number && 
		(**stack_b)->first->number < (**stack_a)->last && 
		(**stack_a)->last != (**stack_a)->biggest) 
	{
		rotate_reverse(**stack_a, RRA);
		stock_stack_infos(*stack_a);
	}
	push(**stack_b, *stack_a, PA);
}

void is_bigger_algo(t_list ***stack_a, t_list ***stack_b)
{
	if ((**stack_b)->first->number > (**stack_a)->biggest)
	{
		while ((**stack_b)->first->number != (**stack_a)->biggest)
		{
			rotate(**stack_a, RA);
			stock_stack_infos(*stack_a);
		}
	}
	else
	{
		while ((**stack_b)->first->number > (**stack_a)->first->number && 
		(**stack_b)->first->number < (**stack_a)->biggest) 
		{
			rotate(**stack_a, RA);
			stock_stack_infos(*stack_a);
		}
	}
	push(**stack_b, *stack_a, PA);
}
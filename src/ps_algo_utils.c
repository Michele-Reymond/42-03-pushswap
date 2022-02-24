/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algo_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:02:01 by mreymond          #+#    #+#             */
/*   Updated: 2022/02/25 00:16:09 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int heart_reverse(t_list ***stack_a, t_list ***stack_b, 
    t_pivot	*pivot, int size, char *moves)
{
	int		i;
	int		pushed_back;

	i = 0;
	pushed_back = 0;
	while (i <= size && pivot_is_in_stack(**stack_a, pivot->high))
	{
		if (is_smaller((**stack_a)->first->number, pivot->high))
		{
			moves = push(**stack_a, *stack_b, PB, moves);
			if ((**stack_b) && is_smaller((**stack_b)->first->number, pivot->low))
			{
				moves = rotate(**stack_b, RB, moves);
				pushed_back++;
			}
		}
		else
			moves = rotate(**stack_a, RA, moves);
		i++;
	}
	printf("%s", moves);
    free(moves);
    moves = NULL;
	return (pushed_back);
}

int heart(t_list ***stack_a, t_list ***stack_b, 
    t_pivot	*pivot, int size, char *moves)
{
	int		i;
	int		pushed_back;

	i = 0;
	pushed_back = 0;
	while (i <= size && pivot_is_in_stack(**stack_a, pivot->high))
	{
		if (is_smaller((**stack_a)->first->number, pivot->high))
		{
			moves = push(**stack_a, *stack_b, PB, moves);
			if ((**stack_b) && is_bigger((**stack_b)->first->number, pivot->low))
			{
				moves = rotate(**stack_b, RB, moves);
				pushed_back++;
			}
		}
		else
			moves = rotate(*(*stack_a), RA, moves);
		i++;
	}
	printf("%s", moves);
    free(moves);
    moves = NULL;
	return (pushed_back);
}

void is_smaller_algo(t_list ***stack_a, t_list ***stack_b)
{
    char *moves;

    moves = ft_strdup("");
	while ((**stack_b)->first->number < (**stack_a)->first->number && 
		(**stack_b)->first->number < (**stack_a)->last && 
		(**stack_a)->last != (**stack_a)->biggest) 
	{
		rotate_reverse(**stack_a, RRA);
		stock_stack_infos(*stack_a);
	}
	push(**stack_b, *stack_a, PA, moves);
	printf("%s\n", "pa");
	free(moves);
}

void is_bigger_algo(t_list ***stack_a, t_list ***stack_b)
{
    char *moves;

    moves = ft_strdup("");
	if ((**stack_b)->first->number > (**stack_a)->biggest)
	{
		while ((**stack_b)->first->number != (**stack_a)->biggest)
		{
			rotate(**stack_a, RA, moves);
			printf("%s\n", "ra");
			stock_stack_infos(*stack_a);
		}
	}
	else
	{
		while ((**stack_b)->first->number > (**stack_a)->first->number && 
		(**stack_b)->first->number < (**stack_a)->biggest) 
		{
			rotate(**stack_a, RA, moves);
			printf("%s\n", "ra");
			stock_stack_infos(*stack_a);
		}
	}
	push(**stack_b, *stack_a, PA, moves);
	printf("%s\n", "pa");
	free(moves);
}
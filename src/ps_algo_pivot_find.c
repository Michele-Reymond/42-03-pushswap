/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algo_pivot_find.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 21:34:36 by mreymond          #+#    #+#             */
/*   Updated: 2022/02/24 21:35:35 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int pivot_is_in_stack(t_list *stack_a, int pivot)
{
    t_nbr *a;
    int i;

    a = stack_a->first;
    i = 0;
    while (a->next != NULL)
    {
        if (a->number <= pivot)
            i++;
        a = a->next;
    }
    if (a->number <= pivot)
        i++;
    if (i > 0)
        return (1);
    return (0);
}

t_pivot *make_middle_pivot(t_pivot *pivot, t_list *stack)
{
	pivot->high = stack->smallest + 2;
	pivot->low = stack->smallest + 1;
	pivot->add = 2;
	return (pivot);
}

t_pivot *make_pivot(t_list *stack)
{
	t_pivot *pivot;

	pivot = malloc(sizeof(t_pivot *));
	if (stack->size > 5 && stack->size <= 20)
		pivot = make_middle_pivot(pivot, stack);
	else if (stack->size > 20 && stack->size <= 350)
	{
		pivot->high = stack->smallest + 16;
		pivot->low = stack->smallest + 8;
		pivot->add = 16;
	}
	else if (stack->size > 350 && stack->size <= 550)
	{
		pivot->high = stack->smallest + 70;
		pivot->low = stack->smallest + 35;
		pivot->add = 70;
	}
	else
	{
		pivot->high = stack->smallest + 100;
		pivot->low = stack->smallest + 50;
		pivot->add = 100;
	}
	return (pivot);
}

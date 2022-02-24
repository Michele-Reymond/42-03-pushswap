/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algo_pivot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 09:33:56 by mreymond          #+#    #+#             */
/*   Updated: 2022/02/24 21:38:18 by mreymond         ###   ########.fr       */
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

int is_smaller(int nbr, int pivot)
{
    if (nbr <= pivot)
        return (1);
    else
        return (0);
}

int is_bigger(int nbr, int pivot)
{
    if (nbr > pivot)
        return (1);
    else
        return (0);
}

void    stock_stack_infos(t_list **stack)
{
	t_nbr *actual;

	actual = (*stack)->first;
	(*stack)->first_n = actual->number;
	(*stack)->smallest = actual->number;
	(*stack)->biggest = actual->number;
	(*stack)->somme = 0;
	while (actual->next != NULL)
	{
			if ((*stack)->smallest > actual->number)
				(*stack)->smallest = actual->number;
			if ((*stack)->biggest < actual->number)
				(*stack)->biggest = actual->number;
			(*stack)->somme = (*stack)->somme + actual->number;
			actual = actual->next;
	}
	if ((*stack)->smallest > actual->number)
		(*stack)->smallest = actual->number;
	if ((*stack)->biggest < actual->number)
		(*stack)->biggest = actual->number;
	(*stack)->somme = (*stack)->somme + actual->number;
	(*stack)->last = actual->number;
}

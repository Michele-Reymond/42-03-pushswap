/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algo_bubble.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:41:22 by mreymond          #+#    #+#             */
/*   Updated: 2022/02/16 17:54:47 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(t_list *stack, char *move)
{
	t_nbr	*li_next;
	t_nbr	*li_pos;

	li_pos = stack->first;
	li_next = li_pos->next;
	if (li_next->number < li_pos->number)
		swap(stack, move);
}

void	bubble_sort_big(t_list *stack, char *move)
{
	t_nbr	*li_next;
	t_nbr	*li_pos;

	li_pos = stack->first;
	li_next = li_pos->next;
	if (li_next->number > li_pos->number)
		swap(stack, move);
}

// void	bubble_sort(t_list *stack)
// {
// 	t_nbr	*li_last;
// 	t_nbr	*li_pos;

// 	li_last = find_last(stack);
// 	li_pos = stack->first;
// 	while (li_pos->next->next != NULL)
// 		li_pos = li_pos->next;
// 	if (li_last->number < li_pos->number)
// 		swap(stack);
// }

int	bubble_loop(t_list *stack)
{
	t_nbr	*li_next;
	t_nbr	*li_pos;

	li_pos = stack->first;
	li_next = li_pos->next;
	while (li_pos->next != NULL)
	{
		if (li_pos->number < li_next->number)
			return (0);
		li_pos = li_pos->next;
		li_next = li_pos->next;
	}
	return (1);
}

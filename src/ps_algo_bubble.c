/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algo_bubble.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:41:22 by mreymond          #+#    #+#             */
/*   Updated: 2022/02/25 09:57:49 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// si next est plus petit swap
void	bubble_sort(t_list *stack, char *move)
{
	t_nbr	*li_next;
	t_nbr	*li_pos;

	li_pos = stack->first;
	li_next = li_pos->next;
	if (stack->first == NULL || li_pos->next == NULL)
		return ;
	if (li_next->number < li_pos->number)
		swap(stack, move);
}

// si next est plus grand swap
void	bubble_sort_big(t_list *stack, char *move)
{
	t_nbr	*li_next;
	t_nbr	*li_pos;
	
	li_pos = stack->first;
	li_next = li_pos->next;
	if (stack->first == NULL || li_pos->next == NULL)
		return ;
	if (li_next->number > li_pos->number)
		swap(stack, move);
}

void bubble_sort_a(t_list **stack, int size)
{
	int i;

	i = 0;
	size = (*stack)->size - 1;
	while (check_order(*stack, size + 1) == 0)
	{
		i = 0;
		while (i < size)
		{
			bubble_sort(*stack, SA);
			rotate(*stack, RA);
			i++;
		}
		i = 0;
		while (i < size)
		{
			rotate_reverse(*stack, RRA);
			bubble_sort(*stack, SA);
			i++;
		}
		size--;
	}
}

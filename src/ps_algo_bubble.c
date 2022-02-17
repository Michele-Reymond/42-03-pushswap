/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algo_bubble.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:41:22 by mreymond          #+#    #+#             */
/*   Updated: 2022/02/17 11:06:37 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_algo_pas_opti(t_list *stack_a, t_list *stack_b)
{
	int i;

	i = 0;
	while (stack_a->size / 2 >= i)
	{
		push(stack_a, &stack_b, PB);
		i++;
	}
	while (bubble_loop(stack_a) == 0)
	{
		bubble_sort(stack_a, SA);
		if (bubble_loop(stack_a) == 0)
			rotate(stack_a, RA);
	}
	while (bubble_loop(stack_b) == 0)
	{
		bubble_sort(stack_b, SB);
		if (bubble_loop(stack_b) == 0)
			rotate(stack_b, RB);
	}
	while (stack_a->size > 0)
	{
		push(stack_a, &stack_b, PB);
		i++;
	}
	while (bubble_loop(stack_b) == 0)
	{
		bubble_sort_big(stack_b, SB);
		if (bubble_loop(stack_b) == 0)
			rotate_reverse(stack_b, RRB);
	}
	while (stack_b->size > 0)
	{
		push(stack_b, &stack_a, PA);
		i++;
	}
}

// si next est plus petit swap
void	bubble_sort(t_list *stack, char *move)
{
	t_nbr	*li_next;
	t_nbr	*li_pos;

	li_pos = stack->first;
	li_next = li_pos->next;
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

// 1, 3, 5, 8
// du plus petit au plus grand
int	bubble_loop(t_list *stack)
{
	t_nbr	*li_next;
	t_nbr	*li_pos;

	li_pos = stack->first;
	li_next = li_pos->next;
	while (li_pos->next != NULL)
	{
		if (li_pos->number > li_next->number)
			return (0);
		li_pos = li_pos->next;
		li_next = li_pos->next;
	}
	return (1);
}

// 8, 5, 3, 1
// du plus grand au plus petit
int	bubble_loop_reverse(t_list *stack)
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

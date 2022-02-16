/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:01:05 by mreymond          #+#    #+#             */
/*   Updated: 2022/02/16 17:51:53 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	swap(t_list *stack)
// {
// 	int		i;
// 	int		tmp;
// 	t_nbr	*li_cursor;
// 	t_nbr	*li_last;

// 	i = 2;
// 	li_cursor = stack->first;
// 	li_last = find_last(stack);
// 	while (i < stack->size)
// 	{
// 		li_cursor = li_cursor->next;
// 		i++;
// 	}
// 	tmp = li_cursor->number;
// 	li_cursor->number = li_last->number;
// 	li_last->number = tmp;
// }

void	swap(t_list *stack, char *move)
{
	int		i;
	int		tmp;
	t_nbr	*li_pos;
	t_nbr	*li_next;

	i = 2;
	li_pos = stack->first;
	li_next = li_pos->next;
	tmp = li_pos->number;
	li_pos->number = li_next->number;
	li_next->number = tmp;
	printf("%s\n", move);
}

// sa : swap a - swap the first 2 elements at the top of stack a. 
// Do nothing if there is only one or no elements).
// sb : swap b - swap the first 2 elements at the top of stack b. 
// Do nothing if there is only one or no elements).
// ss : sa and sb at the same time.
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:01:05 by mreymond          #+#    #+#             */
/*   Updated: 2022/02/19 15:30:24 by mreymond         ###   ########.fr       */
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

char	*swap(t_list *stack, char *move, char *moves)
{
	int		i;
	int		tmp;
	t_nbr	*li_pos;
	t_nbr	*li_next;
	char	*new_moves;

	i = ft_strlen(moves);
	li_pos = stack->first;
	li_next = li_pos->next;
	tmp = li_pos->number;
	li_pos->number = li_next->number;
	li_next->number = tmp;
	if (ft_strnstr(move, "sa", 2))
	{
		if (moves[i - 2] == 'b' && moves[i - 3] == 's')
		{
			new_moves = ft_strdup(moves);
			new_moves[i - 2] = 's';
		}
		else
			new_moves = ft_strjoin(moves, "sa\n");
	}
	else
	{
		if (moves[i - 2] == 'a' && moves[i - 3] == 's')
		{
			new_moves = ft_strdup(moves);
			new_moves[i - 2] = 's';
		}
		else
			new_moves = ft_strjoin(moves, "sb\n");
	}
	// printf("%s\n", move);
	return (new_moves);
}

// sa : swap a - swap the first 2 elements at the top of stack a. 
// Do nothing if there is only one or no elements).
// sb : swap b - swap the first 2 elements at the top of stack b. 
// Do nothing if there is only one or no elements).
// ss : sa and sb at the same time.
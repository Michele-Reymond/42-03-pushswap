/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:01:09 by mreymond          #+#    #+#             */
/*   Updated: 2022/02/19 14:45:03 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// >>>>>>
char	*rotate_reverse(t_list *stack, char *move, char *moves)
{
	t_nbr	*li_last;
	t_nbr	*li_pos;
	int		tmp;
	int		tmp2;
	char	*new_moves;
	int 	i;

	i = ft_strlen(moves);
	li_last = find_last(stack);
	li_pos = stack->first;
	tmp2 = li_last->number;
	while (li_pos != NULL)
	{
		tmp = li_pos->number;
		li_pos->number = tmp2;
		tmp2 = tmp;
		li_pos = li_pos->next;
	}
	if (ft_strnstr(move, "rra", 3))
	{
		if (moves[i - 2] == 'b' && moves[i - 3] == 'r' && moves[i - 4] == 'r')
		{
			new_moves = ft_strdup(moves);
			new_moves[i - 2] = 'r';
		}
		else
			new_moves = ft_strjoin(moves, "rra\n");
	}
	else
	{
		if (moves[i - 2] == 'a' && moves[i - 3] == 'r' && moves[i - 4] == 'r')
		{
			new_moves = ft_strdup(moves);
			new_moves[i - 2] = 'r';
		}
		else
			new_moves = ft_strjoin(moves, "rrb\n");
	}
	// printf("%s\n", move);
	return (new_moves);
}

// <<<<<
char	*rotate(t_list *stack, char *move, char *moves)
{
	t_nbr	*li_last;
	t_nbr	*li_pos;
	t_nbr	*li_next;
	int		tmp;
	int		i;
	char	*new_moves;

	i = ft_strlen(moves);
	li_last = find_last(stack);
	li_pos = stack->first;
	while (li_pos->next != NULL)
	{
		li_next = li_pos->next;
		tmp = li_pos->number;
		li_pos->number = li_next->number;
		li_next->number = tmp;
		li_pos = li_pos->next;
	}
	if (ft_strnstr(move, "ra", 2))
	{
		if (moves[i - 2] == 'b' && moves[i - 3] == 'r' && moves[i - 1] == '\n')
		{
			new_moves = ft_strdup(moves);
			new_moves[i - 2] = 'r';
		}
		else
			new_moves = ft_strjoin(moves, "ra\n");
	}
	else
	{
		if (moves[i - 2] == 'a' && moves[i - 3] == 'r' && moves[i - 1] == '\n')
		{
			new_moves = ft_strdup(moves);
			new_moves[i - 2] = 'r';
		}
		else
			new_moves = ft_strjoin(moves, "rb\n");
	}
	// printf("%s\n", move);
	return (new_moves);
}

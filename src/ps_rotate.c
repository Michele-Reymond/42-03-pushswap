/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:01:09 by mreymond          #+#    #+#             */
/*   Updated: 2022/02/25 09:51:25 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// >>>>>>
void	rotate_reverse(t_list *stack, char *move)
{
	t_nbr	*li_last;
	t_nbr	*li_pos;
	int		tmp;
	int		tmp2;

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
	printf("%s\n", move);
}

// <<<<<
void	rotate(t_list *stack, char *move)
{
	t_nbr	*li_last;
	t_nbr	*li_pos;
	t_nbr	*li_next;
	int		tmp;

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
	printf("%s\n", move);
}

// char	*rotate(t_list *stack, char *move, char *moves)
// {
// 	int		len;

// 	len = ft_strlen(moves);
// 	make_rotation(&stack);
// 	if (ft_strnstr(move, "ra", 2))
// 	{
// 		if (moves[len - 2] == 'b' && moves[len - 3] == 'r' && 
// 			moves[len - 1] == '\n')
// 			moves[len - 2] = 'r';
// 		else
// 			moves = ft_strjoin(moves, "ra\n");
// 	}
// 	else
// 	{
// 		if (moves[len - 2] == 'a' && moves[len - 3] == 'r' 
// 			&& moves[len - 1] == '\n')
// 			moves[len - 2] = 'r';
// 		else
// 			moves = ft_strjoin(moves, "rb\n");
// 	}
// 	return (moves);
// }

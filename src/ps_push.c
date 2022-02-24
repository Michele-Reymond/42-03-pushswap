/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:01:17 by mreymond          #+#    #+#             */
/*   Updated: 2022/02/25 00:10:55 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*push(t_list *src_stack, t_list **dst_stack, 
	char *move, char *moves)
{
	int		nbr;
	char	*new_moves;
	t_nbr	*li_first;

	li_first = src_stack->first;
	nbr = li_first->number;
	delete_first(src_stack);
	if (*dst_stack == NULL)
		*dst_stack = list_init(nbr);
	else
		insert_befor(*dst_stack, nbr);
	if (ft_strnstr(move, "pa", 2))
		new_moves = ft_strjoin(moves, "pa\n");
	else
		new_moves = ft_strjoin(moves, "pb\n");
	return (new_moves);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:01:17 by mreymond          #+#    #+#             */
/*   Updated: 2022/02/25 11:17:43 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list *src_stack, t_list **dst_stack, char *move)
{
	int		nbr;
	t_nbr	*li_first;

	li_first = src_stack->first;
	nbr = li_first->number;
	delete_first(src_stack);
	if (*dst_stack == NULL)
		*dst_stack = list_init(nbr);
	else
		insert_befor(*dst_stack, nbr);
	write(1, &move[0], 1);
	write(1, &move[1], 1);
	write(1, "\n", 1);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:01:05 by mreymond          #+#    #+#             */
/*   Updated: 2022/02/24 22:15:09 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list *stack, char *move)
{
	int		tmp;
	t_nbr	*li_pos;
	t_nbr	*li_next;

	li_pos = stack->first;
	li_next = li_pos->next;
	tmp = li_pos->number;
	li_pos->number = li_next->number;
	li_next->number = tmp;
	printf("%s\n", move);
}
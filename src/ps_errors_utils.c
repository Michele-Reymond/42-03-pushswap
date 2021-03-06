/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_errors_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 10:49:12 by mreymond          #+#    #+#             */
/*   Updated: 2022/02/25 11:21:56 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void check_begin_order(t_list *stack)
{
	if (check_order(stack, stack->size))
	{
		write(1, "La liste n'a pas besoin d'être triée\n", 37);
		free_list(stack);
	    free(stack);
		exit(0);
	}
}

int	check_doubles(t_list *stack, long entry)
{
	t_nbr	*list_pos;

	list_pos = stack->first;
	while (list_pos != NULL)
	{
		if (list_pos->number == entry)
			return (0);
		list_pos = list_pos->next;
	}
	return (1);
}

void	check_max(long entry, t_list *stack)
{
	if (!(entry >= INT_MIN && entry <= INT_MAX))
	{
		write(1, "Error\nUn des nombres n'est pas un integre!\n", 43);
		free_list(stack);
	    free(stack);
		exit(0);
	}
}

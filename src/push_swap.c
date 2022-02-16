/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:05:43 by mreymond          #+#    #+#             */
/*   Updated: 2022/02/16 17:58:59 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		i;

	i = 0;
	stack_b = NULL;
	if (check_args(argc, argv[1]))
		stack_a = stock_string(argv);
	else
		stack_a = stock_args(argc, argv, 1);
	// afficherListe(stack_a);
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
	// afficherListe(stack_a);
	free_list(stack_a);
	free_list(stack_b);
	return (0);
}

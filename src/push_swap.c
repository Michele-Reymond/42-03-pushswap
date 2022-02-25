/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:05:43 by mreymond          #+#    #+#             */
/*   Updated: 2022/02/25 10:47:09 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_b = NULL;
	if (check_args(argc, argv[1]))
		stack_a = stock_string(argv);
	else
		stack_a = stock_args(argc, argv, 1);
	stock_stack_infos(&stack_a);
	if (stack_a->size <= 3)
		algo_three(&stack_a);
	else if (stack_a->size > 3 && stack_a->size <= 5)
		algo_five(&stack_a, &stack_b);
	else
	{
		algo_pivot_push(&stack_a, &stack_b);
		algo_pivot_back(&stack_a, &stack_b);
	}
	free_list(stack_a);
	free(stack_a);
	free(stack_b);
	return (0);
}

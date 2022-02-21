/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:05:43 by mreymond          #+#    #+#             */
/*   Updated: 2022/02/21 23:19:51 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	// char	*moves;

	stack_b = NULL;
	if (check_args(argc, argv[1]))
		stack_a = stock_string(argv);
	else
		stack_a = stock_args(argc, argv, 1);
		
	// printf("A: ");
	// afficherListe(stack_a);
	// printf("B: ");
	// afficherListe(stack_b);

	// moves = algo_pivot_sort(&stack_a, &stack_b);
	// printf("char: %s", moves);
	stock_stack_infos(&stack_a);
	// algo_pivot_big(&stack_a, &stack_b);
	while (stack_a->first != NULL)
        push(stack_a, &stack_b, PB, "");
	algo_lolo(&stack_a, &stack_b);
	
	printf("A: ");
	afficherListe(stack_a);
	printf("B: ");
	afficherListe(stack_b);

	// free(moves);
	free_list(stack_a);
	free_list(stack_b);
	return (0);
}

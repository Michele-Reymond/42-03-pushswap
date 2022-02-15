/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:05:43 by mreymond          #+#    #+#             */
/*   Updated: 2022/02/15 15:49:37 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void afficherListe(t_list *liste)
{
    if (liste == NULL)
    {
        exit(0);
    }

    t_nbr *actuel = liste->first;

    while (actuel != NULL)
    {
        printf("%d -> ", actuel->number);
        actuel = actuel->next;
    }
    printf("NULL\n");
}

int	main(int argc, char **argv)
{
	t_list *stack_a;

	if (check_args(argc, argv[1]))
			stack_a = stock_string(argv);
	else
			stack_a = stock_args(argc, argv, 1);
	afficherListe(stack_a);
	// stack.b = (int *)malloc(sizeof(int) * stack.size_a);
	// free_stack(&stack);
	return (0);
}

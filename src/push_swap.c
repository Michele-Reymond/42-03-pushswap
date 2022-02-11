/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:05:43 by mreymond          #+#    #+#             */
/*   Updated: 2022/02/11 20:08:22 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void check_entry(char *stack, int pos)
// {
// 	// 1. c'est un nbr
// 	// 2. est un intègre
// 	// 3. n'est pas un doublon
// }

int *stock_args(int count, char **arguments)
{
	int		*stack;
	int		i;
	int		j;
	int		entry;
	
	i = 0;
	j = 1;
	stack = (int *)malloc(sizeof(int) * (count - 1) + 1);
	if (stack == NULL)
		return (0);
	while (j < count)
	{
		entry = ft_atoi(arguments[j]);
		// check_entry(stack, i);
		stack[i] = entry;
		i++;
		j++;
	}
	stack[i] = '\0';
	return (stack);
}

int	main(int argc, char **argv)
{
	int	*stack_a = NULL;

	(void)argv;
	if (argc < 2)
	{
		printf("nop!");
		return (0);
	}
	stack_a = stock_args(argc, argv);
	printf("print: %d\n", stack_a[0]);
	free(stack_a);
	return (0);
}

// checker chaque nombre si c'est un nombre et si il est un integer et si il n'est pas déjà apparu
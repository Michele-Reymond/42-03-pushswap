/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:05:43 by mreymond          #+#    #+#             */
/*   Updated: 2022/02/15 14:09:53 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_tabs stack;

	if (check_args(argc, argv[1]))
			stack.a = stock_string(argv);
	else
			stack.a = stock_args(argc, argv, 1);
	stack.b = (int *)malloc(sizeof(int) * stack.size_a);
	free_stack(&stack);
	return (0);
}

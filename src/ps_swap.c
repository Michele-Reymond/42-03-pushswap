/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:01:05 by mreymond          #+#    #+#             */
/*   Updated: 2022/02/14 19:00:46 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(int *stack)
{
    int tmp;

    tmp = stack[0];
    stack[0] = stack[1];
    stack[1] = tmp;
}

void what_to_swap(int *stack_a, int *stack_b, char *move)
{
    if (ft_strnstr(move, SA, 2))
    {
        swap(stack_a);
        printf("%s\n", SA);
    }
    else if (ft_strnstr(move, SB, 2))
    {
        swap(stack_b);
        printf("%s\n", SB);
    }
    else if (ft_strnstr(move, SS, 2))
    {
        swap(stack_b);
        swap(stack_a);
        printf("%s\n", SS);
    }
}

// sa : swap a - swap the first 2 elements at the top of stack a. 
// Do nothing if there is only one or no elements).
// sb : swap b - swap the first 2 elements at the top of stack b. 
// Do nothing if there is only one or no elements).
// ss : sa and sb at the same time.
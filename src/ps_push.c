/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:01:17 by mreymond          #+#    #+#             */
/*   Updated: 2022/02/15 12:07:52 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void push(t_tabs *stack, char *move)
// {
// }

void what_to_push(t_tabs *stack, char *move)
{
    int i;
    int j;

    i = stack->size_a - 1;
    j = stack->size_b - 1;
    if (ft_strnstr(move, PA, 2))
    {
        while(i >= 0)
        {
            if (!stack->a[i])
                stack->a[i] = stack->b[j];
            i--;
        }
        printf("%s\n", PA);
    }
    else if (ft_strnstr(move, PB, 2))
    {
        // push(&stack, move);
        printf("%s\n", PB);
    }
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:01:17 by mreymond          #+#    #+#             */
/*   Updated: 2022/02/14 19:06:20 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push(int *src_stack, int *dst_stack)
{
    
}

void what_to_push(int *stack_a, int *stack_b, char *move)
{
    if (ft_strnstr(move, PA, 2))
    {
        push(stack_b, stack_a);
        printf("%s\n", PA);
    }
    else if (ft_strnstr(move, PB, 2))
    {
        push(stack_a, stack_b);
        printf("%s\n", PB);
    }
}
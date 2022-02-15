/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:01:05 by mreymond          #+#    #+#             */
/*   Updated: 2022/02/15 17:00:14 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_list *stack)
{
    int i;
    int tmp;
    t_nbr *li_cursor;
    t_nbr *li_last;

    i = 2;
    li_cursor = stack->first;
    li_last = stack->first;
    while (i < stack->size)
    {
        li_cursor = li_cursor->next;
        i++;
    }
    i = 1;
    while (i < stack->size)
    {
        li_last = li_last->next;
        i++;
    }
    tmp = li_cursor->number;
    li_cursor->number = li_last->number;
    li_last->number = tmp;
}

// sa : swap a - swap the first 2 elements at the top of stack a. 
// Do nothing if there is only one or no elements).
// sb : swap b - swap the first 2 elements at the top of stack b. 
// Do nothing if there is only one or no elements).
// ss : sa and sb at the same time.
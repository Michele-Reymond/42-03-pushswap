/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:01:17 by mreymond          #+#    #+#             */
/*   Updated: 2022/02/15 18:13:05 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_nbr *find_last(t_list *stack)
{
    int i;
    t_nbr *li_last;

    i = 1;
    li_last = stack->first;
    while (i < stack->size)
    {
        li_last = li_last->next;
        i++;
    }
    return (li_last);
}

void push(t_list *src_stack, t_list **dst_stack)
{
    int nbr;
    t_nbr *li_last;

    li_last = find_last(src_stack);
    nbr = li_last->number;
    delete_last(src_stack);
    if (*dst_stack == NULL)
        *dst_stack = list_init(nbr);
    else
        insert_after(*dst_stack, nbr);
}

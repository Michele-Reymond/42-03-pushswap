/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algo_pivot2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:02:01 by mreymond          #+#    #+#             */
/*   Updated: 2022/02/17 15:51:01 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_order(t_list *stack, int nbr_to_check)
{
	t_nbr	*li_next;
	t_nbr	*li_pos;
    int     i;

    i = 0;
	li_pos = stack->first;
	li_next = li_pos->next;
	while (i < nbr_to_check - 1)
	{
		if (li_pos->number > li_next->number)
			return (0);
		li_pos = li_pos->next;
		li_next = li_pos->next;
        i++;
	}
	return (1);
}


void algo_bubble_opti_sort(t_list **stack)
{
    int quart;
    int demi;
    int tree_quarter;
    int i;

    quart = (*stack)->size / 4;
    demi = (*stack)->size / 2;
    tree_quarter = quart + demi;
    while (check_order(*stack, quart) == 0)
    {
        i = 0;
        while (i < quart)
        {
            bubble_sort(*stack, SA);
            rotate(*stack, RA);
            i++;
        }
        while (i > 0)
        {
            rotate_reverse(*stack, RRA);
            i--;
        }
    }
    while (i < quart)
    {
        rotate(*stack, RA);
        i++;
    }
    while (check_order(*stack, quart) == 0)
    {
        i = 0;
        while (i < quart)
        {
            bubble_sort(*stack, SA);
            rotate(*stack, RA);
            i++;
        }
        while (i > 0)
        {
            rotate_reverse(*stack, RRA);
            i--;
        }
    }

    // trier la moitier
    while (i < demi)
    {
        rotate_reverse(*stack, RA);
        i++;
    }
        while (check_order(*stack, demi) == 0)
    {
        i = 0;
        while (i < demi)
        {
            bubble_sort(*stack, SA);
            rotate(*stack, RA);
            i++;
        }
        while (i > 0)
        {
            rotate_reverse(*stack, RRA);
            i--;
        }
    }
    while (i < demi)
    {
        rotate(*stack, RA);
        i++;
    }


    // trier les 3 quarts
     while (i < quart)
    {
        rotate_reverse(*stack, RA);
        i++;
    }
        while (check_order(*stack, quart) == 0)
    {
        i = 0;
        while (i < quart)
        {
            bubble_sort(*stack, SA);
            rotate(*stack, RA);
            i++;
        }
        while (i > 0)
        {
            rotate_reverse(*stack, RRA);
            i--;
        }
    }

    while (i < quart)
    {
        rotate(*stack, RA);
        i++;
    }


    // trier le dernier quart
    while (check_order(*stack, quart) == 0)
    {
        i = 0;
        while (i < quart - 1)
        {
            bubble_sort(*stack, SA);
            rotate(*stack, RA);
            i++;
        }
        while (i > 0)
        {
            rotate_reverse(*stack, RRA);
            i--;
        }
    }
    while (i < quart)
    {
        rotate(*stack, RA);
        i++;
    }

    // checker toute la longueur    
    while (check_order(*stack, (*stack)->size) == 0)
    {
        i = 0;
        while (i < (*stack)->size - 1)
        {
            bubble_sort(*stack, SA);
            rotate(*stack, RA);
            i++;
        }
        while (i > 0)
        {
            rotate_reverse(*stack, RRA);
            i--;
        }
    }
}
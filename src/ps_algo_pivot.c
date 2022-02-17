/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algo_pivot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 09:33:56 by mreymond          #+#    #+#             */
/*   Updated: 2022/02/17 19:27:12 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_biggest_nbr(t_list *stack_a)
{
    t_nbr *biggest;
    int big_nbr;
    int small_nbr;
    int pivot;

    biggest = stack_a->first;
    big_nbr = biggest->number;
    small_nbr = biggest->number;
    while (biggest->next != NULL)
    {
            if (big_nbr < biggest->number)
                big_nbr = biggest->number;
            if (small_nbr > biggest->number)
                small_nbr = biggest->number;
            biggest = biggest->next;
    }
    pivot = (big_nbr + (2 * small_nbr)) / 3;
    return (pivot);
}

int is_smaller(int nbr, int pivot)
{
    if (nbr < pivot)
        return (1);
    else
        return (0);
}

int is_bigger(int nbr, int pivot)
{
    if (nbr > pivot)
        return (1);
    else
        return (0);
}

int find_pivot(t_list *stack_a, int first_pivot)
{
    t_nbr *a;
    int new_pivot;

    a = stack_a->first;
    if (stack_a->first == NULL)
        return (first_pivot);
    while (a->next != NULL)
    {
        new_pivot = a->number;
        if (new_pivot > first_pivot)
            return (new_pivot);
        a = a->next;
    }
    return (first_pivot);
}

void algo_pivot_sort(t_list **stack_a, t_list **stack_b)
{
    int middle_pivot;

    int i;
    int j;
    int count;
    int size;

    count = 0;
    middle_pivot = find_biggest_nbr(*stack_a);
    while (count < 3)
    {
        i = 0;
        j = 0;
        size = (*stack_a)->size;
        while (i < size)
        {
            if (is_smaller((*stack_a)->first->number, middle_pivot))
            {
                push(*stack_a, stack_b, PB);
                j++;
            }
            else 
                rotate(*stack_a, RA);
            i++;
        }
        algo_bubble_opti_sort_reverse(stack_a, stack_b, j);
        middle_pivot = find_biggest_nbr(*stack_a);
        count++;
    }
    algo_bubble_opti_sort(stack_a);
     while ((*stack_b)->size > 0)
		push(*stack_b, stack_a, PA);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algo_pivot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 09:33:56 by mreymond          #+#    #+#             */
/*   Updated: 2022/02/17 22:50:55 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_biggest_nbr(t_list *stack_a)
{
    t_nbr *actual;
    int small_nbr;
    int pivot;
    int times;

    times = 3;
    actual = stack_a->first;
    small_nbr = actual->number;
    while (actual->next != NULL)
    {
            if (small_nbr > actual->number)
                small_nbr = actual->number;
            actual = actual->next;
    }
    actual = stack_a->first;
    pivot = small_nbr;
    return (pivot);
}

int is_smaller(int nbr, int pivot)
{
    if (nbr <= pivot)
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

int pivot_is_in_stack(t_list *stack_a, int pivot)
{
    t_nbr *a;
    int i;

    a = stack_a->first;
    i = 0;
    while (a->next != NULL)
    {
        if (a->number <= pivot)
            i++;
        a = a->next;
    }
    if (a->number <= pivot)
        i++;
    if (i > 0)
        return (1);
    return (0);
}

void algo_pivot_sort(t_list **stack_a, t_list **stack_b)
{
    int pivot;
    int i;
    int j;
    int sections;
    int count;
    int size;
    int tmp;

    pivot = find_biggest_nbr(*stack_a) + 10;
    count = 0;
    tmp = pivot - 10;
    size = (*stack_a)->size;
    sections = size / 13;
    while (sections >= 0)
    {
        count = 0;
        while (count < 1)
        {
            i = 0;
            j = 0;
            while (i < size)
            {
                if (is_smaller((*stack_a)->first->number, pivot))
                {
                    push(*stack_a, stack_b, PB);
                    j++;
                }
                else if (pivot_is_in_stack(*stack_a, pivot))
                    rotate(*stack_a, RA);
                i++;
            }
            pivot = find_biggest_nbr(*stack_a) + 10;
            count++;
        }
        algo_bubble_opti_sort_reverse(stack_a, stack_b, j);
        sections--;
    }
    algo_bubble_opti_sort(stack_a);
     while ((*stack_b)->size > 0)
		push(*stack_b, stack_a, PA);
}
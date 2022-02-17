/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algo_pivot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 09:33:56 by mreymond          #+#    #+#             */
/*   Updated: 2022/02/17 12:50:46 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_biggest_nbr(t_list *stack_a)
{
    t_nbr *biggest;
    int big_nbr;

    biggest = stack_a->first;
    big_nbr = biggest->number;
    while (biggest->next != NULL)
    {
            if (big_nbr < biggest->number)
                big_nbr = biggest->number;
            biggest = biggest->next;
    }
    return (big_nbr / 2);
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
    int scd_pivot;

    int i;
    int j;
    int tmp;

    i = 0;
    j = 0;
    tmp = 0;
    middle_pivot = find_biggest_nbr(*stack_a);
    // printf("pivot: %d\n", middle_pivot);
    
    // mettre tous les plus petits que middle dans stack b
    while (i < (*stack_a)->size)
	{
        if (is_smaller((*stack_a)->first->number, middle_pivot))
		    push(*stack_a, stack_b, PB);
		i++;
	}

    // choisir un pivot plus grand d'un quart et push les plus petit dans b
    scd_pivot = middle_pivot + (middle_pivot / 2);
    i = 0;
    while (i < (*stack_a)->size)
	{
        if (is_smaller((*stack_a)->first->number, scd_pivot))
        {
		    push(*stack_a, stack_b, PB);
            j++;
        }
		i++;
	}

    if (j % 2 == 0)
    {
        push(*stack_a, stack_b, PB);
        j++;
    }

    // bubble sort stack a
    // tant qu'on est pas du plus petit au plus grand
    // swap si next est plus grand et rotate <<<<<<<

    tmp = (*stack_a)->size + 1;

    while (bubble_loop(*stack_a) == 0)
	{
        j = tmp;
        while (j >= 0)
        {
            if (bubble_loop(*stack_a) == 0)
            {
                bubble_sort_big(*stack_a, SA);
                rotate(*stack_a, RA);
            }
            j--;
        }
        j = tmp;
        while (j >= 0)
        {
            if (bubble_loop(*stack_a) == 0)
            {
                rotate_reverse(*stack_a, RRA);
                bubble_sort(*stack_a, SA);
            }
            j--;
        }
        j = tmp;
        while (j >= 0)
        {
            if (bubble_loop(*stack_a) == 0)
            {
                bubble_sort(*stack_a, SA);
                rotate(*stack_a, RA);
            }
            j--;
        }
        j = tmp;
        while (j >= 0)
        {
            if (bubble_loop(*stack_a) == 0)
            {
                rotate_reverse(*stack_a, RRA);
                bubble_sort(*stack_a, SA);
            }
            j--;
        }
    }

    j = (*stack_b)->size / 2;
    // remettre le quart dans a
    while (j > 0)
	{
        push(*stack_b, stack_a, PA);
		j--;
	}
    
    if ((*stack_b)->size % 2 == 0)
    {
        push(*stack_b, stack_a, PA);
    }

    tmp = (*stack_b)->size;

    while (bubble_loop_reverse(*stack_b) == 0)
	{
        j = tmp;
        while (j >= 0)
        {
            if (bubble_loop_reverse(*stack_b) == 0)
            {
                bubble_sort_big(*stack_b, SB);
                rotate(*stack_b, RB);
            }
            j--;
        }
        j = tmp;
        while (j >= 0)
        {
            if (bubble_loop_reverse(*stack_b) == 0)
            {
                rotate_reverse(*stack_b, RRB);
                bubble_sort(*stack_b, SB);
            }
            j--;
        }
        j = tmp;
        while (j >= 0)
        {
            if (bubble_loop_reverse(*stack_b) == 0)
            {
                bubble_sort(*stack_b, SB);
                rotate(*stack_b, RB);
            }
            j--;
        }
        j = tmp;
        while (j >= 0)
        {
            if (bubble_loop_reverse(*stack_b) == 0)
            {
                rotate_reverse(*stack_b, RRB);
                bubble_sort(*stack_b, SB);
            }
            j--;
        }
    }

    tmp = (*stack_a)->size - (*stack_b)->size + 1;

    while (bubble_loop(*stack_a) == 0)
	{
        j = tmp;
        while (j >= 0)
        {
            if (bubble_loop(*stack_a) == 0)
            {
                bubble_sort_big(*stack_a, SA);
                rotate(*stack_a, RA);
            }
            j--;
        }
        j = tmp;
        while (j >= 0)
        {
            if (bubble_loop(*stack_a) == 0)
            {
                rotate_reverse(*stack_a, RRA);
                bubble_sort(*stack_a, SA);
            }
            j--;
        }
        j = tmp;
        while (j >= 0)
        {
            if (bubble_loop(*stack_a) == 0)
            {
                bubble_sort(*stack_a, SA);
                rotate(*stack_a, RA);
            }
            j--;
        }
        j = tmp;
        while (j >= 0)
        {
            if (bubble_loop(*stack_a) == 0)
            {
                rotate_reverse(*stack_a, RRA);
                bubble_sort(*stack_a, SA);
            }
            j--;
        }
    }

    tmp = (*stack_a)->size - (*stack_b)->size + 1;
    
    // remettre tout dans a
    while ((*stack_b)->size > 0)
	{
        tmp++;
        push(*stack_b, stack_a, PA);
	}

    while (bubble_loop(*stack_a) == 0)
	{
        j = tmp;
        while (j > 0)
        {
            if (bubble_loop(*stack_a) == 0)
            {
                bubble_sort_big(*stack_a, SA);
                rotate(*stack_a, RA);
            }
            j--;
        }
        j = tmp;
        while (j > 0)
        {
            if (bubble_loop(*stack_a) == 0)
            {
                rotate_reverse(*stack_a, RRA);
                bubble_sort(*stack_a, SA);
            }
            j--;
        }
        j = tmp;
        while (j > 0)
        {
            if (bubble_loop(*stack_a) == 0)
            {
                bubble_sort(*stack_a, SA);
                rotate(*stack_a, RA);
            }
            j--;
        }
        j = tmp;
        while (j > 0)
        {
            if (bubble_loop(*stack_a) == 0)
            {
                rotate_reverse(*stack_a, RRA);
                bubble_sort(*stack_a, SA);
            }
            j--;
        }
    }
    //         printf("A: ");
	// afficherListe(*stack_a);
	// printf("B: ");
	// afficherListe(*stack_b);
    // exit(0);
}
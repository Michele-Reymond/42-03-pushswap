/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algo_pivot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 09:33:56 by mreymond          #+#    #+#             */
/*   Updated: 2022/02/22 19:35:54 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_biggest_nbr(t_list *stack_a)
{
    t_nbr *actual;
    int small_nbr;
    int pivot;

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

char *algo_pivot_sort(t_list **stack_a, t_list **stack_b)
{
    int pivot;
    int i;
    int j;
    int sections;
    int count;
    int size;
    int tmp;
    char *moves;
    char *chartmp;

    pivot = find_biggest_nbr(*stack_a) + 10;
    count = 0;
    tmp = pivot - 10;
    size = (*stack_a)->size;
    sections = size / 13;
    chartmp = ft_strdup("");
    moves = ft_strdup("");
    // while (sections >= 0)
    // {
        count = 0;
        while (count < 1)
        {
            i = 0;
            j = 0;
            while (i < size)
            {
                if (is_smaller((*stack_a)->first->number, pivot))
                {
                    moves = push(*stack_a, stack_b, PB, chartmp);
                    chartmp = moves;
                    free(moves);
                    moves = NULL;
                    j++;
                }
                else if (pivot_is_in_stack(*stack_a, pivot))
                {
                    moves = rotate(*stack_a, RA, chartmp);
                    chartmp = moves;
                    free(moves);
                    moves = NULL;
                }
                i++;
            }
            pivot = find_biggest_nbr(*stack_a) + 10;
            count++;
        }
        moves = algo_bubble_opti_sort_reverse(stack_a, stack_b, j, chartmp);
        chartmp = moves;
        free(moves);
        moves = NULL;
        sections--;
    // }
    moves = algo_bubble_opti_sort(stack_a, chartmp);
    chartmp = moves;
    free(moves);
    moves = NULL;
     while ((*stack_b)->size > 0)
     {
		moves = push(*stack_b, stack_a, PA, chartmp);
        chartmp = moves;
        // free(moves);
        // moves = NULL;
     }
    return (chartmp);
}

// cimetière de fonctions inutiles

char *algo_pivot_big(t_list **stack_a, t_list **stack_b)
{
	int pivot;
	int pivot_low;
	int i;
	char *moves;
	int size;
	int pushed_small;

	i = 0;
	pushed_small = 0;
	size = (*stack_a)->size;
	moves = ft_strdup("");
	pivot = ((*stack_a)->smallest + (*stack_a)->biggest) / 3 + 100;
	pivot_low = (*stack_a)->smallest + 200;
	while (i <= size && pivot_is_in_stack(*stack_a, pivot))
	{
		if (is_smaller((*stack_a)->first->number, pivot))
		{
			push(*stack_a, stack_b, PB, moves);
			if (bubble_sort(*stack_a, SA, ""))
					printf("%s\n", "sa");
			if ((*stack_b) && is_smaller((*stack_b)->first->number, pivot_low))
			{
				rotate(*stack_b, RB, moves);
				printf("%s\n", "rb");
			}
			if ((*stack_b) && bubble_sort_big(*stack_b, SB, ""))
					printf("%s\n", "sb");
		}
		else
		{
			rotate(*stack_a, RA, moves);
			printf("%s\n", "ra");
		}
		i++;
	}
	stock_stack_infos(stack_a);
	while ((*stack_a)->size > 10)
	{
		push(*stack_a, stack_b, PB, moves);
		if (bubble_sort_big(*stack_b, SB, ""))
			printf("%s\n", "sb");
		stock_stack_infos(stack_a);
	}
	return (moves);
}

void bubble_sort_reverse_b(t_list **stack_a, t_list **stack_b, int size)
{
	int i;
	int a;
	int b;

	i = 0;
	a = 0;
	b = 0;  
	while (check_order(*stack_b, size) == 0)
	{
		i = 0;
		afficherListe(*stack_b);
		while (i < size)
		{
			b = bubble_sort(*stack_b, SB, "");
			a = bubble_sort(*stack_a, SA, "");
			if (a == 1 && b == 1)
				printf("%s\n", "ss");
			else if (b == 1)
				printf("%s\n", "sb");
			else if (a == 1)
				printf("%s\n", "sa");
			rotate(*stack_b, RB, "");     
			rotate(*stack_a, RA, "");
			printf("%s\n", "rr");
			i++;
		}
		i = size;
		while (i > 0)
		{
			rotate_reverse(*stack_b, RRB, "");
			rotate_reverse(*stack_a, RRA, "");
			printf("%s\n", "rrr");
			i--;
		}
	} 
}


void bubble_sort_b(t_list **stack_a, t_list **stack_b, int size)
{
	int i;
	int a;
	int b;

	i = 0;
	a = 0;
	b = 0; 
	while (check_order_reverse(*stack_b, size + 1) == 0)
	{
		i = 0;
		while (i < size)
		{
			b = bubble_sort_big(*stack_b, SB, "");
			a = bubble_sort(*stack_a, SA, "");
			if (a == 1 && b == 1)
				printf("%s\n", "ss");
			if (b == 1 && a == 0)
				printf("%s\n", "sb");
			if (a == 1 && b == 0)
				printf("%s\n", "sa");
			rotate(*stack_b, RB, "");     
			rotate(*stack_a, RA, "");
			printf("%s\n", "rr");
			i++;
		}
		i = 0;
		while (i < size)
		{
			rotate_reverse(*stack_b, RRB, "");
			rotate_reverse(*stack_a, RRA, "");
			printf("%s\n", "rrr");
			if ((*stack_b) && bubble_sort_big(*stack_b, SB, ""))
				printf("%s\n", "sb");
			i++;
		}
		size--;
	} 
}
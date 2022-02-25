/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_trash.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 20:56:02 by mreymond          #+#    #+#             */
/*   Updated: 2022/02/25 11:24:17 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// cimetière des fonctions codée mais inutilisée

void	afficherListe(t_list *liste)
{
	t_nbr	*actuel;

	if (liste == NULL)
	{
		printf("Liste nulle\n");
		return ;
	}
	actuel = liste->first;
	while (actuel != NULL)
	{
		printf("%d -> ", actuel->number);
		actuel = actuel->next;
	}
	printf("NULL\n");
}

int	smaller_pivot_low(t_list ****stack_a, t_list ****stack_b, t_pivot *pivot)
{
	char	*moves;
	int		pushed_back;
	int size;

	pushed_back = 0;
	moves = ft_strdup("");
	size = (***stack_a)->size;
	if (is_smaller((***stack_a)->first->number, pivot->high))
	{
		moves = push(***stack_a, **stack_b, PB, moves);
		if ((***stack_b) && is_bigger((***stack_b)->first->number, pivot->low))
		{
			moves = rotate(***stack_b, RB, moves);
			pushed_back++;
		}
	}
	else
		moves = rotate(***stack_a, RA, moves);
	return (pushed_back);
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

	i = 0;
	(void)stack_a;
	size = (*stack_b)->size - 1;
	while (check_order(*stack_b, size + 1) == 0)
	{
		i = 0;
		while (i < size)
		{
			if (bubble_sort(*stack_b, SB, ""))
				printf("%s\n", "sb");
			rotate(*stack_b, RB, "");
			printf("%s\n", "rb");
			i++;
		}
		i = 0;
		while (i < size)
		{
			rotate_reverse(*stack_b, RRB, "");
			if ((*stack_b) && bubble_sort(*stack_b, SB, ""))
				printf("%s\n", "sb");
			i++;
		}
		size--;
	}
}


// 1, 3, 5, 8
// du plus petit au plus grand
int	bubble_loop(t_list *stack)
{
	t_nbr	*li_next;
	t_nbr	*li_pos;

	li_pos = stack->first;
	li_next = li_pos->next;
	while (li_pos->next != NULL)
	{
		if (li_pos->number > li_next->number)
			return (0);
		li_pos = li_pos->next;
		li_next = li_pos->next;
	}
	return (1);
}

// 8, 5, 3, 1
// du plus grand au plus petit
int	bubble_loop_reverse(t_list *stack)
{
	t_nbr	*li_next;
	t_nbr	*li_pos;

	li_pos = stack->first;
	li_next = li_pos->next;
	while (li_pos->next != NULL)
	{
		if (li_pos->number < li_next->number)
			return (0);
		li_pos = li_pos->next;
		li_next = li_pos->next;
	}
	return (1);
}


char *algo_bubble_opti_sort(t_list **stack, char *moves)
{
    int i;
    int size;
    char *new_moves;
    char *new_moves_rr;
    char *new_moves_bubble = NULL;
  
    size = (*stack)->size - 1;
    while (check_order(*stack, (*stack)->size) == 0)
    {
        i = 0;
        while (i < size)
        {
            bubble_sort(*stack, SA, moves);
            new_moves = rotate(*stack, RA, new_moves_bubble);
            moves = new_moves;
            i++;
        }
        i = size;
        while (i > 0)
        {
            new_moves_rr = rotate_reverse(*stack, RRA, moves);
            moves = new_moves_rr;
            i--;
        }
        size--;
    } 
    return (moves);
}

char *algo_bubble_opti_sort_reverse(t_list **stack_a, t_list **stack_b, int size, char *moves)
{
    int i;
    char *new_moves_b;
    char *new_moves_a;
    char *new_moves_rr_b;
    char *new_moves_rr_a;
    char *new_moves_bubble_b = NULL;
    char *new_moves_bubble_a = NULL;

    // while (check_order_reverse(*stack_b, (*stack_b)->size) == 0)
    // {
        i = 0;
        while (i < size)
        {
            bubble_sort_big(*stack_b, SB, moves);
            bubble_sort(*stack_a, SA, new_moves_bubble_b);
            new_moves_b = rotate(*stack_b, RB, new_moves_bubble_a);     
            new_moves_a = rotate(*stack_a, RA, new_moves_b);
            moves = new_moves_a;   
            i++;
        }
        i = size;
        while (i > 0)
        {
            new_moves_rr_b = rotate_reverse(*stack_b, RRB, moves);
            new_moves_rr_a = rotate_reverse(*stack_a, RRA, new_moves_rr_b);
            moves = new_moves_rr_a;
            i--;
        }
        size--;
    // } 
    return (new_moves_rr_a);
}
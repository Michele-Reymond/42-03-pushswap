/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algo_pivot_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 10:24:13 by mreymond          #+#    #+#             */
/*   Updated: 2022/02/22 01:51:28 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    stock_stack_infos(t_list **stack)
{
    t_nbr *actual;

    actual = (*stack)->first;
    (*stack)->first_n = actual->number;
    (*stack)->smallest = actual->number;
    (*stack)->biggest = actual->number;
    (*stack)->somme = 0;
    while (actual->next != NULL)
    {
            if ((*stack)->smallest > actual->number)
                (*stack)->smallest = actual->number;
            if ((*stack)->biggest < actual->number)
                (*stack)->biggest = actual->number;
            (*stack)->somme = (*stack)->somme + actual->number;
            actual = actual->next;
    }
    if ((*stack)->smallest > actual->number)
        (*stack)->smallest = actual->number;
    if ((*stack)->biggest < actual->number)
        (*stack)->biggest = actual->number;
    (*stack)->somme = (*stack)->somme + actual->number;
    (*stack)->last = actual->number;
}

t_pivot *make_middle_pivot(t_pivot *pivot, t_list *stack)
{
    if (stack->somme > 0)
    {
        pivot->high = stack->somme / 2;
        pivot->low = stack->somme / 4;
    }
    else if (stack->somme < 0)
    {
        pivot->high = stack->somme / 4;
        pivot->low = (pivot->high + stack->smallest) / 2;
    }
    else
    {
        pivot->high = stack->somme + 2;
        pivot->low = stack->somme - 2;
    }
    return (pivot);
}

t_pivot *make_pivot(t_list *stack)
{
    t_pivot *pivot;

    pivot = malloc(sizeof(t_pivot *));
    if (stack->size > 5 && stack->size <= 20)
        pivot = make_middle_pivot(pivot, stack);
    else if (stack->size > 20 && stack->size <= 150)
    {
        pivot->high = stack->smallest + 8;
        pivot->low = stack->smallest + 4;
    }
    else if (stack->size > 150 && stack->size <= 550)
    {
        pivot->high = stack->smallest + 50;
        pivot->low = stack->smallest + 25;
    }
    else
    {
        pivot->high = stack->smallest + 100;
        pivot->low = stack->smallest + 50;
    }
    return (pivot);
}

void bubble_sort_a(t_list **stack, int size)
{
    int i;

    i = 0;
    size = (*stack)->size - 1;
    while (check_order(*stack, size + 1) == 0)
    {
        i = 0;
        while (i < size)
        {
            if (bubble_sort(*stack, SA, ""))
                printf("%s\n", "sa");
            rotate(*stack, RA, "");
            printf("%s\n", "ra");
            i++;
        }
        i = 0;
        while (i < size)
        {
            rotate_reverse(*stack, RRA, "");
            printf("%s\n", "rra");
            if ((*stack) && bubble_sort(*stack, SA, ""))
                printf("%s\n", "sa");
            i++;
        }
        size--;
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

char *algo_pivot(t_list **stack_a, t_list **stack_b)
{
    t_pivot	*pivot;
    char *moves;
    int i;
    int j;
    int size;
    int pushed_small;
    int last_pivot;

    pivot = make_pivot(*stack_a);
    i = 0;
    j = 0;
    pushed_small = 0;
    moves = ft_strdup("");
    size = (*stack_a)->size;
    
    while (i <= size && pivot_is_in_stack(*stack_a, pivot->high))
    {
        if (is_smaller((*stack_a)->first->number, pivot->high))
        {
            push(*stack_a, stack_b, PB, moves);
            if (bubble_sort(*stack_a, SA, ""))
                    printf("%s\n", "sa");
            if ((*stack_b) && is_smaller((*stack_b)->first->number, pivot->low))
            {
                rotate(*stack_b, RB, moves);
                printf("%s\n", "rb");
                pushed_small++;
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
    stock_stack_infos(stack_b);
    // bubble_sort_b(stack_a, stack_b, (*stack_b)->size - pushed_small);
    // i = 0;
    // rotate_reverse(*stack_b, RRB, moves);
    // printf("%s\n", "rrb");
    // while (i < pushed_small)
    // {
    //     rotate_reverse(*stack_b, RRB, moves);
    //     printf("%s\n", "rrb");
    //     if (bubble_sort_big(*stack_b, SB, ""))
    //         printf("%s\n", "sb");
    //     i++;
    // }
    // bubble_sort_b(stack_a, stack_b, pushed_small);
    while ((*stack_b)->first->number != (*stack_b)->biggest)
    {
        rotate_reverse(*stack_b, RRB, moves);
        printf("%s\n", "rrb");
    }

    last_pivot = pivot->high;
    pivot->high = pivot->high + 40;
    pivot->low = last_pivot + 20; 
    size = (*stack_a)->size;

    while (pivot->high < (*stack_a)->biggest)
    {
        i = 0;
        j = 0;
        pushed_small = 0;
        while (i <= size)    
        {
            if (is_smaller((*stack_a)->first->number, pivot->high))
            {
                push(*stack_a, stack_b, PB, moves);
                if ((*stack_b)->first->number > last_pivot && is_bigger((*stack_b)->first->number, pivot->low))
                {
                    rotate(*stack_b, RB, moves);
                    printf("%s\n", "rb");
                    pushed_small++;
                }
                if ((*stack_b) && bubble_sort_big(*stack_b, SB, ""))
                    printf("%s\n", "sb");
                j++;
            }
            else
            {
                rotate(*stack_a, RA, moves);
                printf("%s\n", "ra");
            }
            i++;
        }
        // bubble_sort_b(stack_a, stack_b, j - pushed_small);
        i = 0;
        while (i < pushed_small)
        {
            rotate_reverse(*stack_b, RRB, moves);
            printf("%s\n", "rrb");
            i++;
        }
        // bubble_sort_b(stack_a, stack_b, pushed_small);
        last_pivot = pivot->high;
        pivot->high = pivot->high + 50;
        pivot->low = last_pivot + 25; 
        size = (*stack_a)->size;
    }

    // stock_stack_infos(stack_a);

    // while ((*stack_a)->first->number != (*stack_a)->smallest)
    // {
    //     rotate(*stack_a, RA, moves);
    //     printf("%s\n", "ra");
    // }

    // bubble_sort_a(stack_a, (*stack_a)->size);
    // while ((*stack_b)->first != NULL)
    //     push(*stack_b, stack_a, PA, moves);

    return (moves);
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

void    algo_lolo(t_list **stack_a, t_list **stack_b)
{
    char *moves;

    moves = ft_strdup("");
    // while ((*stack_a)->size < 10)
    //     push(*stack_b, stack_a, PA, moves);
    bubble_sort_a(stack_a, (*stack_a)->size);
    while ((*stack_a)->last != (*stack_a)->biggest)
    {
        rotate(*stack_a, RA, moves);
        printf("%s\n", "ra");
        stock_stack_infos(stack_a);
    }

    while ((*stack_b)->size > 0)
    {
        stock_stack_infos(stack_a);
        if ((*stack_b)->first->number < (*stack_a)->first->number)
        {
            while ((*stack_b)->first->number < (*stack_a)->first->number && (*stack_b)->first->number < (*stack_a)->last && (*stack_a)->last != (*stack_a)->biggest) 
            {
                rotate_reverse(*stack_a, RRA, moves);
                printf("%s\n", "rra");
                stock_stack_infos(stack_a);
            }
            push(*stack_b, stack_a, PA, moves);
        }
        else if ((*stack_b)->first->number > (*stack_a)->first->number)
        {
            if ((*stack_b)->first->number > (*stack_a)->biggest)
            {
                while ((*stack_b)->first->number != (*stack_a)->biggest)
                {
                    rotate(*stack_a, RRA, moves);
                    printf("%s\n", "ra");
                    stock_stack_infos(stack_a);
                }
            }
            else
            {
                while ((*stack_b)->first->number > (*stack_a)->first->number && (*stack_b)->first->number < (*stack_a)->biggest) 
                {
                    rotate(*stack_a, RRA, moves);
                    printf("%s\n", "ra");
                    stock_stack_infos(stack_a);
                }
            }
            push(*stack_b, stack_a, PA, moves);
        }
    }
    while ((*stack_a)->last != (*stack_a)->biggest)
    {
        rotate_reverse(*stack_a, RA, moves);
        printf("%s\n", "rra");
        stock_stack_infos(stack_a);
    }
}
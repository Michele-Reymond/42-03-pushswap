/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algo_pivot_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 10:24:13 by mreymond          #+#    #+#             */
/*   Updated: 2022/02/24 12:19:00 by mreymond         ###   ########.fr       */
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
	pivot->high = stack->smallest + 2;
	pivot->low = stack->smallest + 1;
	pivot->add = 2;
	return (pivot);
}

t_pivot *make_pivot(t_list *stack)
{
	t_pivot *pivot;

	pivot = malloc(sizeof(t_pivot *));
	if (stack->size > 5 && stack->size <= 20)
		pivot = make_middle_pivot(pivot, stack);
	else if (stack->size > 20 && stack->size <= 350)
	{
		pivot->high = stack->smallest + 16;
		pivot->low = stack->smallest + 8;
		pivot->add = 16;
	}
	else if (stack->size > 350 && stack->size <= 550)
	{
		pivot->high = stack->smallest + 70;
		pivot->low = stack->smallest + 35;
		pivot->add = 70;
	}
	else
	{
		pivot->high = stack->smallest + 100;
		pivot->low = stack->smallest + 50;
		pivot->add = 100;
	}
	return (pivot);
}

void algo_tree(t_list **stack)
{
	if ((*stack)->last == (*stack)->biggest)
	{
		if (bubble_sort(*stack, SA, ""))
			printf("%s\n", "sa");
	}
	else if ((*stack)->first->number == (*stack)->biggest)
	{
		rotate(*stack, RA, "");
		printf("%s\n", "ra");
		if (bubble_sort(*stack, SA, ""))
			printf("%s\n", "sa");
	}
	else
	{
		rotate_reverse(*stack, RRA, "");
		if (bubble_sort(*stack, SA, ""))
			printf("%s\n", "sa");
	}
}

void algo_five(t_list **stack_a, t_list **stack_b)
{
	int i;

	i = -1;
	while (++i < 2)
	{
		if ((*stack_a)->first->next->number == (*stack_a)->smallest)
		{
			rotate(*stack_a, RA, "");
			printf("%s\n", "ra");
		}
		else {
			while ((*stack_a)->first->number != (*stack_a)->smallest)
				rotate_reverse(*stack_a, RRA, "");
		}
		if (check_order(*stack_a, (*stack_a)->size))
			return;
		push(*stack_a, stack_b, PB, "");
		printf("%s\n", "pb");
		stock_stack_infos(stack_a);
	}
	algo_tree(stack_a);
	push(*stack_b, stack_a, PB, "");
	push(*stack_b, stack_a, PB, "");
	printf("%s\n", "pa");
	printf("%s\n", "pa");
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
			if ((*stack) && bubble_sort(*stack, SA, ""))
				printf("%s\n", "sa");
			i++;
		}
		size--;
	}
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

int heart_reverse(t_list ***stack_a, t_list ***stack_b, t_pivot	*pivot, int size, char *moves)
{
	int		i;
	int		pushed_back;

	i = 0;
	pushed_back = 0;
	while (i <= size && pivot_is_in_stack(**stack_a, pivot->high))
	{
		if (is_smaller((**stack_a)->first->number, pivot->high))
		{
			moves = push(**stack_a, *stack_b, PB, moves);
			if ((**stack_b) && is_smaller((**stack_b)->first->number, pivot->low))
			{
				moves = rotate(**stack_b, RB, moves);
				pushed_back++;
			}
		}
		else
			moves = rotate(*(*stack_a), RA, moves);
		i++;
	}
	printf("%s", moves);
	return (pushed_back);
}

int heart(t_list ***stack_a, t_list ***stack_b, t_pivot	*pivot, int size, char *moves)
{
	int		i;
	int		pushed_back;

	i = 0;
	pushed_back = 0;
	while (i <= size && pivot_is_in_stack(**stack_a, pivot->high))
	{
		if (is_smaller((**stack_a)->first->number, pivot->high))
		{
			moves = push(**stack_a, *stack_b, PB, moves);
			if ((**stack_b) && is_bigger((**stack_b)->first->number, pivot->low))
			{
				moves = rotate(**stack_b, RB, moves);
				pushed_back++;
			}
		}
		else
			moves = rotate(*(*stack_a), RA, moves);
		i++;
	}
	printf("%s", moves);
	return (pushed_back);
}

void	algo_pivot_push(t_list **stack_a, t_list **stack_b)
{
	t_pivot	*pivot;
	int		pushed_small;
	int		i;
	char *moves;

	moves = ft_strdup("");
	pivot = make_pivot(*stack_a);
	heart_reverse(&stack_a, &stack_b, pivot, (*stack_a)->size, moves);
	pivot->low = pivot->high + (pivot->add / 2); 
	pivot->high = pivot->high + pivot->add;
	while (pivot->high < (*stack_a)->biggest)
	{
		i = -1;
		pushed_small = heart(&stack_a, &stack_b, pivot, (*stack_a)->size, moves);
		while (++i < pushed_small && (*stack_b)->size > 4)
			rotate_reverse(*stack_b, RRB, "");
		pivot->low = pivot->high + (pivot->add / 2); 
		pivot->high = pivot->high + pivot->add;
	}
}

void is_smaller_algo(t_list ***stack_a, t_list ***stack_b)
{
	char *moves;

	moves = ft_strdup("");
	while ((**stack_b)->first->number < (**stack_a)->first->number && 
		(**stack_b)->first->number < (**stack_a)->last && 
		(**stack_a)->last != (**stack_a)->biggest) 
	{
		rotate_reverse(**stack_a, RRA, moves);
		stock_stack_infos(*stack_a);
	}
	push(**stack_b, *stack_a, PA, moves);
	printf("%s\n", "pa");
}

void is_bigger_algo(t_list ***stack_a, t_list ***stack_b)
{
	char *moves;

	moves = ft_strdup("");
	if ((**stack_b)->first->number > (**stack_a)->biggest)
	{
		while ((**stack_b)->first->number != (**stack_a)->biggest)
		{
			rotate(**stack_a, RA, moves);
			printf("%s\n", "ra");
			stock_stack_infos(*stack_a);
		}
	}
	else
	{
		while ((**stack_b)->first->number > (**stack_a)->first->number && 
		(**stack_b)->first->number < (**stack_a)->biggest) 
		{
			rotate(**stack_a, RA, moves);
			printf("%s\n", "ra");
			stock_stack_infos(*stack_a);
		}
	}
	push(**stack_b, *stack_a, PA, moves);
	printf("%s\n", "pa");
}

void    algo_pivot_back(t_list **stack_a, t_list **stack_b)
{
	char *moves;

	moves = ft_strdup("");
	bubble_sort_a(stack_a, (*stack_a)->size);
	while ((*stack_b)->size > 0)
	{
		stock_stack_infos(stack_b);
		stock_stack_infos(stack_a);
		if ((*stack_b)->first->number < (*stack_a)->first->number)
			is_smaller_algo(&stack_a, &stack_b);
		else if ((*stack_b)->first->number > (*stack_a)->first->number)
			is_bigger_algo(&stack_a, &stack_b);
	}
	while ((*stack_a)->last != (*stack_a)->biggest)
	{
		rotate_reverse(*stack_a, RRA, moves);
		stock_stack_infos(stack_a);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:05:43 by mreymond          #+#    #+#             */
/*   Updated: 2022/02/12 11:19:35 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str)
{
	int			i;
	int			num;
	long int	temp;

	i = 0;
	temp = 0;
	num = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
		num = num * -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		temp = temp * 10 + (str[i] - 48);
		i++;
	}
	temp = temp * num;
	return (temp);
}

int check_doubles(int *stack, long entry, int pos)
{
	int i;

	i = 0;
	while (i < pos)
	{
		if (stack[i] == entry)
			return (0);
		i++;
	}
	return (1);
}

int check_max(long entry)
{
	if (!(entry >= INT_MIN && entry <= INT_MAX))
		return (0);
	return (1);
}

void check_entry(int *stack, long entry, int pos)
{
	if (check_max(entry) == 0)
	{
		printf("Error\nUn des nombres n'est pas un integre!\n");
		free(stack);
		exit(0);
	}
	if (check_doubles(stack, entry, pos) == 0)
	{
		printf("Error\nIl y a des doublons!\n");
		free(stack);
		exit(0);
	}
}

void check_nbr(char *nbr, int *stack)
{
	int i;

	i = 0;
	while (nbr[i] != '\0')
	{
		if (!(nbr[i] >= '0' && nbr[i] <= '9'))
		{
			printf("Error\nL'une des entrée n'est pas un nombre\n");
			free(stack);
			exit(0);
		}
		i++;
	}
}

int *stock_args(int count, char **arguments)
{
	int		*stack;
	int		i;
	int		j;
	long	entry;
	
	i = 0;
	j = 1;
	stack = (int *)malloc(sizeof(int) * (count - 1) + 1);
	if (stack == NULL)
		return (0);
	while (j < count)
	{
		check_nbr(arguments[j], stack);
		entry = ft_atol(arguments[j]);
		check_entry(stack, entry, i);
		stack[i] = entry;
		i++;
		j++;
	}
	stack[i] = '\0';
	return (stack);
}

int	main(int argc, char **argv)
{
	int	*stack_a;

	if (argc < 2)
	{
		printf("Error\n");
		return (0);
	}
	stack_a = stock_args(argc, argv);
	printf("print: %d\n", stack_a[3]);
	free(stack_a);
	return (0);
}

//TO DO

// stack b
// algos de tris
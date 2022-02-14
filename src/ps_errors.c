/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:00:42 by mreymond          #+#    #+#             */
/*   Updated: 2022/02/14 18:54:44 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_args(int argc)
{
    if (argc < 2)
	{
		printf("Error\nIl n'y a pas assez d'arguments");
		exit(0);
	}
     if (argc == 2)
	{
		printf("Error\nIl faut plus d'un agrument pour trier");
		exit(0);
	}
	return (argc - 1);
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
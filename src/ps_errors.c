/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:00:42 by mreymond          #+#    #+#             */
/*   Updated: 2022/02/16 13:34:56 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_if_string(char *string)
{
	int	i;

	i = 0;
	while (string[i] != '\0')
	{
		if (!(ft_isdigit(string[i]) || string[i] == ' ' || string[i] == '-'))
			return (0);
		i++;
	}
	if (!ft_strchr(string, ' '))
	{
		printf("Error\nIl n'y a pas assez de nombre à comparer");
		exit(0);
	}
	return (1);
}

int	check_args(int argc, char *string)
{
	if (argc < 2)
	{
		printf("Error\nIl n'y a pas assez d'arguments");
		exit(0);
	}
	if (argc == 2)
	{
		if (!check_if_string(string))
		{
			printf("Error\nL'entrée n'est pas conforme:\n");
			printf("Les nombres doivent être séparés par des espaces\n");
			printf("Il ne doit pas y avoir de lettres\n");
			exit(0);
		}
		return (1);
	}
	return (0);
}

int	check_doubles(t_list *stack, long entry)
{
	t_nbr	*list_pos;

	list_pos = stack->first;
	while (list_pos != NULL)
	{
		if (list_pos->number == entry)
			return (0);
		list_pos = list_pos->next;
	}
	return (1);
}

int	check_max(long entry)
{
	if (!(entry >= INT_MIN && entry <= INT_MAX))
		return (0);
	return (1);
}

void	check_entry(t_list *stack, long entry)
{
	if (check_max(entry) == 0)
	{
		printf("Error\nUn des nombres n'est pas un integre!\n");
		free(stack);
		exit(0);
	}
	if (check_doubles(stack, entry) == 0)
	{
		printf("Error\nIl y a des doublons!\n");
		free(stack);
		exit(0);
	}
}

void	check_nbr(char *nbr, t_list *stack)
{
	int	i;

	i = 0;
	if (nbr[i] == '-')
		i++;
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

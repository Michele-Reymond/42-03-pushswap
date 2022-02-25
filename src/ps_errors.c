/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:00:42 by mreymond          #+#    #+#             */
/*   Updated: 2022/02/25 11:21:00 by mreymond         ###   ########.fr       */
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
		write(1, "Error\nIl n'y a pas assez de nombre à comparer\n", 46);
		exit(0);
	}
	return (1);
}

int	check_args(int argc, char *string)
{
	if (argc < 2)
	{
		write(1, "Error\nIl n'y a pas assez d'arguments\n", 37);
		exit(0);
	}
	if (argc == 2)
	{
		if (!check_if_string(string))
		{
			write(1, "Error\nL'entrée n'est pas conforme:\n", 35);
			write(1, "Les nombres doivent être séparés par des espaces\n", 49);
			write(1, "Il ne doit pas y avoir de lettres\n", 34);
			exit(0);
		}
		return (1);
	}
	return (0);
}

void	check_entry(t_list *stack, long entry)
{
	check_max(entry, stack);
	if (check_doubles(stack, entry) == 0)
	{
		write(1, "Error\nIl y a des doublons!\n", 27);
		free_list(stack);
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
			write(1, "Error\nL'une des entrée n'est pas un nombre\n", 43);
			free_list(stack);
	    	free(stack);
			exit(0);
		}
		i++;
	}
}

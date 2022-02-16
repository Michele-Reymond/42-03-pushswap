/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:59:38 by mreymond          #+#    #+#             */
/*   Updated: 2022/02/16 15:19:23 by mreymond         ###   ########.fr       */
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

t_list	*stock_string(char **av)
{
	char	**strings;
	t_list	*stack;
	int		i;

	i = 0;
	strings = ft_split(av[1], ' ');
	while (strings[i])
		i++;
	stack = stock_args(i, strings, 0);
	return (stack);
}

t_list	*stock_args(int count, char **arguments, int start)
{
	t_list	*stack;
	int		j;
	long	entry;

	j = start;
	count--;
	stack = NULL;
	check_nbr(arguments[count], stack);
	entry = ft_atol(arguments[count]);
	check_max(entry);
	stack = list_init(entry);
	count--;
	while (count >= j)
	{
		check_nbr(arguments[count], stack);
		entry = ft_atol(arguments[count]);
		check_entry(stack, entry);
		insert_befor(stack, entry);
		count--;
	}
	return (stack);
}

// t_list	*stock_args(int count, char **arguments, int start)
// {
// 	t_list	*stack;
// 	int		j;
// 	int		end;
// 	long	entry;

// 	j = start;
// 	stack = NULL;
// 	check_nbr(arguments[j], stack);
// 	entry = ft_atol(arguments[j]);
// 	check_max(entry);
// 	stack = list_init(entry);
// 	j++;
// 	while (j < count)
// 	{
// 		check_nbr(arguments[j], stack);
// 		entry = ft_atol(arguments[j]);
// 		check_entry(stack, entry);
// 		insert_befor(stack, entry);
// 		j++;
// 	}
// 	return (stack);
// }

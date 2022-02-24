/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_linked_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:10:52 by mreymond          #+#    #+#             */
/*   Updated: 2022/02/24 21:13:43 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*list_init(long nbr)
{
	t_list	*liste;
	t_nbr	*number;

	liste = malloc(sizeof(*liste));
	number = malloc(sizeof(*number));
	if (liste == NULL || number == NULL)
		exit(0);
	number->number = nbr;
	number->next = NULL;
	liste->first = number;
	liste->size = 1;
	return (liste);
}

void	insert_befor(t_list *liste, long nbr)
{
	t_nbr	*new_nbr;

	new_nbr = malloc(sizeof(*new_nbr));
	if (liste == NULL || new_nbr == NULL)
		exit(0);
	new_nbr->number = nbr;
	new_nbr->next = liste->first;
	liste->first = new_nbr;
	liste->size++;
}

void	insert_after(t_list *liste, long nbr)
{
	t_nbr	*new_nbr;
	t_nbr	*li_last;

	li_last = find_last(liste);
	new_nbr = malloc(sizeof(*new_nbr));
	if (liste == NULL || new_nbr == NULL)
		exit(0);
	new_nbr->number = nbr;
	new_nbr->next = NULL;
	li_last->next = new_nbr;
	liste->size++;
}

void	delete_last(t_list *stack)
{
	int		i;
	t_nbr	*li_cursor;
	t_nbr	*li_last;

	i = 2;
	li_cursor = stack->first;
	li_last = find_last(stack);
	while (i < stack->size)
	{
		li_cursor = li_cursor->next;
		i++;
	}
	li_cursor->next = NULL;
	stack->size--;
	free(li_last);
}

void	delete_first(t_list *stack)
{
	t_nbr	*li_pos;
	t_nbr	*li_next;

	li_pos = stack->first;
	li_next = li_pos->next;
	stack->first = li_next;
	stack->size--;
	free(li_pos);
}

void	free_list(t_list *liste)
{
	t_nbr	*to_delete;

	if (liste == NULL)
		exit(0);
	if (liste->first != NULL)
	{
		to_delete = liste->first;
		liste->first = liste->first->next;
		free(to_delete);
	}
}

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

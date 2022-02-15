/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_linked_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:10:52 by mreymond          #+#    #+#             */
/*   Updated: 2022/02/15 15:52:53 by mreymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list *list_init(long nbr)
{
    t_list *liste;
    t_nbr *number;

    liste = malloc(sizeof(*liste));
    number = malloc(sizeof(*number));
    if (liste == NULL || number == NULL)
        exit(0);
    number->number = nbr;
    number->next = NULL;
    liste->first = number;
    return (liste);
}

void insert_after(t_list *liste, long nbr)
{
    t_nbr *new_nbr;

    new_nbr = malloc(sizeof(*new_nbr));
    if (liste == NULL || new_nbr == NULL)
        exit(0);
    new_nbr->number = nbr;
    new_nbr->next = liste->first;
    liste->first = new_nbr;
}
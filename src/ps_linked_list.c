/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_linked_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreymond <mreymond@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:10:52 by mreymond          #+#    #+#             */
/*   Updated: 2022/02/15 18:02:39 by mreymond         ###   ########.fr       */
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
    liste->size = 1;
    return (liste);
}

void insert_befor(t_list *liste, long nbr)
{
    t_nbr *new_nbr;

    new_nbr = malloc(sizeof(*new_nbr));
    if (liste == NULL || new_nbr == NULL)
        exit(0);
    new_nbr->number = nbr;
    new_nbr->next = liste->first;
    liste->first = new_nbr;
    liste->size++;
}

void delete_last(t_list *stack)
{
    int i;
    t_nbr *li_cursor;
    t_nbr *li_last;

    i = 2;
    li_cursor = stack->first;
    li_last = stack->first;
    while (i < stack->size)
    {
        li_cursor = li_cursor->next;
        i++;
    }
    li_cursor->next = NULL;
    i = 1;
    while (i < stack->size)
    {
        li_last = li_last->next;
        i++;
    }
    stack->size--;
    free(li_last);
}

void free_list(t_list *liste)
{
    t_nbr *to_delete;

    if (liste == NULL)
        exit(0);
    if (liste->first != NULL)
    {
        to_delete = liste->first;
        liste->first = liste->first->next;
        free(to_delete);
    }
}

void afficherListe(t_list *liste)
{
    t_nbr *actuel;

    if (liste == NULL)
    {
        printf("ouin ouin\n");
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
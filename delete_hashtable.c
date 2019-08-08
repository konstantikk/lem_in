/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_hashtable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 18:28:37 by vlegros           #+#    #+#             */
/*   Updated: 2019/08/07 18:28:37 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void    del_elem(t_list **head)
{
    t_list *temp;

    temp = *head;
    while (temp)
    {
        *head = temp;
        ft_memdel((void**)&((t_node*)(temp->content))->name);
        ft_memdel(&temp->content);
        temp = temp->next;
        ft_memdel((void**)head);
    }
}

void    ht_delete(t_ht **hashtable)
{
    t_ht        *ht;
    const int   *data = (*hashtable)->loaded->data;
    const size_t length = (*hashtable)->loaded->length;
    int         i;

    ht = *hashtable;
    i = -1;
    while (++i < length)
        del_elem(&ht->table[data[i]]);
    free(ht->table);
    ft_int_vec_del(&ht->loaded);
    ft_memdel((void**)hashtable);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 18:28:37 by vlegros           #+#    #+#             */
/*   Updated: 2019/08/07 18:28:37 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int     insert_node(t_ht *hashtable, t_node *node)
{
    const unsigned long index = ft_hash((unsigned char*)node->name, hashtable->capacity);
    t_list              *temp;
    t_list              *new;

    temp = hashtable->table[index];
    if (!temp)
    {
        if (!(hashtable->table[index] = ft_lstnew(node, sizeof(node))))
            return (0);
        ft_int_vec_pushback(hashtable->loaded, (int)index);
    }
    else
    {
        if(!(new = ft_lstnew(node, sizeof(node))))
            return (0);
        ft_lstadd(&hashtable->table[index], new);
    }
    hashtable->size++;
    return (1);
}
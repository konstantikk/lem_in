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

int     ht_insert_node(t_ht *hashtable, t_node *node)
{
    unsigned long index;
    t_list              *temp;
    t_list              *new;

    if (ht_enlarge(hashtable)) {
        index = ft_hash((unsigned char*)node->name, hashtable->capacity);
        temp = hashtable->table[index];
        if (!temp) {
            if (!(hashtable->table[index] = ft_lstnew(NULL, 0)))
                return (0);
            hashtable->table[index]->content = node;
            if (ft_int_vec_pushback(hashtable->loaded, (int) index) != 1)
                return (0);
        } else {
            if (!(new = ft_lstnew(NULL, 0)))
                return (0);
            new->content = node;
            ft_lstadd(&hashtable->table[index], new);
        }
        hashtable->size++;
        return (1);
    }
    return (0);
}
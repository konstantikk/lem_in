/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 15:52:26 by vlegros           #+#    #+#             */
/*   Updated: 2019/09/10 15:52:26 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void        dijkstra(t_farm *farm)
{
    t_node *node;
    t_link *link;
    t_pvec *q = ft_ptr_vec_init();

    nullify(farm->nodes, BOTH);
    ft_ptr_vec_pushfront(q, farm->start);
    farm->start->level = 0;
    while (q->length)
    {
        node = ft_ptr_vec_popfront(q);
        for (int i = 0; (size_t)i < node->links->length; i++)
        {
             link = node->links->data[i];
             if (link->ptr->level > node->level + (link->direction + node->potential - link->ptr->potential) && link->flow != 1)
             {
                 ft_ptr_vec_pushfront(q, link->ptr);
                 link->ptr->level =  node->level + (link->direction + node->potential - link->ptr->potential);
                 link->ptr->parent = node;
             }
        }
    }
}
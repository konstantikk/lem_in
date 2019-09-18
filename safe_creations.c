/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_creations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 18:11:53 by vlegros           #+#    #+#             */
/*   Updated: 2019/09/14 22:35:55 by jziemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	safe_pushback(t_farm **farm, t_pvec *links, void *elem)
{
    if (!elem)
        finish_him(farm);
    if (ft_ptr_vec_pushback(links, elem) != 1)
        finish_him(farm);
}

void	safe_insert(t_farm **farm, t_ht *nodes, t_node *node)
{
    if (!node)
        finish_him(farm);
    if (!ht_insert_node(nodes, node))
    	finish_him(farm);
}

t_link	*safe_create_link(t_farm **farm, char *name)
{
    t_link *link;

    if (!name)
        finish_him(farm);
    if (!(link = create_link(name, (*farm)->nodes)))
        finish_him(farm);
    return (link);
}

void	safe_room_adding(t_farm **farm_ptr, t_path **path_ptr,
		void *elem, t_pvec **flow)
{
    t_path *path;

    path = *path_ptr;
    if (!elem)
    {
        ft_ptr_vec_del(flow, del_path);
        finish_him(farm_ptr);
    }
    if (ft_ptr_vec_pushback(path->path, elem) != 1)
    {
        ft_ptr_vec_del(flow, del_path);
        finish_him(farm_ptr);
    }
}

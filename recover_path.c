/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recover_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 18:05:31 by vlegros           #+#    #+#             */
/*   Updated: 2019/08/11 18:05:31 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void    check_links(t_node **node_ptr, t_path **path, t_farm **farm_ptr, t_pvec **flow)
{
    register int i;
    t_link  *forward_link;
    t_node  *node;

    i = -1;
    node = *node_ptr;
    while ((size_t)++i < node->links->length)
    {
        forward_link = node->links->data[i];
        if (forward_link->direction == 1 && forward_link->flow == 1)
        {
            if (forward_link->name[0] != 'L')
                safe_room_adding(farm_ptr, path, create_room(forward_link->name, forward_link->ptr), flow);
            *node_ptr = forward_link->ptr;
            break ;
        }
    }
}

void	ft_recover_path(t_farm **farm_ptr, t_link *link, t_pvec **flow)
{
    t_path	*path;
    t_node *node;
    t_farm *farm;

    farm = *farm_ptr;
    if (!(path = create_path()))
        finish_him(farm_ptr);
    node = link->ptr;
    while (node != farm->end)
       check_links(&node, &path, farm_ptr, flow);
    //safe_room_adding(farm_ptr, &path, create_room(farm->end->name), flow);
    if (ft_ptr_vec_pushback(*flow, path) != 1)
    {
        ft_ptr_vec_del(flow, del_path);
        finish_him(farm_ptr);
    }
}

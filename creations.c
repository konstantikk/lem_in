/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 18:06:48 by vlegros           #+#    #+#             */
/*   Updated: 2019/09/14 22:27:02 by jziemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_node		*create_node(char *name)
{
	t_node *node;

	if (!(node = (t_node*)malloc(sizeof(t_node))))
		return (NULL);
	node->name = name;
	if (!(node->links = ft_ptr_vec_init()))
	{
		ft_memdel((void**)&node);
		return (NULL);
	}
	node->level = -1;
	node->potential = 0;
	return (node);
}

t_link		*create_link(char *name, t_ht *nodes)
{
	t_link *link;

	if (!(link = (t_link*)malloc(sizeof(t_link))))
		return (NULL);
	link->name = name;
	link->flow = 0;
	link->ptr = ht_find_node(nodes, name);
	link->direction = 1;
	return (link);
}

t_path		*create_path(void)
{
	t_path *path;

	path = (t_path*)malloc(sizeof(t_path));
	if (!(path->path = ft_ptr_vec_init()))
	{
		ft_memdel((void**)&path);
		return (NULL);
	}
	path->ants_onw = 0;
	path->last_occupied = 0;
	path->fixed_ant_num = 0;
	return (path);
}

t_room		*create_room(char *name, t_node *node_ptr)
{
	t_room *room;

	if (!(room = (t_room*)malloc(sizeof(t_room))))
		return (NULL);
	room->temp_ant = -1;
	room->name = name;
	room->ptr = node_ptr;
	return (room);
}

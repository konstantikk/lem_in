/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dfs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziemann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 21:54:50 by jziemann          #+#    #+#             */
/*   Updated: 2019/09/15 18:29:19 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_link	*find_link(t_pvec *links, t_node *name)
{
	const size_t	len = links->length;
	const void		**data = (const void**)links->data;
	register int	i;

	i = -1;
	while ((size_t)++i < len)
		if (((t_link*)data[i])->ptr == name)
			return ((t_link*)data[i]);
	return (NULL);
}

static void		add_new_link(t_node *node, t_link *child_link_to_parent,
		t_farm **farm_ptr)
{
	ft_ptr_vec_pushback(node->links,
			safe_create_link(farm_ptr, ft_strdup(node->parent->name)));
	child_link_to_parent = node->links->data[node->links->length - 1];
	child_link_to_parent->flow = -1;
	child_link_to_parent->direction = -1;
}

void			ft_add_path(t_farm **farm_ptr)
{
	t_node *node;
	t_link *child_link_to_parent;
	t_link *parent_link_to_child;
	t_farm *farm;

	farm = *farm_ptr;
	node = farm->end;
	while (node != farm->start)
	{
		child_link_to_parent = find_link(node->links, node->parent);
		parent_link_to_child = find_link(node->parent->links, node);
		if (node == farm->end)
			add_new_link(node, child_link_to_parent, farm_ptr);
		else if (!child_link_to_parent)
			add_new_link(node, child_link_to_parent, farm_ptr);
		else
			child_link_to_parent->flow = -1;
		parent_link_to_child->flow = 1;
		parent_link_to_child->direction = 1;
		node = node->parent;
	}
}

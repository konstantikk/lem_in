/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dfs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziemann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 21:54:50 by jziemann          #+#    #+#             */
/*   Updated: 2019/08/10 21:54:50 by jziemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_link	*find_link(t_pvec *links, t_node *name)
{
	const size_t len = links->length;
	const void **data = (const void**)links->data;
	register int i;

	i = -1;
	while ((size_t)++i < len)
		if (((t_link*)data[i])->ptr == name)
			return ((t_link*)data[i]);
	return (NULL);
}

static void	ft_add_path(t_farm **farm_ptr)
{
	t_node *node;
	t_link *parent_link;
	t_link *child_link;
	t_farm *farm;

	farm = *farm_ptr;
	node = farm->end;
	while (node != farm->start)
	{
		parent_link = find_link(node->links, node->parent);
		child_link = find_link(node->parent->links, node);
		if (node->name[0] == 'L' || node == farm->end)
		{
			if (!parent_link)
			{
				ft_ptr_vec_pushback(node->links, safe_create_link(farm_ptr, node->parent->name));
				parent_link = node->links->data[node->links->length - 1];
				parent_link->capacity = 0;
				parent_link->flow = -1;
			}
			child_link->flow = 1;
		}
		else
		{
			child_link->flow = 1;
			parent_link->flow = -1;
		}
		node = node->parent;
	}
}

static void	dfs_mark_link(t_farm *farm, t_pvec *q, t_node *check_elem, int i)
{
	t_node *mark_node;
	const t_link *link = check_elem->links->data[i];

	mark_node = ht_find_node(farm->nodes, link->name);
	if (mark_node->used == FALSE && mark_node->level == check_elem->level + 1
			&& link->flow != 1 && mark_node->level <= farm->fixed)
	{
		mark_node->used = TRUE;
		mark_node->parent = check_elem;
		ft_ptr_vec_pushback(q, mark_node);
	}
}

int		ft_dfs(t_farm **farm_ptr)
{
	t_pvec *q;
	t_farm *farm;
	t_node	*check_elem;
	register int i;

	farm = *farm_ptr;
	nullify(farm->nodes, USED);
	farm->start->used = TRUE;
	if (!(q = ft_ptr_vec_init()))
		finish_him(farm_ptr);
	if (ft_ptr_vec_pushback(q, farm->start) != 1)
	{
		//del
		finish_him(farm_ptr);
	}
	while (q->length)
	{
		check_elem = ft_ptr_vec_popfront(q);
		if (check_elem == farm->end)
		{
			ft_add_path(farm_ptr);
			return (1);
		}
		i = -1;
		while ((size_t)++i < check_elem->links->length)
			dfs_mark_link(farm, q, check_elem, i);
	}
	return (0);
}
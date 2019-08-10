/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bfs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziemann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 20:43:00 by jziemann          #+#    #+#             */
/*   Updated: 2019/08/10 20:43:00 by jziemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	nullify(t_ht *nodes, int level_or_used)
{
	const int *data = nodes->loaded->data;
	const size_t *len = nodes->loaded->length;
	register int i;
	t_list		*temp;

	i = -1;
	while ((size_t)++i < len)
	{
		temp = nodes->table[data[i]];
		while (temp)
		{
			if (level_or_used == BOTH)
				((t_node*)(temp->content))->level = -1;
			((t_node*)(temp->content))->used = FALSE;
			temp = temp->next;
		}
	}
}

static void	bfs_mark_link(t_ht *nodes, t_pvec *q, t_node *check_elem, int i)
{
	t_node *mark_node;
	const t_link	*link = check_elem->links->data[i];

	mark_node = ht_find_node(nodes, link->name);
	if (mark_node->used == FALSE && link->flow != 1)
	{
		mark_node->used = TRUE;
		mark_node->level = check_elem->level + 1;
		ft_ptr_vec_pushback(q, mark_node);
	}
}

int		ft_bfs(t_farm **farm_ptr)
{
	t_pvec *q;
	t_farm	*farm;
	t_node	*check_elem;
	register int i;

	farm = *farm_ptr;
	nullify(farm->nodes, BOTH);
	farm->start->used = TRUE;
	if (!(q = ft_ptr_vec_init()))
		finish_him(farm_ptr);
	if (ft_ptr_vec_pushback(q, farm->start) != 1)
	{
		//del vec
		finish_him(farm_ptr);
	}
	while (q->length)
	{
		check_elem = ft_ptr_vec_popfront(q);
		i = -1;
		while ((size_t)++i < check_elem->links->length)
			bfs_mark_link(farm->nodes, q, check_elem, i);
	}
	farm->fixed = farm->end->level; //mark line
	return (farm->end->level != -1);
}
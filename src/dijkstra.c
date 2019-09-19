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

void	check_links(t_node *node, t_pvec **q_ptr, t_farm **farm_ptr)
{
	t_link			*link;
	t_pvec			*q;
	int				weight;
	register int	i;

	q = *q_ptr;
	i = -1;
	while ((size_t)++i < node->links->length)
	{
		link = node->links->data[i];
		weight = node->level +
				(link->direction + node->potential - link->ptr->potential);
		if (link->ptr->level > weight && link->flow != 1)
		{
			link->ptr->level = weight;
			link->ptr->parent = node;
			if (ft_ptr_vec_pushback(q, link->ptr) != 1)
			{
				free(q->start_data);
				ft_memdel((void**)q_ptr);
				finish_him(farm_ptr);
			}
			sift_up(q->data, q->length - 1);
		}
	}
}

void	dijkstra(t_farm **farm_ptr)
{
	t_pvec *q;
	t_farm *farm;

	farm = *farm_ptr;
	if (!(q = ft_ptr_vec_init()))
		finish_him(farm_ptr);
	nullify(farm->nodes);
	if (ft_ptr_vec_pushback(q, farm->start) != 1)
	{
		free(q->start_data);
		ft_memdel((void**)&q);
		finish_him(farm_ptr);
	}
	farm->start->level = 0;
	while (q->length)
		check_links(pop_min(q), &q, farm_ptr);
	free(q->start_data);
	ft_memdel((void**)&q);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 16:30:17 by vlegros           #+#    #+#             */
/*   Updated: 2019/09/14 22:24:00 by jziemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_flow	*ft_get_flow(t_farm **farm_ptr)
{
	register int	i;
	t_pvec			*flow;
	t_farm			*farm;
	t_link			*link;
	t_flow			*temp_flow;

	farm = *farm_ptr;
	i = -1;
	if (!(flow = ft_ptr_vec_init()))
		finish_him(farm_ptr);
	while ((size_t)++i < farm->start->links->length)
	{
		link = farm->start->links->data[i];
		if (link->flow == 1 && link->direction == 1)
			ft_recover_path(farm_ptr, link, &flow);
	}
	sort_flow(flow, flow->length, flow->length - 1);
	if (!(temp_flow = (t_flow *)malloc(sizeof(t_flow))))
		finish_him(farm_ptr);
	temp_flow->flow = flow;
	temp_flow->len_flow = flow->length;
	if (!(temp_flow->ants_allocation = (int *)ft_memalloc(sizeof(int) * flow->length)))
	{
		//del flow
		finish_him(farm_ptr);
	}
	ft_ptr_vec_pushback(farm->all_flows, temp_flow);
	return (temp_flow);
}

void	recalculate_potentials(t_ht *nodes)
{
	const int		*data = nodes->loaded->data;
	const size_t	len = nodes->loaded->length;
	register int	i;
	t_list			*temp;

	i = -1;
	while ((size_t)++i < len)
	{
		temp = nodes->table[data[i]];
		while (temp)
		{
			((t_node*)(temp->content))->potential += ((t_node*)(temp->content))->level;
			temp = temp->next;
		}
	}
}

int		new_alg(t_farm **farm_ptr)
{
	t_farm *farm;

	farm = *farm_ptr;
	dijkstra(farm_ptr);
	while (farm->end->level != INF)
	{
		recalculate_potentials(farm->nodes);
		ft_add_path(farm_ptr);
		if (!ft_release_flow(farm_ptr))
			return (0);
		dijkstra(farm_ptr);
	}
	return (1);
}

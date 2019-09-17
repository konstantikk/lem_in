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
			((t_node*)(temp->content))->potential +=
					((t_node*)(temp->content))->level;
			temp = temp->next;
		}
	}
}

int		get_optimal_flow(t_farm **farm_ptr)
{
	t_farm *farm;

	farm = *farm_ptr;
	if (farm->direct_path == TRUE)
	{
		direct_path(farm_ptr);
		return (0);
	}
	dijkstra(farm_ptr);
	if (farm->end->level == INF)
		finish_him(farm_ptr);
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

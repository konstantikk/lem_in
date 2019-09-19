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

void	direct_path(t_farm **farm_ptr)
{
	t_farm			*farm;
	register int	i;

	i = -1;
	farm = *farm_ptr;
	if (farm->fast == FALSE)
		while (++i < farm->ant_num)
			push_room_with_ant(farm_ptr, i + 1, farm->end->name);
}

int		get_optimal_flow(t_farm **farm_ptr)
{
	t_farm *farm;

	farm = *farm_ptr;
	if (!farm->nodes || !farm->start || !farm->end)
		finish_him(farm_ptr);
	if (farm->direct_path == TRUE)
	{
		if (farm->fast == TRUE)
			farm->num_of_lines = 1;
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vera <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 12:19:22 by vera              #+#    #+#             */
/*   Updated: 2019/08/21 12:19:22 by vera             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"


static void dijkstra_mark_link(t_farm *farm, t_node *check_elem, int i, int min)
{
	t_node	*mark_node;
	const t_link	*link = check_elem->links->data[i];

	mark_node = ht_find_node(farm->nodes, link->name);
	//printf("%s \n", mark_node->name);
	if (link->flow != 1 && mark_node->level > link->weight + min)
	{
		mark_node->level = link->weight + min;
	}
}

int		dijkstra(t_farm *farm)
{
	register int	i;
	const int *data = farm->nodes->loaded->data;
	const size_t len = farm->nodes->loaded->length;
	t_list		*temp;
	t_node	*min_node;

	nullify(farm->nodes, USED);
	min_node = (t_node *)malloc(sizeof(t_node));
	min_node->level = 1000000;
	farm->start->level = 0;// len==level d[s] = 0;
	for (int k = 0; (size_t)k < len; k++)
	{
		i = -1;
		min_node->level = 1000000;
		while ((size_t)++i < len)
		{
			temp = farm->nodes->table[data[i]];
			while (temp)
			{
				printf("[%s] level: %d\n",((t_node *)(temp->content))->name,((t_node *)(temp->content))->level);
				if (((t_node *)(temp->content))->used == 0 && ((t_node *)(temp->content))->level < min_node->level)
				{
					min_node = ((t_node *)(temp->content));
				}
				temp = temp->next;
			}
		}
		min_node->used = 1;
		if (min_node == farm->end)
			return (1);
		else if (min_node->level == 1000000)///
			return (0);////
		i = -1;
		while ((size_t)++i < min_node->links->length)
		{
			dijkstra_mark_link(farm, min_node, i, min_node->level);
		}
		printf("_________________________\n");
	}
	return (0);
}

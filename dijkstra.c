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
	if (link->flow != 1 && mark_node->level >= link->weight + min)
	{
		mark_node->level = link->weight + min;
		mark_node->parent = check_elem;
	}
}

void	dijkstra_potentials(t_farm *farm)
{
	const int *data = farm->nodes->loaded->data;
	const size_t len = farm->nodes->loaded->length;
	t_list		*temp;
	register int i;

	i = -1;
	while ((size_t)++i < len)
	{
		temp = farm->nodes->table[data[i]];
		while (temp)
		{

			int node_u = ((t_node*)(temp->content))->level;
			for (int j = 0; j < ((t_node*)(temp->content))->links->length; j++)
			{
				t_link	*link = ((t_node*)(temp->content))->links->data[j];
				t_node *node_v = ht_find_node(farm->nodes, link->name);
				//printf("weight: %d\n", link->weight);
				if (node_u < 1000000 && node_v->level < 1000000)
					link->weight = link->weight + node_u - node_v->level + 1;
			}
			temp = temp->next;
		}
	}

	//printf("len path:%d\n", farm->end->level);
}

int		dijkstra(t_farm *farm)
{
	register int	i;
	const int *data = farm->nodes->loaded->data;
	const size_t len = farm->nodes->size;
	t_list		*temp;
	t_node	*min_node;
	int     min;

	nullify(farm->nodes, BOTH);
	farm->start->level = 0;
	for (int j = 0; j < len; j++)
    {
	    i = -1;
	    min_node = NULL;
	    min = 100000;
	    while (++i < farm->nodes->loaded->length)
        {
	        temp = farm->nodes->table[data[i]];
	        while (temp)
            {
	            if (!min_node && ((t_node*)(temp->content))->used == FALSE)
                {
	                min_node = temp->content;
                    min = ((t_node*)(temp->content))->level;
                    min_node->level = min;
                }
	            else if (((t_node*)(temp->content))->used == FALSE && ((t_node*)(temp->content))->level < min)
                {
	                min_node = temp->content;
	                min = ((t_node*)(temp->content))->level;
	                min_node->level = min;
                }
	            temp = temp->next;
            }
        }
	    i = -1;
	    min_node->used = TRUE;
	    while (++i < min_node->links->length)
        {
	        dijkstra_mark_link(farm, min_node, i, min);
        }
	    if (min_node != farm->start)
	    /// printf("child name: %s parent name: %s\n", min_node->name,  min_node->parent ? min_node->parent->name : NULL);
        if (min_node == farm->end)
            return (1);
        else if (min == 100000)
            return (0);
    }
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 16:30:17 by vlegros           #+#    #+#             */
/*   Updated: 2019/07/28 16:30:17 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

#define NODE(i) ((t_node*)(((void**)(farm->nodes->data))[i]))
#define LINK(i, j) ((t_link*)((void**)((t_node*)((void**)(farm->nodes->data))[i])->links->data)[j])
#define SUBSTREAM(i) ((t_sub_stream*)(((void**)farm->mainstream->data)[i]))

int 	bfs(t_farm *farm)
{
	t_ivec	*q = ft_int_vec_init();
	static int flag = FALSE;

	for (int i = 0; (size_t)i < farm->nodes->length; i++)
	{
		farm->levels[i] = -1;
		farm->used[i] = FALSE;
	}
	farm->used[farm->start] = TRUE;
	ft_int_vec_pushback(q, farm->start);
	while (q->length)
	{
		int	check_elem = ft_int_vec_popfront(q);
		for (int i = 0; (size_t)i < NODE(check_elem)->links->length; i++)
		{
			if (!farm->used[LINK(check_elem, i)->index] && LINK(check_elem, i)->capacity)
			{
				farm->used[LINK(check_elem, i)->index] = TRUE;
				ft_int_vec_pushback(q,LINK(check_elem, i)->index);
				farm->levels[LINK(check_elem, i)->index] = farm->levels[check_elem] + 1;
			}
		}
	}
	if (!flag)
	{
		farm->fixed = farm->levels[farm->end];
		flag  = TRUE;
		ft_ptr_vec_pushback(farm->mainstream, create_substream(farm));
	}
	return (farm->levels[farm->end] != -1);
}

int 		min_fl(int val1, int val2)
{
	if (val1 < val2)
		return val1;
	return val2;
}

int 		ft_find_index(t_farm *farm, int parent,int val)
{
	for (int i = 0; i < NODE(parent)->links->length; i++)
		if (LINK(parent, i)->index == val)
			return (i);
	return (-1);
}

/**
 * creating array sizeof farm->fixed + 1 because we storing the last(end_node) as well
 *
 */
void		add_path(t_farm *farm)
{
	int 	vertex = farm->end;
	int 	j = farm->fixed;
	int 	*path = (int*)malloc(sizeof(int) * farm->fixed + 1);

	while (vertex != farm->start)
	{
		path[j--] = vertex;
		LINK(farm->parents[vertex], ft_find_index(farm, farm->parents[vertex], vertex))->capacity = 0;
		vertex = farm->parents[vertex];
	}
	ft_ptr_vec_pushback(SUBSTREAM(farm->mainstream->length - 1)->stream, path);
}

int 		dfs(t_farm *farm)
{
	int i;
	t_ivec	*s = ft_int_vec_init();
	int	node;

	ft_memset(farm->used, 0, sizeof(int) * farm->nodes->length);
	farm->used[farm->start] = TRUE;
	ft_int_vec_pushback(s, farm->start);
	while (s->length > 0)
	{
		node = ft_int_vec_popfront(s);
		i = 0;
		if (node == farm->end)
		{
			add_path(farm);
			return (1);
		}
		while ((size_t)i < NODE(node)->links->length)
		{
			if (!farm->used[LINK(node, i)->index] && LINK(node, i)->capacity && farm->levels[LINK(node, i)->index] == farm->levels[node] + 1 && farm->levels[LINK(node, i)->index] <= farm->fixed)
			{
				ft_int_vec_pushback(s, LINK(node, i)->index);
				farm->used[LINK(node, i)->index] = TRUE;
				farm->parents[LINK(node, i)->index] = node;
			}
			i++;
		}
	}
	farm->fixed += 2;
	ft_ptr_vec_pushback(farm->mainstream, create_substream(farm));
	return (0);
}

void	debuf_dinic(t_farm *farm)
{
	for (int i = 0; i < farm->nodes->length; i++)
	{
		printf("|index: %10d| |name: %10s| ", i ,NODE(i)->name);
		for (int j = 0; j < NODE(i)->links->length; j++)
			printf("|%d|->%d ", LINK(i, j)->index, LINK(i, j)->capacity);
		printf("\n");
	}
	printf("\n");
	for (int i = 0; i < farm->mainstream->length - 1; i++)
	{
		printf("%d stream\n", i);
		for (int j = 0; j <  SUBSTREAM(i)->stream->length; j++)
		{
			for (int m = 0; m < SUBSTREAM(i)->flow_size; m++)
				printf("%d->", *((int*)(((void**)SUBSTREAM(i)->stream->data)[j]) + m));
			printf("\n");
		}
		printf("\n\n");
	}
}

int 	dinic(t_farm *farm)
{
	int max_flow = 0;
	int flow;

	while (bfs(farm))
	{
		flow = dfs(farm);
		while (flow)
		{
			max_flow += flow;
			flow = dfs(farm);
		}
	}
	debuf_dinic(farm);
	return max_flow;
}
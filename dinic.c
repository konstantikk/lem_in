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
int			INF = 1000000000;

void	recover_path(int *parents, int end)
{
	t_ivec *path = ft_int_vec_init();

//	for (int i = 0; i < ft_strlen((char*)parents) / sizeof(int); i++)
//		printf("%d ", parents[i]);
	for (int i = end; i != -1; i = parents[i])
		ft_int_vec_pushback(path, i);
	for (size_t i = 0; i < path->length; i++)
		printf("%d->", path->data[i]);
}

int 	bfs(t_farm *farm)
{
	t_ivec	*q = ft_int_vec_init();

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
//	for (int i = 0; i < farm->nodes->length; i++)
//		printf("|%d| ", farm->levels[i]);
//	printf("\n");
	return (farm->levels[farm->end] != -1);
}

int 		min_fl(int val1, int val2)
{
	if (val1 < val2)
		return val1;
	return val2;
}

int 		dfs(t_farm *farm, int node, int min_flow)
{
	int flow;

	if ((size_t)node == farm->end || min_flow == 0)
		return min_flow;
	for (int i = 0; i < NODE(node)->links->length; i++)
		if (farm->levels[LINK(node, i)->index] == farm->levels[node] + 1)
		{
			printf("path:%d->", LINK(node, i)->index);
			flow = dfs(farm, LINK(node, i)->index, min_fl(min_flow, LINK(node, i)->capacity));
			LINK(node, i)->capacity = 0;
			return flow;
		}
	return (0);
}

int 	dinic(t_farm *farm)
{
	int max_flow = 0;
	int flow;

	while (bfs(farm))
	{
		flow = dfs(farm, farm->start, INF);
		printf("\n");
		while (flow)
		{
			max_flow += flow;
			flow = dfs(farm, farm->start, INF);
			printf("\n");
		}
	}
	for (int i = 0; i < farm->nodes->length; i++)
	{
		printf("|index: %10d| |name: %10s| ", i ,NODE(i)->name);
		for (int j = 0; j < NODE(i)->links->length; j++)
			printf("|%d|->%d ", LINK(i, j)->index, LINK(i, j)->capacity);
		printf("\n");
	}
	return max_flow;
}
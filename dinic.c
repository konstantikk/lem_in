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


int 		iterative_dfs(t_farm *farm)
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

			return (1);
		}
		while ((size_t)i < NODE(node)->links->length)
		{
			if (!farm->used[i] && LINK(node, i)->capacity && farm->levels[LINK(node, i)->index] == farm->levels[node] + 1&&
				farm->levels[LINK(node, i)->index] <= farm->fixed)
			{
				ft_int_vec_pushback(s, LINK(node, i)->index);
				farm->used[i] = TRUE;
				farm->parents[i] = node;
			}
			i++;
		}
	}
	farm->fixed++;
	return (0);
}

int 		dfs(t_farm *farm, int node, int min_flow)
{
	int flow;
	int i;

	if ((size_t)node == farm->end || min_flow == 0)
		return min_flow;
	i = 0;
	while ((size_t)i < NODE(node)->links->length)
	{
		if (LINK(node, i)->capacity && farm->levels[LINK(node, i)->index] == farm->levels[node] + 1 &&
				farm->levels[LINK(node, i)->index] <= farm->fixed)
		{
			printf("%d->", LINK(node, i)->index);
			if (LINK(node, i)->index == farm->end)
				printf("good");
			flow = dfs(farm, LINK(node, i)->index, min_fl(min_flow, LINK(node, i)->capacity));
			if (!flow)
			{
				printf("stop\n");
		//		printf("\n");
				i++;
				continue ;
			}
			LINK(node, i)->capacity = 0;
			return (flow);
		}
		i++;
	}
	farm->fixed++;
	return (0);
}

int 	dinic(t_farm *farm)
{
	int max_flow = 0;
	int flow;

	while (bfs(farm))
	{
		//printf("path: ");
		flow = iterative_dfs(farm);///dfs(farm, farm->start, INF);
		printf("\n");
		while (flow)
		{
			max_flow += flow;
			//printf("path: ");
			flow = iterative_dfs(farm);///dfs(farm, farm->start, INF);
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
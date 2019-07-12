/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 17:24:26 by vlegros           #+#    #+#             */
/*   Updated: 2019/07/12 17:24:26 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int dim = 7;
int dim2 = 5;
const int INF = 1000000000;



void	dijkstra(int g[dim2][dim2])
{

}



t_ivec 	*bfs(int g[dim][dim], int source)
{
	t_ivec *queue = ft_int_vec_init();
	int 	*d = (int*)malloc(sizeof(int) * 7);
	int		temp;
	t_ivec *path = ft_int_vec_init();

	ft_bzero((void*)d, sizeof(int) * 7);
	d[source] = 1;
	ft_int_vec_pushback(queue, 0);
	while (queue->length)
	{
		temp = ft_int_vec_popfront(queue);
		for (int i = 0; i < 7; i++)
			if (!d[i] && g[temp][i])
			{
				d[i] = 1;
				ft_int_vec_pushback(queue, i);
				ft_int_vec_pushback(path, i);
			}
	}
	return (path);
}


void create_elem(t_vec *new_elem, int to, int weight)
{

	t_pair *new = (t_pair*)malloc(sizeof(t_pair));

	new->weight = weight;
	new->node = to;

	ft_ptr_vec_pushback(new_elem, new);
}

int		main(void)
{
	int num_of_nodes;
	t_vec **g;

	printf("num of nodes: ");
	scanf("%d", &num_of_nodes);
	g = (t_vec**)malloc(sizeof(t_vec*) * num_of_nodes);
	for (int i = 0; i < num_of_nodes; i++)
	{
		g[i] = ft_ptr_vec_init();
		printf("num of edges for %d node", i + 1);
		int num_of_edges;
		scanf("%d", &num_of_edges);
		for (int j = 0; j < num_of_edges; j++)
		{
			printf("node and weight: ");
			int node, weight;
			scanf("%d%d", &node, &weight);
			create_elem(g[i], node, weight);
		}
		printf("\n");
	}
	for (int i = 0; i < num_of_nodes; i++)
	{
		printf("for %d node\n", i + 1);
		for (int j = 0; (size_t)j < g[i]->length; j++)
			printf("node: %d weight: %d\n", ((t_pair*)g[i]->data)->node, ((t_pair*)g[i]->data)->weight);
		printf("\n");
	}
	return (0);
}
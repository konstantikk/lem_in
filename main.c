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
int dim2 = 7;
const int INF = 1000000000;

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

void	dijkstra(int w[dim2][dim2])
{
	int *dist = (int*)malloc(sizeof(int) * dim2);
	int *used = (int*)malloc(sizeof(int) * dim2);
	int min_dist = 0;
	int start_vertex = 0;

	for (int i = 0; i < dim2; i++)
	{
		dist[i] = INF;
		used[i] = 0;
	}
	dist[0] = 0;
	while (min_dist != INF)
	{
		int i = start_vertex;
		used[i] = 1;
		for (int j = 0; j < dim2; j++)
			if (dist[i] + w[i][j] < dist[j])
				dist[j] = dist[i] + w[i][j];
		min_dist = INF;
		for (int j = 0; j < dim2; j++)
			if (!used[j] && dist[j] < min_dist)
			{
				min_dist = dist[j];
				start_vertex = j;
			}
	}
	for (int i = 0; i < dim2; i++)
		printf("%d->", dist[i]);

}

int		main(void)
{
	int mas[7][7] = { { INF, 5, 10, INF, INF, INF, 4 }, // 0 матрица смежности
					  { 5, INF, 1, 7, INF, INF, INF }, //1
					  { 10, 1, INF, INF, INF, INF, INF }, //2
					  { INF, 7, INF, INF, 3, INF, INF }, //3
					  { INF, INF, INF, 3, INF, 6, INF }, //4
					  { INF, INF, INF, INF, 6, INF, 4 }, //5
					  { 4, INF, INF, INF, INF, 4, INF } }; //6
	dijkstra(mas);
	return (0);
}
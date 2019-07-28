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
	int		*used = (int*)malloc(sizeof(int) * farm->nodes->length);
	int		*levels = (int*)malloc(sizeof(int) * farm->nodes->length);
	int		*parents = (int*)malloc(sizeof(int) * farm->nodes->length);

	for (size_t i = 0; i < farm->nodes->length; i++)
	{
		used[i] = FALSE;
		levels[i] = 0;
		parents[i] = 0;
	}
	used[farm->start] = TRUE;
	parents[farm->start] = -1;
	ft_int_vec_pushback(q, farm->start);
	while (q->length)
	{
		int	check_elem = ft_int_vec_popfront(q);
		for (int i = 0; (size_t)i < NODE(check_elem)->links->length; i++)
		{
			if (!used[NODE(check_elem)->links->data[i]])
			{
				used[NODE(check_elem)->links->data[i]] = TRUE;
				ft_int_vec_pushback(q,NODE(check_elem)->links->data[i]);
				levels[NODE(check_elem)->links->data[i]] = levels[check_elem] + 1;
				parents[NODE(check_elem)->links->data[i]] = check_elem;
			}
		}
	}
	return (1);
}

void	dfs_helper(t_farm *farm, int *used, int node, int end)
{
	if (node == end)
		return ;
	used[node] = TRUE;
	printf("%d->", node);
	for (int i = 0; (size_t)i < NODE(node)->links->length; i++)
		if (!used[NODE(node)->links->data[i]])
			dfs_helper(farm, used, NODE(node)->links->data[i], end);
}

int 		dfs(t_farm *farm)
{
	int *used = (int*)malloc(sizeof(int) * farm->nodes->length);

	for (int i = 0; (size_t)i < farm->nodes->length; i++)
		used[i] = FALSE;
	dfs_helper(farm, used, farm->start, farm->end);
	return (1);
}


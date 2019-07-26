/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziemann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 20:11:10 by jziemann          #+#    #+#             */
/*   Updated: 2019/07/25 20:11:10 by jziemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int 	find_start(t_node *vec)
{
	int i;

	i = -1;
	while (++i < (int)vec->len)
	{
		if (vec->links[i]->start)
			return (i);
	}
	return (-1);
}

void 	bfs(t_node *vec)
{
	int start = find_start(vec);
	t_link	*q;
	int id;
	int to;
//	char 	*vertex;


	q = ft_makevec();
	ft_vec_push_back(q, vec->name_vertex[start]);
	vec->parent[start] = -1;
	while (q->len)
	{
		///printf("q->len: %zu\n\n", q->len);
		id = ft_vec_return(ft_vec_pop_front(q), vec);
		for (int i = 0; i < (int)vec->links[id]->len; i++)
		{
			//printf("%s\n", vec->links[id]->name[i]);

				to = ft_vec_return(vec->links[id]->name[i], vec);
			if (!vec->used[to])
			{
				vec->used[to] = '1';
				ft_vec_push_back(q, vec->name_vertex[to]);
				//printf("%s\n", vec->name_vertex[to]);
				vec->parent[to] = id;
				vec->cost[to] = vec->cost[id] + 1;///need added d[] distanation d[to] = d[v] + 1 if is end level unnecessary
			}
		}

	}///PATCH
	int end;
	end = 0;
	for (int i=0; i <(int) vec->len; i++)
		if (vec->links[i]->end == '1')
		{
			end = i;
			break ;
		}
	for (int v = end; v!= -1; v = vec->parent[v])
	{
		printf("%s<--", vec->name_vertex[v]);
	}

	///end patch
	for (int i = 0 ; i < (int)vec->len; i++)
	{
		printf("\nname: %3s\t used: %c\t parent: %d\t level: %d\tlinks: ", vec->name_vertex[i], vec->used[i], vec->parent[i], vec->cost[i]);
		for (int j = 0; j < (int)vec->links[i]->len; j++)
		{
			printf("[%s] ",vec->links[i]->name[j]);
		}
		printf("\n");
	}
	printf("\n\n\n");
}
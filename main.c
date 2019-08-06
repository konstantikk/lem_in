/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 19:57:35 by vlegros           #+#    #+#             */
/*   Updated: 2019/07/26 19:57:35 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	debug(t_farm *farm)
{
	for (int i = 0; (size_t)i < farm->nodes->length; i++)
	{
		printf("%s\t", ((t_node*)(((void**)(farm->nodes->data))[i]))->name);
		for (int j = 0; (size_t)j < ((t_node*)(((void**)(farm->nodes->data))[i]))->links->length; j++)
			printf("|%d| ", ((t_link*)((void**)((t_node*)((void**)(farm->nodes->data))[i])->links->data)[j])->index);
		printf("\n");
	}

	printf("\n%zu, %zu\n", farm->start, farm->end);
}

int 	main(int argc, char **argv)
{
	t_farm *farm;
	t_vec *flow;
	int *array;
	int fd = open(argv[1], O_RDONLY);
	farm = parse(0);
//	debug(farm);
//	bfs(farm);
//	dfs(farm);
	if (dinic(farm) > 0)
	{
		//printf("AAA\n");
		flow = get_flow(farm);
		array = check_profit(farm, flow, farm->max_path);
		let_the_flow_go(farm, flow, farm->ant_num, array);
		//start
	}
	close(fd);
	return (0);
}
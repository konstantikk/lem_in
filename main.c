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
	int fd = open(argv[1], O_RDONLY);
	farm = parse(0);
	debug(farm);
//	bfs(farm);
//	dfs(farm);
	printf("max_flow: %d", dinic(farm));
	close(fd);
	return (0);
}
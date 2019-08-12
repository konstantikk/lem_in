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

void    finish_him(t_farm **farm)
{
    write(2, "Error\n", 6);
    free_memory(farm);
    exit(-1);
}

int     debug(t_farm *to_del)
{
    t_list **table = to_del->nodes->table;
    for (int i = 0; i < to_del->nodes->loaded->length; i++) {
        t_list *temp = table[to_del->nodes->loaded->data[i]];
        printf("index %d\n", to_del->nodes->loaded->data[i]);
        while (temp) {
            printf("|%5s %5p|->", ((t_node *) temp->content)->name, ((t_node *) temp->content));
            printf("links: ");
            for (int j = 0; j < ((t_node *) temp->content)->links->length; j++)
			{
            	t_link *link = (((t_node *) temp->content)->links->data[j]);
            	if (link->capacity == 1 && link->flow == 1)
            	printf("|name: %s capacity: %d flow: %d ptr: %p| ", link->name, link->capacity, link->flow, link->ptr);
			}
            printf("\n");
            temp = temp->next;
        }
        printf("\n");
    }
}

int 	main(int argc, char **argv)
{
	t_farm *farm;
	t_pvec *flow;
	int 	*ants_allocation;
	int fd = open(argv[1], O_RDONLY);
	farm = parse(0);
	if (ft_dinic(&farm))
	{
		if (!(ants_allocation = (int *)ft_memalloc(sizeof(int)*farm->len_flow)))
		{
			//del flow
			finish_him(&farm);
		}
		flow = ft_get_flow(&farm);
		if (!ft_check_profit(farm, flow, ants_allocation))
			ft_decrease_flow_size(&farm, flow, ants_allocation);
		let_the_flow_go(&farm, &flow, ants_allocation);


	}
	//for (int i = 0; i < farm->loss->length; i++)
	//	printf("%d ", farm->loss->data[i]);
//	debug(farm);
//	free_memory(&farm);
//	debug(farm);
//	bfs(farm);
//	dfs(farm);
/*	if (dinic(farm) > 0)
	{
		//printf("AAA\n");
		flow = get_flow(farm);
		array = check_profit(farm, flow, farm->max_path);
		let_the_flow_go(farm, flow, farm->ant_num, array);
		//start
	}*/
//	close(fd);
	return (0);
}
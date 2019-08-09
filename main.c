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

void    free_memory(t_farm **farm) {
    t_farm *to_del;

    to_del = *farm;
    ft_memdel((void**)&to_del->levels);
    ft_memdel((void**)&to_del->used);
    ft_memdel((void**)&to_del->parents);
    ft_int_vec_del(&to_del->loss);
    ht_delete(&to_del->nodes);
    ft_memdel((void**)farm);
}

int     debug(t_farm *to_del)
{
    t_list **table = to_del->nodes->table;
    for (int i = 0; i < to_del->nodes->loaded->length; i++) {
        t_list *temp = table[to_del->nodes->loaded->data[i]];
        printf("index %d\n", to_del->nodes->loaded->data[i]);
        while (temp) {
            printf("|%5s|->", ((t_node *) temp->content)->name);
            printf("links: ");
            for (int j = 0; j < ((t_node *) temp->content)->links->length; j++)
                printf("|%s| ", ((t_node *) temp->content)->links->data[j]);
            printf("\n");
            temp = temp->next;
        }
        printf("\n");
    }
}

int 	main(int argc, char **argv)
{
	t_farm *farm;
	t_vec *flow;
	int *array;
	int fd = open(argv[1], O_RDONLY);
	farm = parse(0);
	debug(farm);
	free_memory(&farm);
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
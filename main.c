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
            printf("|%5s level: %d|->", ((t_node *) temp->content)->name, ((t_node *) temp->content)->level);
            printf("links: ");
            for (int j = 0; j < ((t_node *) temp->content)->links->length; j++)
			{
            	t_link *link = (((t_node *) temp->content)->links->data[j]);
            	/*if (link->capacity == 1 && link->flow == 1)*/
            	printf("|name: %s destination: %d flow: %d| ", link->name, link->direction, link->flow);
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
	t_flow *flow;
int k;
	int fd = open(argv[1], O_RDONLY);
	farm = parse(0);

	if ((k = ft_dinic(&farm)))
	{
	    //printf("max flow: %d\n", k);
		if (farm->loss->length > 1 && farm->loss->data[farm->loss->length - 2] <= farm->loss->data[farm->loss->length - 1])
			flow = ft_return_previous_flow(farm);
		else
			flow = farm->all_flows->data[farm->all_flows->length - 1];//
		//for (int i = 0; i < flow->len_flow; i++)
		//	printf("%d ", flow->ants_allocation[i]);
		let_the_flow_go(&farm, &flow, flow->ants_allocation);
	}
 //   debug(farm);
	return (0);
}
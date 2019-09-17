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
            printf("|%5s level: %d p: %d|->", ((t_node *) temp->content)->name, ((t_node *) temp->content)->level,((t_node *) temp->content)->potential);
            printf("links %zu: ",  ((t_node *) temp->content)->links->length);
            for (int j = 0; j < ((t_node *) temp->content)->links->length; j++)
			{
            	t_link *link = (((t_node *) temp->content)->links->data[j]);
            	/*if (link->capacity == 1 && link->flow == 1)*/
            	printf("|name: %s destination: %d flow: %d| ", link->ptr->name, link->direction, link->flow);
			}
            printf("\n");
            temp = temp->next;
        }
        printf("\n");
    }
}

void	output(t_pvec *vec)
{
	t_node *node;
	for (int i = 0; i < vec->length; i++)
	{
		node = vec->data[i];
		printf("name: %s level: %d\n", node->name, node->level);
	}
	printf("--------------------------------------------------\n");
}

void	bin_heap_test(void)
{
	t_pvec *vec = ft_ptr_vec_init();
	t_pvec *new_vec = ft_ptr_vec_init();
	t_node *node;
	ft_ptr_vec_pushback(vec, (node = create_node(ft_strdup("chlen1"))));
	node->level = 5;
	output(vec);
	sift_up(vec->data, vec->length - 1);
	output(vec);
	ft_ptr_vec_pushback(vec, (node = create_node(ft_strdup("chlen2"))));
	node->level = 2;
	output(vec);
	sift_up(vec->data, vec->length - 1);
	output(vec);
	ft_ptr_vec_pushback(vec, (node = create_node(ft_strdup("chlen3"))));
	node->level = 4;
	output(vec);
	sift_up(vec->data, vec->length - 1);
	output(vec);
	ft_ptr_vec_pushback(vec, (node = create_node(ft_strdup("chlen4"))));
	node->level = 0;
	output(vec);
	sift_up(vec->data, vec->length - 1);
	output(vec);
	ft_ptr_vec_pushback(vec, (node = create_node(ft_strdup("chlen5"))));
	node->level = 1;
	output(vec);
	sift_up(vec->data, vec->length - 1);
	output(vec);
	while (vec->length)
		ft_ptr_vec_pushback(new_vec, pop_min(vec));
	printf("new_vec\n");
	output(new_vec);
}

int 	main(int argc, char **argv)
{
	t_farm *farm;
	t_flow *flow;

	flow = NULL;
	farm = parse(0);
	if (new_alg(&farm) == 1)
	{
		if (farm->loss->length > 1 && farm->loss->data[farm->loss->length - 2] <= farm->loss->data[farm->loss->length - 1])
			flow = farm->all_flows->data[farm->all_flows->length - 2];
		else
			flow = farm->all_flows->data[farm->all_flows->length - 1];
		let_the_flow_go(&farm, flow, flow->ants_allocation);
	}
	ft_chr_vec_pushback(farm->output, "\n");
	write(1, farm->output->data, farm->output->length);
//	debug(farm);
	free_memory(&farm);
	return (0);
}
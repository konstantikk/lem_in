/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flow.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziemann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 17:02:53 by jziemann          #+#    #+#             */
/*   Updated: 2019/08/03 17:02:53 by jziemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

#define NODE(i) ((t_node*)(nodes[i]))
#define LINK(i, j) ((t_link*)((void**)((t_node*)nodes[i])->links->data)[j])

void	release_flow(t_farm *farm)
{
	void **nodes = farm->nodes->data;
	int		i;
	int		j;

	i = -1;
/*	while (++i < (int)farm->nodes->length)
	{
		j = -1;
		printf(" {%s} - ", NODE(i)->name);
		while (++j < (int)NODE(i)->links->length)
		{
			if (LINK(i, j)->flow == 1 && LINK(i, j)->capacity == 1)
				printf("{%s} ",  NODE(LINK(i, j)->index)->name);
		}
		printf("\n");
	}*/

    int k = 0;
    while (k < farm->ant_num)
    {
        i = -1;
        while (++i < farm->nodes->length)
        {
            j = -1;
            while (++j < NODE(i)->links->length)
            {
                if (LINK(i, j)->flow == 1 && LINK(i, j)->capacity == 1 &&
                ft_strncmp(NODE(LINK(i,j)->index)->name, "st_", 3))
                    printf("L%d-%s ", k++ + 1, NODE(LINK(i, j)->index)->name);
            }
            printf("\n");
        }
    }
}

void    let_the_flow_go(t_farm *farm)
{
    char *ants = (char*)malloc(sizeof(char) * farm->ant_num);
    int i;
    int saved_index = -1;
    int num_of_ways = 68468467;

    i = -1;
    while (++i < farm->ant_num)
        ants[i] = -1;
    while (ants[farm->ant_num - 1] != 1)
    {
        i = -1;
        while (++i < num_of_ways && ++saved_index < farm->ant_num)
        {
            ants[saved_index] = 0; //mark ants that are on their way
            //put them on the start node
            //turn capacity to 1
            //print
        }
        i = -1;
        while (++i < num_of_ways)
        {
            //turn capacity to 0
            //move forward each ant
            /*
             *
             */
            //turn capacity to 1
            //print
            //if ant reached the finish mark this ant with 1
        }
        //print '\n'
    }
}
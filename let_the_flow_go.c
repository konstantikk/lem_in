/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   let_the_flow_go.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziemann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 15:34:45 by jziemann          #+#    #+#             */
/*   Updated: 2019/08/06 15:34:45 by jziemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

#define NODE(i) ((t_node*)(nodes[i]))
#define LINK(i, j) ((t_link*)((void**)((t_node*)nodes[i])->links->data)[j])
#define LENGTH(i) ((t_path*)(((void**)flow->data)[i]))->path->length
#define ROOM(i, j) ((t_room*)(((void**)((t_path*)(((void**)flow->data)[i]))->path->data)[j]))

void    let_the_flow_go(t_farm *farm, t_vec *flow, int ant_num, int *array)
{
	char *ants = (char*)malloc(sizeof(char) * ant_num);
	int i;
	int j;
	int saved_index = 0;
	void **nodes = farm->nodes->data;
	int flag = FALSE;
	int counter;

	i = -1;
	while (++i < ant_num)
		ants[i] = -1;
	int l = flow->length;
	while (ants[ant_num - 1] != 1)
	{
		i = 0;
		while (i < flow->length && saved_index < ant_num)
		{
		    if (((t_path*)((void**)flow->data)[i])->fixed_ant_num == array[i])
            {
		        i++;
                continue ;
            }
			ants[saved_index] = 0;
			ROOM(i, 0)->temp_ant = saved_index;
			((t_path*)((void**)flow->data)[i])->ants_onw++;
			printf("L%d-%s ", saved_index++ + 1, NODE(ROOM(i, 0)->node_num)->name);
            ((t_path*)((void**)flow->data)[i++])->fixed_ant_num++;
		}
		printf("\n");
		i = -1;
		while (++i < flow->length)
		{
			j = ((t_path*)((void**)flow->data)[i])->last_occupied + 1;
			counter = ((t_path*)((void**)flow->data)[i])->ants_onw;
            flag = FALSE;
			while (counter-- && j > 0)
			{
			    if (ROOM(i, j)->node_num == farm->end)
			    {
			        ants[ROOM(i, j - 1)->temp_ant] = 1;
			        flag = TRUE;
			        ((t_path*)((void**)flow->data)[i])->ants_onw--;
			    }
			    ROOM(i, j)->temp_ant = ROOM(i, j - 1)->temp_ant;
			    ROOM(i, j - 1)->temp_ant = -1;
			    printf("L%d-%s ", ROOM(i, j)->temp_ant + 1, NODE(ROOM(i, j)->node_num)->name);
			    j--;
			}
			if (flag != TRUE) {
                ((t_path *) ((void **) flow->data)[i])->last_occupied++;
            }
		}
	}

}



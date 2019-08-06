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

void    let_the_flow_go(t_farm *farm, t_vec *flow, int ant_num)
{
	char *ants = (char*)malloc(sizeof(char) * ant_num);
	int i;
	int j;
	int saved_index = 0;
	void **nodes = farm->nodes->data;
	int fisrt_entry = FALSE;

	i = -1;
	while (++i < ant_num)
		ants[i] = -1;
	int shit = 0;
	while (ants[ant_num - 1] != 1)
	{
		i = -1;
		while (++i < flow->length && saved_index < ant_num)
		{
			ants[saved_index] = 0;
			ROOM(i, 0)->capacity = 1;
			ROOM(i, 0)->temp_ant = saved_index;
			((t_path*)((void**)flow->data)[i])->ants_onw++;
			printf("L%d-%s ", saved_index + 1, NODE(ROOM(i, 0)->node_num)->name);
			++saved_index;

		}
		printf("\n");
		i = -1;
		while (++i < flow->length)
		{
			j = 0;
			while (++j < LENGTH(i)) {

				int l = ROOM(i, j)->capacity, m = ROOM(i, j)->temp_ant;
				int ll = ROOM(i, j - 1)->capacity, mm = ROOM(i, j - 1)->temp_ant;
				if (!ROOM(i, j)->capacity && ROOM(i, j)->temp_ant == -1) {
					int counter = ((t_path*)((void**)flow->data)[i])->ants_onw;
					while (counter-- && j > 0)
					{
						if (ROOM(i, j)->node_num == farm->end)
						{
							ants[ROOM(i, j - 1)->temp_ant] = 1;
							((t_path*)((void**)flow->data)[i])->ants_onw--;
							printf("L%d-%s ", ROOM(i, j - 1)->temp_ant + 1, NODE(ROOM(i, j)->node_num)->name);
							ROOM(i, j - 1)->temp_ant = -1;
							ROOM(i, j - 1)->capacity = 0;
						}
						else {
							ROOM(i, j - 1)->capacity = 0;
							ROOM(i, j)->capacity = 1;
							ROOM(i, j)->temp_ant = ROOM(i, j - 1)->temp_ant;
							ROOM(i, j - 1)->temp_ant = -1;
							printf("L%d-%s ", ROOM(i, j)->temp_ant + 1, NODE(ROOM(i, j)->node_num)->name);
						}
						j--;
					}
					break ;
				}
			}
		}
	}

}



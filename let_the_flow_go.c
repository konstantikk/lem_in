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
/*
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
*/

void    put_ants_on_start(char *ants, int ant_num, t_pvec *flow, int *ants_allocation)
{
    static int ant_index = 0;
    register int i;
    const size_t len = flow->length;
    t_room  *room;
    t_path  *path;

    i = 0;
    while ((size_t)i < len && ant_index < ant_num)
    {
        path = flow->data[i];
        if (path->fixed_ant_num == ants_allocation[i])
        {
            i++;
            continue ;
        }
        ants[ant_index] = 0;
        room =((t_room*)(path->path->data[0]));
        room->temp_ant = ant_index;
        path->ants_onw++;
        printf("L%d-%s ", ant_index++ + 1, room->name);
        path->fixed_ant_num++;
    }
}

void    one_step_towards_finish(char *ants, t_pvec *flow, int counter, t_farm *farm)
{
    register int i;
    register int j;
    t_path  *path;
    t_room  *room;
    int     flag;

    i = -1;
    while ((size_t)++i < flow->length)
    {
        path = flow->data[i];
        j = path->last_occupied + 1;
        counter = path->ants_onw;
        flag = FALSE;
        while (counter-- && j > 0)
        {
            room = path->path->data[j];
            if (ht_find_node(farm->nodes,room->name) == farm->end)
            {
                ants[room->temp_ant] = 1;
                flag = TRUE;
                path->ants_onw--;
                farm->ants_check++;
            }
            room->temp_ant = ((t_room*)(path->path->data[j - 1]))->temp_ant;
            printf("L%d-%s ", room->temp_ant + 1, room->name);
            j--;
        }
        if (flag != TRUE) {
            path->last_occupied++;
        }
    }
}

void    let_the_flow_go(t_farm **farm_ptr, t_pvec **flow, int *ants_allocation)
{
    char *ants;
    t_farm *farm;
    int counter;

    farm = *farm_ptr;
    if (!(ants = (char*)malloc(sizeof(char) * farm->ant_num)))
    {
        ft_ptr_vec_del(flow, del_path);
        finish_him(farm_ptr);
    }
    while (farm->ants_check != farm->ant_num)
    {
        put_ants_on_start(ants, farm->ant_num, *flow, ants_allocation);
        printf("\n");
        one_step_towards_finish(ants, *flow, counter, farm);
    }
    printf("\n");
}
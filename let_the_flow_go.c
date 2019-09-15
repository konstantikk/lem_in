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

void	push_room_with_ant(t_cvec **output_ptr, int ant_index, char *room_name)
{
	t_cvec *output;
	const char	*chr_ant_index = ft_itoa(ant_index);

	output = *output_ptr;
	ft_chr_vec_pushback(output, "L");
	ft_chr_vec_pushback(output, (char*)chr_ant_index);
	ft_chr_vec_pushback(output, "-");
	ft_chr_vec_pushback(output, room_name);
	ft_chr_vec_pushback(output, " ");
	ft_memdel((void**)&chr_ant_index);
}

void    put_ants_on_start(char *ants, t_farm *farm, t_flow *flow_temp, int *ants_allocation)
{
    static int ant_index = 0;
    register int i;
    const size_t len = flow_temp->len_flow;
    t_room  *room;
    t_path  *path;

    i = -1;
    while ((size_t)++i < len && ant_index < farm->ant_num)
    {
        path = flow_temp->flow->data[i];
        if (ants_allocation)
            if (path->fixed_ant_num == ants_allocation[i])
                continue ;
        ants[ant_index] = 0;
        room =((t_room*)(path->path->data[0]));
        room->temp_ant = ant_index;
        path->ants_onw++;
        push_room_with_ant(&farm->output, ant_index++ + 1, room->name);
        path->fixed_ant_num++;
    }
}

void    one_step_towards_finish(char *ants, t_flow *flow, int counter, t_farm *farm)
{
    register int i;
    register int j;
    t_path  *path;
    t_room  *room;
    int     flag;

    i = -1;
    while ((size_t)++i < flow->len_flow)
    {
        path = flow->flow->data[i];
        j = path->last_occupied + 1;
        counter = path->ants_onw;
        flag = FALSE;
        while (counter-- && j > 0)
        {
            room = path->path->data[j];
            if (ht_find_node(farm->nodes,room->name) == farm->end)
            {
                ants[room->temp_ant] = (char)1;
                flag = TRUE;
                path->ants_onw--;
                farm->ants_check++;
            }
            room->temp_ant = ((t_room*)(path->path->data[j - 1]))->temp_ant;
            push_room_with_ant(&farm->output, room->temp_ant + 1, room->name);
            j--;
        }
        if (flag != TRUE) {
            path->last_occupied++;
        }
    }
}

void    let_the_flow_go(t_farm **farm_ptr, t_flow **flow, int *ants_allocation)
{
    char *ants;
    t_farm *farm;
    int counter;

    counter = 0;
    farm = *farm_ptr;
    if (!(ants = (char*)malloc(sizeof(char) * farm->ant_num)))
    {
        ft_ptr_vec_del(&((*flow)->flow), del_path);
        finish_him(farm_ptr);
    }
    while (farm->ants_check != farm->ant_num)
    {
        put_ants_on_start(ants, farm, *flow, ants_allocation);
        ft_chr_vec_pushback(farm->output, "\n");
        one_step_towards_finish(ants, *flow, counter, farm);
    }

}
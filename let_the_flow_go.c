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

void				push_room_with_ant(t_farm **farm_ptr,
		int ant_index, char *room_name)
{
	t_farm		*farm;
	const char	*chr_ant_index = ft_itoa(ant_index);

	farm = *farm_ptr;
	if (ft_chr_vec_pushback(farm->output, "L") != 1 ||
	ft_chr_vec_pushback(farm->output, (char*)chr_ant_index) != 1 ||
	ft_chr_vec_pushback(farm->output, "-") != 1 ||
	ft_chr_vec_pushback(farm->output, room_name) != 1 ||
	ft_chr_vec_pushback(farm->output, " ") != 1)
	{
		ft_memdel((void**)&chr_ant_index);
		finish_him(farm_ptr);
	}
	ft_memdel((void**)&chr_ant_index);
}

static void			put_ants_on_start(t_farm **farm_ptr,
		t_flow *flow_temp, int *ants_allocation)
{
	static int		ant_index = 0;
	register int	i;
	t_farm			*farm;
	t_room			*room;
	t_path			*path;

	i = -1;
	farm = *farm_ptr;
	while ((size_t)++i < flow_temp->len_flow && ant_index < farm->ant_num)
	{
		path = flow_temp->flow->data[i];
		if (ants_allocation)
			if (path->fixed_ant_num == ants_allocation[i])
				continue ;
		room = ((t_room*)(path->path->data[0]));
		room->temp_ant = ant_index;
		path->ants_onw++;
		push_room_with_ant(farm_ptr, ant_index++ + 1, room->name);
		path->fixed_ant_num++;
	}
}

static inline void	one_step_on_one_path(int *flag,
		t_farm **farm_ptr, t_path *path)
{
	t_farm			*farm;
	register int	j;
	t_room			*room;
	int				counter;

	farm = *farm_ptr;
	j = path->last_occupied + 1;
	counter = path->ants_onw;
	while (counter-- && j > 0)
	{
		room = path->path->data[j];
		if (room->ptr == farm->end)
		{
			(*flag) = TRUE;
			path->ants_onw--;
			farm->ants_check++;
		}
		room->temp_ant = ((t_room*)(path->path->data[j - 1]))->temp_ant;
		push_room_with_ant(farm_ptr, room->temp_ant + 1, room->name);
		j--;
	}
}

static void			one_step_towards_finish(
		t_farm **farm_ptr, t_flow *flow)
{
	register int	i;
	t_path			*path;
	int				flag;

	i = -1;
	while ((size_t)++i < flow->len_flow)
	{
		path = flow->flow->data[i];
		flag = FALSE;
		one_step_on_one_path(&flag, farm_ptr, path);
		if (flag != TRUE)
			path->last_occupied++;
	}
}

void				let_the_flow_go(t_farm **farm_ptr,
		t_flow *flow, int *ants_allocation)
{
	t_farm		*farm;

	farm = *farm_ptr;
	while (farm->ants_check != farm->ant_num)
	{
		put_ants_on_start(farm_ptr, flow, ants_allocation);
		ft_chr_vec_pushback(farm->output, "\n");
		one_step_towards_finish(farm_ptr, flow);
	}
}

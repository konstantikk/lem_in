/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 16:30:17 by vlegros           #+#    #+#             */
/*   Updated: 2019/07/28 16:30:17 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
/*
int		release_flow(t_farm *farm)
{
	//void	**nodes = farm->nodes->data;
	int		*array;
	t_vec	*flow;

	//printf("\nnew patch \n");
	if (farm->ant_num == 1)
	{
		flow = get_flow(farm);
		//let_the_flow_go(farm, flow, farm->ant_num);
		///start ant race
		return (0);
	}

	flow = get_flow(farm);
	array = check_profit(farm, flow, farm->max_path);
	if (!array)
	{
		///printf ("BBB\n");
		array = check_profit(farm, flow,  find_previous_max(flow, farm->max_path));
		let_the_flow_go(farm, flow, farm->ant_num, array);
		///start and race
		return (0);
	}
	///printf("\n\n");
	if (farm->loss->length == 1 || (farm->loss->length > 1 &&
			farm->loss->data[farm->loss->length - 2] > farm->loss->data[farm->loss->length - 1]))
	{
		/// free array
		//search continue
		return (1);
	}
	else if (farm->loss->length > 1 &&
			farm->loss->data[farm->loss->length - 2] < farm->loss->data[farm->loss->length - 1])
	{
		///free array
		///	printf ("AAA\n");
		array = check_profit(farm, flow,  find_previous_max(flow, farm->max_path));
		let_the_flow_go(farm, flow, farm->ant_num, array);
		///start and race
		return (0);
	}
	return (1);
}

int 	*check_profit(t_farm *farm, t_vec *flow, int max)
{
	int *array;
	long long sum = 0;
	long long additional_ants;
	int residual_ants;
	int max_loss = 0;

	///array = (int *)ft_memalloc(sizeof(int) * flow->length);
	for (int i = 0; i < (int)flow->length; i++)
	{
		array[i] = max - (int) LENGTH(i) + 1;/// flow->max_patch = ants_allocation[0]
		if (farm->max_path == LENGTH(i))
			array[i] = 0;
		sum += array[i];
	}
	if (farm->ant_num < sum)
		return (0);
	additional_ants = (farm->ant_num - sum) / flow->length;
	residual_ants = (farm->ant_num - sum) % flow->length;
	for (int i = 0; i < (int)flow->length; i++)
	{
		array[i] += additional_ants;
		if (residual_ants > 0)
		{
			array[i] += 1;
			residual_ants--;
		}
	}
	for (int i = 0; i < (int)flow->length; i++)
	{
		if (max_loss < LENGTH(i) + array[i] - 1)
			max_loss = LENGTH(i) + array[i] - 1;
	}
	ft_int_vec_pushback(farm->loss, max_loss); ///array[min]
	return (array);
}


t_vec    *get_flow(t_farm *farm)
{
	void **nodes = farm->nodes->data;
	int		i = -1;
	int		j;
	int 	v;
	t_path *path;
	t_vec *flow;


	flow = ft_ptr_vec_init();
	while (++i < (int) NODE(farm->start)->links->length)
	{
		if ((LINK(farm->start, i)->flow == 1 && LINK(farm->start, i)->capacity == 1))
		{
			path = create_path();
			v = LINK(farm->start, i)->index;
			while (v != farm->end)
			{
				j = -1;
				while (++j < (int)NODE(v)->links->length)
				{
					if (LINK(v, j)->flow == 1 && LINK(v, j)->capacity == 1)
					{
						if (ft_strncmp(NODE(v)->name, "st_", 3))
							ft_ptr_vec_pushback(path->path, create_room(v));
						v = LINK(v, j)->index;
						break ;
					}
				}
			}
			ft_ptr_vec_pushback(path->path, create_room((int)farm->end));
			//if ((int)path->path->length > farm->max_path)
			///	farm->max_path = (int)path->path->length;
			///else if ((int)path->path->length < farm->min_path)
			//	farm->min_path = (int)path->path->length;
			ft_ptr_vec_pushback(flow, path);
		}
	}
	return (flow);
}*/

t_flow	*ft_get_flow(t_farm **farm_ptr)
{
	register int i;
	t_pvec	*flow;
	t_farm *farm;
	t_link	*link;
	t_flow	*temp_flow;

	farm = *farm_ptr;
	i = -1;
	if (!(flow = ft_ptr_vec_init()))
		finish_him(farm_ptr);
	while ((size_t)++i < farm->start->links->length)
	{
		link = farm->start->links->data[i];
		if (link->flow == 1 && link->capacity == 1)
			ft_recover_path(farm_ptr, link, &flow);
	}
	sort_flow(flow, flow->length, flow->length - 1);
	if (!(temp_flow = (t_flow *)malloc(sizeof(t_flow))))
		finish_him(farm_ptr);
	temp_flow->flow = flow;
	temp_flow->len_flow = flow->length;
	if (!(temp_flow->ants_allocation = (int *)ft_memalloc(sizeof(int) * flow->length)))
	{
		//del flow
		finish_him(farm_ptr);
	}
	ft_ptr_vec_pushback(farm->all_flows, flow);
	////ft_push_back_flow_in_main_flow(all_flow, flow);
	return (temp_flow);
}

int 	ft_check_profit(t_farm *farm, t_pvec *flow, int *ants_allocation, int len_flow)
{
	int		sum;
	int 	addition_ants;
	int 	residual_ants;
	int 	i;
	size_t	path_len;
	const int 	max_path = (int)((t_path*)(flow->data[len_flow - 1]))->path->length ;

	sum = 0;
	i = -1;
	while ((size_t)++i < len_flow)
	{
		path_len = max_path - ((t_path*)(flow->data[i]))->path->length;
		ants_allocation[i] = path_len;
		sum += path_len;
	}
	if (farm->ant_num < sum)
		return (0);
	addition_ants = (farm->ant_num - sum) / len_flow;
	residual_ants = (farm->ant_num - sum) % len_flow;
	i = -1;
	while ((size_t)++i < len_flow)
	{
		ants_allocation[i] += addition_ants;
		if (residual_ants-- > 0)
			ants_allocation[i] += 1; ///speed ants
	}
	ft_int_vec_pushback(farm->loss, ((t_path*)(flow->data[0]))->path->length - 1 + ants_allocation[0] - 1);
	return (1);
}
/*
void	ft_decrease_flow_size(t_farm **farm_ptr, t_pvec *flow, int *ants_allocation)
{
	t_farm *farm = *farm_ptr;

	ft_memset(ants_allocation, 0, farm->len_flow);
	farm->len_flow--;
	while (!ft_check_profit(*farm_ptr, flow, ants_allocation))
	{
		ft_memset(ants_allocation, 0, farm->len_flow);
		farm->len_flow--;
	}
	//let_the_flow_go(farm_ptr, &flow, ants_allocation);
}
*/
int 	ft_release_flow(t_farm **farm_ptr)
{
	t_farm	*farm;
	//int 	*ants_allocation;
	t_flow	*flow;
	t_ivec	*loss;

	farm = *farm_ptr;
	loss = farm->loss;
	if (!(flow = ft_get_flow(farm_ptr)))
	{    ///del flow
		finish_him(farm_ptr);
	}
	//flow->len_flow = flow->length;
	if (farm->ant_num == 1)
	{
		let_the_flow_go(farm_ptr, &(flow->flow), NULL);
		return (0);
	}
	/*if (!(ants_allocation = (int *)ft_memalloc(sizeof(int)*farm->len_flow)))
	{
		//del flow
		finish_him(farm_ptr);
	}*/

	if (!ft_check_profit(farm, flow->flow, flow->ants_allocation, flow->len_flow))
	{
		//ft_decrease_flow_size(farm_ptr, flow, ants_allocation);
		return (0);
	}
	if (loss->length > 1 && loss->data[loss->length - 2] <= loss->data[loss->length - 1])
	{
		//ft_decrease_flow_size(farm_ptr, flow, ants_allocation);
		return (0);
	}

	//ft_memdel((void **)&ants_allocation);
	return (1);

}

int		ft_dinic(t_farm **farm)
{
	int flow;

	while (ft_bfs(farm))
	{
		flow = ft_dfs(farm);
		while (flow)
			flow = ft_dfs(farm);
		if (!ft_release_flow(farm))
			return (0);
	}
	return (1);
}
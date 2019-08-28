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
	ft_ptr_vec_pushback(farm->all_flows, temp_flow);
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
		if (farm->ant_num < sum)
			return (0) ;
	}
	//if (farm->ant_num < sum)
		//return (0);
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

t_flow		*ft_return_previous_flow(t_farm *farm)
{
	const int 	len = (int)farm->all_flows->length;

	return (farm->all_flows->data[len - 2]);///////len -2
}
int 	ft_release_flow(t_farm **farm_ptr)
{
	t_farm	*farm;
	t_flow	*flow;
	t_ivec	*loss;

	farm = *farm_ptr;
	loss = farm->loss;
	if (!(flow = ft_get_flow(farm_ptr)))
	{    ///del flow
		finish_him(farm_ptr);
	}
	if (farm->ant_num == 1)
	{
		let_the_flow_go(farm_ptr, &(flow), NULL);
		return (0);
	}
	if (!ft_check_profit(farm, flow->flow, flow->ants_allocation, flow->len_flow))
	{
		flow = ft_return_previous_flow(farm);
		//let_the_flow_go(farm_ptr, &flow, flow->ants_allocation);
		return (0);
	}
	if (loss->length > 1 && loss->data[loss->length - 2] <= loss->data[loss->length - 1])
	{
		flow = ft_return_previous_flow(farm);
		//let_the_flow_go(farm_ptr, &flow, flow->ants_allocation);
		return (0);
	}

	t_pvec	*all_f = farm->all_flows;
	const int 	len = (int)farm->all_flows->length;
	for (int i = 0; i < len; i++)
	{
		int len_flow =  ((t_flow *)(all_f->data[i]))->len_flow;
		t_flow *flow = (t_flow *)(all_f->data[i]);
		//printf("len: %d\n", len_flow);
		for (int j = 0; j < len_flow; j++)
			printf("%zu (%d)\n", ((t_path*)(flow->flow->data[j]))->path->length , flow->ants_allocation[j]);
		printf("\n");
	}
	printf("__________________________\n");

	return (1);

}

int		ft_dinic(t_farm **farm)
{
    int flow;
    int i = 0;
    //printf("%d\n", i);

    while (dijkstra(*farm))
    {     //t_node *node = (*farm)->end;
        ft_add_path(farm);
		dijkstra_potentials(*farm);
		if (!ft_release_flow(farm))
			return (0);
		//dijkstra_potentials(*farm);

	}
    return (1);
	/*while (node != (*farm)->start)
    {
	    printf("%s->", node->name);
	    node = node->parent;
    }*/
		//printf("%d\n",i++);
/*	while (ft_bfs(farm))///dejkstra
	{
		flow = ft_dfs(farm);
		while (flow)
			flow = ft_dfs(farm);
		if (!ft_release_flow(farm))
			return (0);
	}
	return (1);*/
}

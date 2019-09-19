/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 19:34:50 by vlegros           #+#    #+#             */
/*   Updated: 2019/09/15 19:34:50 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	delete_path(void **elem)
{
	t_path *path;

	path = *elem;
	ft_ptr_vec_del(&path->path, ft_memdel);
	ft_memdel(elem);
}

void	delete_one_flow(void **flow_ptr)
{
	t_flow *flow;

	flow = *flow_ptr;
	ft_memdel((void**)&flow->a_alloc);
	ft_ptr_vec_del(&flow->flow, delete_path);
	ft_memdel(flow_ptr);
}

void	delete_all_flows(t_pvec **all_flows)
{
	ft_ptr_vec_del(all_flows, delete_one_flow);
}

void	delete_parse_link_struct(t_parse_link **pl_ptr)
{
	t_parse_link *pl;

	pl = *pl_ptr;
	ft_memdel((void**)&pl->name1);
	ft_memdel((void**)&pl->name2);
	ft_memdel((void**)pl_ptr);
}

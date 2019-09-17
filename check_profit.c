/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_profit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziemann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 21:20:31 by jziemann          #+#    #+#             */
/*   Updated: 2019/09/14 21:20:31 by jziemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static	int		scatter_ants(t_farm *farm, int *ants_allocation, int len_flow, int sum)
{
	int		addition_ants;
	int		residual_ants;
	int		i;

	i = -1;
	addition_ants = (farm->ant_num - sum) / len_flow;
	residual_ants = (farm->ant_num - sum) % len_flow;
	while ((size_t)++i < len_flow)
	{
		ants_allocation[i] += addition_ants;
		if (residual_ants-- > 0)
			ants_allocation[i] += 1;
	}
	return (ants_allocation[0] - 1);
}

static	int		ft_check_profit(t_farm *farm, t_pvec *flow, int *ants_allocation, int len_flow)
{
	int			sum;
	int			i;
	size_t		path_len;
	const int	max_path = (int)((t_path*)(flow->data[len_flow - 1]))->path->length;
	const int	length = ((t_path*)(flow->data[0]))->path->length - 1;

	sum = 0;
	i = -1;
	while ((size_t)++i < len_flow)
	{
		path_len = max_path - ((t_path*)(flow->data[i]))->path->length;
		ants_allocation[i] = path_len;
		sum += path_len;
		if (farm->ant_num < sum)
			return (0);
	}
	ft_int_vec_pushback(farm->loss, length +
	scatter_ants(farm, ants_allocation, len_flow, sum));
	return (1);
}

void	ft_return_previous_flow(t_farm **farm_ptr)
{
	t_farm	*farm;
	t_flow	*flow;
	int		len;

	farm = *farm_ptr;
	len = (int)farm->all_flows->length;
	flow = farm->all_flows->data[len - 2];
	let_the_flow_go(farm_ptr, flow, flow->ants_allocation);
}

static	int		check_benefits(t_farm **farm_ptr, t_ivec *loss, t_flow *flow)
{
	t_farm	*farm;

	farm = *farm_ptr;
	if (farm->ant_num == 1)
	{
		let_the_flow_go(farm_ptr, flow, NULL);
		return (0);
	}
	if (!ft_check_profit(farm, flow->flow, flow->ants_allocation,
			flow->len_flow))
	{
		ft_return_previous_flow(farm_ptr);
		return (0);
	}
	if (loss->length > 1
			&& loss->data[loss->length - 2] < loss->data[loss->length - 1])
	{
		ft_return_previous_flow(farm_ptr);
		return (0);
	}
	return (1);
}

int				ft_release_flow(t_farm **farm_ptr)
{
	t_farm *farm;
	t_flow *flow;
	t_ivec *loss;

	farm = *farm_ptr;
	loss = farm->loss;
	if (!(flow = ft_get_flow(farm_ptr)))
		finish_him(farm_ptr);
	if (!check_benefits(farm_ptr, loss, flow))
		return (0);
	return (1);
}

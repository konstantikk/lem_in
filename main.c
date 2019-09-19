/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 19:57:35 by vlegros           #+#    #+#             */
/*   Updated: 2019/07/26 19:57:35 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void    finish_him(t_farm **farm)
{
    write(2, "Error\n", 6);
    free_memory(farm);
    exit(-1);
}

int 	main(int argc, char **argv)
{
	t_farm *farm;
	t_flow *flow;

	farm = variables_init();
	parse_options(argc, argv, &farm);
	parse(farm->fd, &farm);
	if (get_optimal_flow(&farm) == 1)
	{
		if (farm->loss->length > 1 && farm->loss->data[farm->loss->length - 2] <= farm->loss->data[farm->loss->length - 1])
			flow = farm->all_flows->data[farm->all_flows->length - 2];
		else
			flow = farm->all_flows->data[farm->all_flows->length - 1];
		let_the_flow_go(&farm, flow, flow->a_alloc);
	}
	if (farm->fast == FALSE && (farm->print == FULL || farm->print == ANTS_MOVE))
		ft_chr_vec_pushback(farm->output, "\n");
	else if (farm->fast == TRUE)
		ft_printf("{BLUE}%d{GREY}\n", farm->num_of_lines);
	write(1, farm->output->data, farm->output->length);
	if (farm->fd)
		close(farm->fd);
	free_memory(&farm);
	return (0);
}
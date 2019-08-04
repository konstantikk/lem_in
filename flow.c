/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flow.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziemann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 17:02:53 by jziemann          #+#    #+#             */
/*   Updated: 2019/08/03 17:02:53 by jziemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

#define NODE(i) ((t_node*)(nodes[i]))
#define LINK(i, j) ((t_link*)((void**)((t_node*)nodes[i])->links->data)[j])

int 	check_profit()
{

}

void	print_flow(t_farm *farm)
{
	void **nodes = farm->nodes->data;
	int		i = -1;
	int		j;
//	int 	counter_patch = 0;
	int 	v;

	while (++i < (int) NODE(farm->start)->links->length)
	{
		if ((LINK(farm->start, i)->flow == 1 && LINK(farm->start, i)->capacity == 1))
		{
			///malloc new patch
			v = LINK(farm->start, i)->index;
			while (v != farm->end)
			{
				j = -1;
				while (++j < (int)NODE(v)->links->length)
				{
					if (LINK(v, j)->flow == 1 && LINK(v, j)->capacity == 1)
					{
						///add strjoin("L",node->name) in vector (patch)
						printf("%s->", NODE(v)->name);
						v = LINK(v, j)->index;
						break ;
					}
				}
			}
			///add strjoin("L",node->name) in vector (patch)
			printf("%s", NODE(farm->end)->name);
			printf("\n");
			///add new patch in flow
		}
	}
	///return (flow);
}

int		release_flow(t_farm *farm)
{
	void **nodes = farm->nodes->data;

	if (farm->ant_num == 1)
	{
		print_flow(farm);
		///start ant race
		return (0);
	}
	else
	{
		print_flow(farm);
		/*if (check_profit())
		{
			print_flow(farm);
			///start ant race
			return (0);
		}
		else
		{
			///array.push_back(profit);
		}*/
	}
	return (1);
}

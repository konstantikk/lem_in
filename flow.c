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

void	release_flow(t_farm *farm)
{
	void **nodes = farm->nodes->data;
	int		i;
	int		j;

	i = -1;
	while (++i < (int)farm->nodes->length)
	{
		j = -1;
		printf(" {%s} -", NODE(i)->name);
		while (++j < (int)NODE(i)->links->length)
		{
		//	printf("[%d] ",farm->levels[LINK(i, j)->index]);
			if (LINK(i, j)->f == 1 && LINK(i, j)->capacity == 1)
				printf("{%s} ",  NODE(LINK(i, j)->index)->name);
		}
		printf("\n");
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bfs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziemann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 20:43:00 by jziemann          #+#    #+#             */
/*   Updated: 2019/09/15 18:30:01 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	nullify(t_ht *nodes, int level_or_used)
{
	const int *data = nodes->loaded->data;
	const size_t len = nodes->loaded->length;
	register int i;
	t_list		*temp;

	i = -1;
	while ((size_t)++i < len)
	{
		temp = nodes->table[data[i]];
		while (temp)
		{
			if (level_or_used == BOTH)
				((t_node*)(temp->content))->level = INF;
			((t_node*)(temp->content))->used = FALSE;
			temp = temp->next;
		}
	}
}

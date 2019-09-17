/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 18:28:37 by vlegros           #+#    #+#             */
/*   Updated: 2019/09/14 22:30:36 by jziemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_node		*ht_find_node(t_ht *ht, char *name)
{
	const unsigned long index = ft_hash((unsigned char*)name, ht->capacity);
	t_list				*temp;

	temp = ht->table[index];
	while (temp)
	{
		if (!ft_strcmp(((t_node*)temp->content)->name, name))
			return (temp->content);
		temp = temp->next;
	}
	return (NULL);
}

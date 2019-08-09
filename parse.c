/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 19:58:37 by vlegros           #+#    #+#             */
/*   Updated: 2019/07/26 19:58:37 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_node	*create_node(char *name)
{
	t_node *node;

	if (!(node = (t_node*)malloc(sizeof(t_node))))
		return (NULL);
	node->name = name;
	node->links = ft_ptr_vec_init();
	node->flow = NULL;
	node->capacity = NULL;
	return (node);
}

t_farm	*parse(int fd)
{
	t_farm	*farm;
	char	*buff = NULL;

	if (!(farm = (t_farm*)ft_memalloc(sizeof(t_farm))))
		return (NULL);
	farm->nodes = ft_ht_init();
	while (get_next_line(fd, &buff))
	{
		if (!farm->ant_num)
			farm->ant_num = ft_atoi(buff);
		else if (buff[0] == '#')
		{
			if (!ft_strcmp(buff, "##start"))
			    read_start_end(farm, fd, &buff, START);
			else if (!ft_strcmp(buff, "##end"))
                read_start_end(farm, fd, &buff, END);
		}
		else if (ft_strchr(buff, '-'))
		    read_links(farm, buff);
		else
			read_node(farm, buff);
		ft_memdel((void**)&buff);
	}
	farm->levels = (int*)malloc(sizeof(int) * farm->nodes->size);
	farm->used = (int*)malloc(sizeof(int) * farm->nodes->size);
	farm->parents = (int*)malloc(sizeof(int) * farm->nodes->size);
//	farm->stream = ft_ptr_vec_init();
	farm->loss = ft_int_vec_init();
	return (farm);
}

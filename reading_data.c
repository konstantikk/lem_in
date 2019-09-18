/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 21:26:06 by vlegros           #+#    #+#             */
/*   Updated: 2019/08/08 21:26:06 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		read_node(t_farm **farm, char *buff)
{
	t_node	*in_node;
	t_node	*out_node;
	char	*name;
	char	*sup_name;

	if (!(name = ft_find_word(buff, 0, ' ')))
		finish_him(farm);
	if (name[0] == 'L' || ft_strchr(name, '-'))
	{
		ft_memdel((void**)&name);
		finish_him(farm);
	}
	if (!(sup_name = ft_strjoin("L", name)) ||
		!(in_node = create_node(sup_name)) ||
		!(out_node = create_node(name)))
		finish_him(farm);
	safe_insert(farm, (*farm)->nodes, in_node);
	safe_insert(farm, (*farm)->nodes, out_node);
	safe_pushback(farm, in_node->links,
			safe_create_link(farm, ft_strdup(out_node->name)));
	safe_pushback(farm, out_node->links,
			safe_create_link(farm, ft_strdup(in_node->name)));
	((t_link*)(out_node->links->data[0]))->direction = -1;
	return (1);
}

int		read_start_end(t_farm **farm, int fd, char **buff, int start_end)
{
	char	*name;

	ft_chr_vec_pushback((*farm)->output, *buff);
	ft_memdel((void**)buff);
	ft_chr_vec_pushback((*farm)->output, "\n");
	get_next_line(fd, buff);
	if (!(name = ft_find_word(*buff, 0, ' ')))
		finish_him(farm);
	if (name[0] == 'L' || ft_strchr(name, '-'))
	{
		ft_memdel((void**)&name);
		finish_him(farm);
	}
	safe_insert(farm, (*farm)->nodes, create_node(name));
	if (start_end == START)
		(*farm)->start = ht_find_node((*farm)->nodes, name);
	else if (start_end == END)
		(*farm)->end = ht_find_node((*farm)->nodes, name);
	return (1);
}

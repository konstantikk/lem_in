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

int		read_node(t_farm **f, char *buff)
{
	t_node	*i_n;
	t_node	*o_n;
	char	*name;
	char	*s_n;

	i_n = NULL;
	o_n = NULL;
	if (!(name = ft_find_word(buff, 0, ' ')))
		finish_him(f);
	if (name[0] == 'L' || ft_strchr(name, '-') ||
	ht_find_node((*f)->nodes, name))
	{
		ft_memdel((void**)&name);
		finish_him(f);
	}
	if (!(s_n = ft_strjoin("L", name)) ||
	!(i_n = create_node(s_n)) ||
	!(o_n = create_node(name)))
		finish_him(f);
	safe_insert(f, (*f)->nodes, i_n);
	safe_insert(f, (*f)->nodes, o_n);
	safe_pushback(f, i_n->links, safe_create_link(f, ft_strdup(o_n->name)));
	safe_pushback(f, o_n->links, safe_create_link(f, ft_strdup(i_n->name)));
	((t_link*)(o_n->links->data[0]))->direction = -1;
	return (1);
}

int		read_start_end(t_farm **farm_ptr, int fd, char **buff, int start_end)
{
	char	*name;
	t_farm	*farm;

	farm = *farm_ptr;
	if (farm->fast == FALSE && (farm->print == FULL || farm->print == GRAPH))
	{
		ft_chr_vec_pushback(farm->output, *buff);
		ft_chr_vec_pushback(farm->output, "\n");
	}
	ft_memdel((void**)buff);
	get_next_line(fd, buff);
	if (!(name = ft_find_word(*buff, 0, ' ')))
		finish_him(farm_ptr);
	if (name[0] == 'L' || ft_strchr(name, '-'))
	{
		ft_memdel((void**)&name);
		finish_him(farm_ptr);
	}
	safe_insert(farm_ptr, farm->nodes, create_node(name));
	if (start_end == START)
		farm->start = ht_find_node(farm->nodes, name);
	else if (start_end == END)
		farm->end = ht_find_node(farm->nodes, name);
	return (1);
}

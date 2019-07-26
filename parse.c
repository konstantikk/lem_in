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

t_node	*create_node(char *line)
{
	t_node *node;

	if (!line)
		return (NULL);
	if (!(node = (t_node*)malloc(sizeof(node))))
		return (NULL);
	node->name = line;
	node->links = NULL;
	node->parents = NULL;
	return (node);
}

int 	read_node(t_farm *farm, char *line)
{
	t_node		*in_node;
	t_node		*out_node;
	char	*name = ft_find_word(line, 0, ' ');

	if (!(in_node =
		create_node((char*)name)))
		return (-1);
	if (!(out_node = create_node(ft_strdup("chlen"))))
		return (-1);
	in_node->links = ft_int_vec_init();
	ft_int_vec_pushback(in_node->links, farm->nodes->length);
	ft_ptr_vec_pushback(farm->nodes, in_node);
	ft_ptr_vec_pushback(farm->nodes, out_node);
	return (1);
}

int 	read_link(t_farm *farm, char *line)
{
	return (1);
}

int 	read_start_end(t_farm *farm, char **line, int fd, int start_end)
{
	t_node *node;

	get_next_line(fd, line);
	if (!(node = create_node(ft_find_word(*line, 0, ' '))))
		return (-1);
	if (!ft_ptr_vec_pushback(farm->nodes, node))
		return (0);
	if (start_end == START)
		farm->start = farm->nodes->length - 1;
	else if (start_end == END)
		farm->end = farm->nodes->length - 1;
	return (1);
}

t_farm	*parse(int fd)
{
	char *line;
	t_farm *farm;

	line = NULL;
	if (!(farm = (t_farm*)malloc(sizeof(t_farm))))
		return (NULL);
	farm->nodes = ft_ptr_vec_init();
	get_next_line(fd, &line);
	farm->ant_num = ft_atoi(line);
	ft_memdel((void**)&line);
	while (get_next_line(fd, &line))
	{
		if (line[0] == '#')
		{
			if (!ft_strcmp("##start", line))
			{
			//	ft_memdel((void**)&line);
				read_start_end(farm, &line, fd, START);
			}
			else if (!ft_strcmp("##end", line))
			{
			//	ft_memdel((void**)&line);
				read_start_end(farm, &line, fd, END);
			}
			ft_memdel((void**)&line);
			continue ;
		}
		read_node(farm, line);
			/*	if (ft_strchr(line, '-'))
					read_link(farm, line);*/
			ft_memdel((void **)&line);
	}

	return (farm);
}
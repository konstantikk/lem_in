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

int		find_index(t_farm *farm, char *name)
{
	int i;

	i = -1;
	while ((size_t)++i < farm->nodes->length)
		if (!ft_strcmp(((t_node*)(((void**)farm->nodes->data)[i]))->name, name))
			return (i);
	return (-1);
}

t_node	*create_node(char *name)
{
	t_node *node;

	if (!(node = (t_node*)malloc(sizeof(t_node))))
		return (NULL);
	node->usage = 0;
	node->level = 0;
	node->name = name;
	node->links = ft_int_vec_init();
	node->parents = NULL;
	return (node);
}

int 	read_node(t_farm *farm, char *buff)
{
	t_node	*in_node;
	t_node	*out_node;
	char 	*name;

	name = ft_find_word(buff, 0, ' ');
	if (!(in_node =
		create_node(ft_strjoin("st_", ft_find_word(buff, 0, ' ')))))
		return (0);
	if (!(out_node = create_node(ft_find_word(buff, 0, ' '))))
	{
		//del
		return (0);
	}
	ft_int_vec_pushback(in_node->links, (int)farm->nodes->length + 1);
	ft_ptr_vec_pushback(farm->nodes, in_node);
	ft_ptr_vec_pushback(farm->nodes, out_node);
	return (1);
}

int 	read_links(t_farm *farm, char *buff)
{
	const char	*node1 = ft_find_word(buff, 0, '-');
	const char	*node2 = ft_strsub(buff, ft_strlen(node1) + 1, ft_strlen(buff) - ft_strlen(node1) - 1);
	const int	index1 = find_index(farm, (char*)node1);
	const int	index2 = find_index(farm, (char*)node2);

	ft_int_vec_pushback(((t_node*)(((void**)farm->nodes->data)[index1]))->links, index2);
	ft_int_vec_pushback(((t_node*)(((void**)farm->nodes->data)[index2]))->links, index1);
	return (1);
}

int		read_start_end(t_farm *farm, int fd, char **buff, int start_end)
{
	t_node *node;

	ft_memdel((void**)buff);
	get_next_line(fd, buff);
	if (!(node = create_node(ft_find_word(*buff, 0, ' '))))
		return (0);
	ft_ptr_vec_pushback(farm->nodes, node);
	if (start_end == START)
		farm->start = farm->nodes->length - 1;
	else if (start_end == END)
		farm->end = farm->nodes->length - 1;
	return (1);
}

t_farm	*parse(int fd)
{
	t_farm	*farm;
	char	*buff = NULL;

	if (!(farm = (t_farm*)malloc(sizeof(t_farm))))
		return (NULL);
	farm->ant_num = 0;
	farm->nodes = ft_ptr_vec_init();
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
	return (farm);
}

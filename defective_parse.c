/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defective_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vera <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 21:34:03 by vera              #+#    #+#             */
/*   Updated: 2019/07/22 21:34:03 by vera             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_node	*make_vek()
{
	t_node	*r;

	r = (t_node *)malloc(sizeof(t_node));

	r->cap = 10;
	r->len = 0;
	if (!(r->name_vertex = (char **)ft_memalloc(sizeof(char *) * 10)))
		return (0);
	r->links = (t_link **)malloc(sizeof(t_link *) * 10);
	return (r);
}

int 		ft_push_back(t_node *vec, char *name, t_link *link)
{
	int i;
	char **new_name;
	t_link	**new_links;

	if (!vec)
		return (0);
	if (vec->len + 1 > vec->cap)
	{
		while (vec->len >= vec->cap)
			vec->cap *= 2;
		if (!(new_name = (char **)malloc(vec->cap * sizeof(char *))))
			return (0);
		if (!(new_links = (t_link **)malloc(vec->cap * sizeof(t_link *))))
			return (0);
		i = -1;
		while (++i < (int)vec->len)
		{
			new_name[i] = vec->name_vertex[i];
			new_links[i] = vec->links[i];
		}
		new_links[vec->len] = link;
		new_name[vec->len++] = name;
		//	free(vec->start_name);
		vec->links = new_links;
		vec->name_vertex = new_name;
	}
	else
	{
		vec->name_vertex[vec->len] = name;
		vec->links[vec->len++] = link;
	}

	return (1);
}

t_fam	*defective_parse(void)
{
	t_fam *fam;
	char *line;
	char *buff;
	t_node	*list;


	list = make_vek();
	fam = (t_fam *)malloc(sizeof(t_fam));
	get_next_line(0, &line);
	fam->num_ant = ft_atoi(line);
	while (get_next_line(0, &buff))
	{

		if ((line = ft_strchr(buff, '#')))
		{
			if (*(++line) == '#')
			{
				///start or end
				++line;

				if (ft_strcmp(line, "end"))
				{
					fam->norm_start = 1;///parse next line immediately, it's start
					get_next_line(0, &buff);
					ft_push_back(list, ft_find_word(buff, 0, ' '), ft_makevec());
					list->links[list->len - 1]->start = '1';
				}
				else if (ft_strcmp(line, "start"))
				{
					fam->norm_end = 1 ; ///parse next line immediately, it's end
					get_next_line(0, &buff);
					ft_push_back(list, ft_find_word(buff, 0, ' '), ft_makevec());
					list->links[list->len - 1]->end = '1';
				}
				else
				{
					ft_strdel(&buff);
					continue ;
				}
			}
			else
			{
				ft_strdel(&buff);
				continue ;
			}
		}
		else if (ft_strchr(buff, '-'))
		{
			fam->norm_links = 1;
			///parse links
		}

		else
		{
			fam->norm_vertex = 1;
			ft_push_back(list, ft_find_word(buff, 0, ' '), ft_makevec());
			ft_push_back(list, ft_strjoin("new_",ft_find_word(buff, 0, ' ') ), ft_makevec());
			//list->links->end = '0';
			//list->links->start = '0';
			///parse vertex [node coord_x coord_y]
		}


	}
	fam->adjacency_list = list;

	return (fam);
}
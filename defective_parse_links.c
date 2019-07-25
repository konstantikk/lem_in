/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defective_parse_links.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziemann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 16:59:16 by jziemann          #+#    #+#             */
/*   Updated: 2019/07/25 16:59:16 by jziemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lem_in.h"


int 	ft_vec_return(char *name, t_node *vec)
{
	int i;

	i = -1;
	while (++i < (int)vec->len)
		if (!ft_strcmp(name, vec->name_vertex[i]))
			return (i);
	return (-1);
}

int 	check_double(char *name, t_link *vec)
{
	int i;

	i = -1;
	while (++i < (int)vec->len)
		if (!ft_strcmp(name, vec->name[i]))
			return (i);
	return (-1);
}

void	defective_parse_links(char *buff, t_node *list)
{
	char	*vertex1;
	char	*vertex2;
	int 	id1;
	int 	id2;

	vertex1 = ft_find_word(buff, 0, '-');
	vertex2 = ft_strsub(buff, ft_strlen(vertex1) + 1, ft_strlen(buff) - ft_strlen(vertex1) - 1);
	id1 = ft_vec_return(vertex1, list);
	id2 = ft_vec_return(vertex2, list);

	if (list->links[id1]->start == '1' || list->links[id2]->start == '1')
	{
		//printf("!%s\t%s!\n", vertex1, vertex2);
		///first or second node - start; start->(vertex1 or vertex2)
		if (list->links[id1]->start)
		{
			ft_vec_push_back(list->links[id1], vertex2);
			if (check_double(ft_strjoin("new_", vertex2), list->links[id2]) == -1)
				ft_vec_push_back(list->links[id2], ft_strjoin("new_", vertex2));
		}
		else
		{
			ft_vec_push_back(list->links[id2], vertex1);
			if (check_double(ft_strjoin("new_", vertex1), list->links[id1]) == -1)
				ft_vec_push_back(list->links[id1], ft_strjoin("new_", vertex1));
		}
	}
	else if (list->links[id1]->end == '1'|| list->links[id2]->end == '1')
	{
		/// first or second vertex is end, (new_vertex1 || new_vertex2)->end
		if (list->links[id1]->end == '1')
		{
			ft_vec_push_back(list->links[id2 + 1],vertex1);///maybe need link vertex2->new_vertex2
			if (check_double(ft_strjoin("new_", vertex2), list->links[id2]) == -1)
				ft_vec_push_back(list->links[id2],ft_strjoin("new_", vertex2));
		}
		else
		{
			ft_vec_push_back(list->links[id1 + 1], vertex2);
			if (check_double(ft_strjoin("new_", vertex1),list->links[id1]) == -1)
				ft_vec_push_back(list->links[id1],ft_strjoin("new_", vertex1));
		}
	}
	else
	{
		if (check_double(ft_strjoin("new_", vertex1),list->links[id1]) == -1)
			ft_vec_push_back(list->links[id1], ft_strjoin("new_", vertex1));
		if (check_double(ft_strjoin("new_", vertex2), list->links[id2]) == -1)
			ft_vec_push_back(list->links[id2], ft_strjoin("new_", vertex2));
		ft_vec_push_back(list->links[id1 + 1], vertex2);
		ft_vec_push_back(list->links[id2 + 1], vertex1);
	}
}

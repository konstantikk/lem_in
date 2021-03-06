/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_links.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 20:17:56 by vlegros           #+#    #+#             */
/*   Updated: 2019/09/18 22:15:45 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	create_link_with_start(t_farm **farm_ptr, t_parse_link **pl_ptr)
{
	t_parse_link	*pl;
	t_farm			*farm;

	pl = *pl_ptr;
	farm = *farm_ptr;
	if (pl->node1 == farm->end || pl->node2 == farm->end)
		farm->direct_path = TRUE;
	if (pl->node1 == farm->start)
	{
		if (pl->node2 == farm->end)
			pl->node2_flag = TRUE;
		safe_pushback(farm_ptr, pl->node1->links,
				safe_create_link(farm_ptr, pl->node2 != farm->end ?
				ft_strjoin("L", pl->name2) : pl->name2));
	}
	else
	{
		if (pl->node1 == farm->end)
			pl->node1_flag = TRUE;
		safe_pushback(farm_ptr, pl->node2->links,
				safe_create_link(farm_ptr, pl->node1 != farm->end ?
				ft_strjoin("L", pl->name1) : pl->name1));
	}
}

void	link_with_start(t_farm **farm_ptr, t_parse_link **pl_ptr)
{
	t_farm			*farm;
	t_parse_link	*pl;

	farm = *farm_ptr;
	pl = *pl_ptr;
	pl->node1_flag = FALSE;
	pl->node2_flag = FALSE;
	if (pl->node1 == farm->end || pl->node2 == farm->end)
		farm->direct_path = TRUE;
	create_link_with_start(farm_ptr, pl_ptr);
	if (!pl->node1_flag && !pl->node2_flag)
		delete_parse_link_struct(pl_ptr);
	else if (pl->node1_flag || pl->node2_flag)
	{
		pl->node1_flag ?
		ft_memdel((void**)&pl->name2) : ft_memdel((void**)&pl->name1);
		ft_memdel((void**)pl_ptr);
	}
}

void	link_with_end(t_farm **farm_ptr, t_parse_link **pl_ptr)
{
	t_farm			*farm;
	t_parse_link	*pl;

	farm = *farm_ptr;
	pl = *pl_ptr;
	if (pl->node1 == farm->end)
	{
		safe_pushback(farm_ptr, pl->node2->links,
				safe_create_link(farm_ptr, pl->name1));
		ft_memdel((void**)&pl->name2);
	}
	else
	{
		safe_pushback(farm_ptr, pl->node1->links,
				safe_create_link(farm_ptr, pl->name2));
		ft_memdel((void**)&pl->name1);
	}
	ft_memdel((void**)pl_ptr);
}

void	link_with_typ_nodes(t_farm **farm_ptr, t_parse_link **pl_ptr)
{
	t_parse_link *pl;

	pl = *pl_ptr;
	safe_pushback(farm_ptr, pl->node1->links,
			safe_create_link(farm_ptr, ft_strjoin("L", pl->name2)));
	safe_pushback(farm_ptr, pl->node2->links,
			safe_create_link(farm_ptr, ft_strjoin("L", pl->name1)));
	delete_parse_link_struct(pl_ptr);
}

int		read_links(t_farm **farm_ptr, char *buff)
{
	t_parse_link	*pl;
	t_farm			*farm;

	if (!(pl = (t_parse_link*)ft_memalloc(sizeof(t_parse_link))))
		finish_him(farm_ptr);
	farm = *farm_ptr;
	pl->name1 = ft_find_word(buff, 0, '-');
	pl->name2 = pl->name1 ?
			ft_strsub(buff, ft_strlen(pl->name1) + 1,
					ft_strlen(buff) - ft_strlen(pl->name1) - 1) : NULL;
	pl->node1 = pl->name1 ? ht_find_node(farm->nodes, pl->name1) : NULL;
	pl->node2 = pl->name2 ? ht_find_node(farm->nodes, pl->name2) : NULL;
	if (!pl->node1 || !pl->node2)
	{
		delete_parse_link_struct(&pl);
		finish_him(farm_ptr);
	}
	if (pl->node1 == farm->start || pl->node2 == farm->start)
		link_with_start(farm_ptr, &pl);
	else if (pl->node1 == farm->end || pl->node2 == farm->end)
		link_with_end(farm_ptr, &pl);
	else
		link_with_typ_nodes(farm_ptr, &pl);
	return (1);
}

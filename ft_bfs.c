/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bfs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziemann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 20:43:00 by jziemann          #+#    #+#             */
/*   Updated: 2019/08/10 20:43:00 by jziemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

#define INF 1000000

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

static void	bfs_mark_link(t_farm **farm_ptr, t_pvec **q, t_node *check_elem, int i)
{
    t_node *mark_node;
    t_farm  *farm;
	const t_link	*link = check_elem->links->data[i];

	farm = *farm_ptr;
	mark_node = ht_find_node(farm->nodes, link->name);
	if (mark_node->used == FALSE && link->flow != 1)
	{
		mark_node->used = TRUE;
		mark_node->level = check_elem->level + 1;
		if (ft_ptr_vec_pushfront(*q, mark_node) != 1)
        {
		    free((*q)->data);
		    ft_memdel((void**)q);
		    finish_him(farm_ptr);
        }
	}
}

int		ft_bfs(t_farm **farm_ptr)
{
	t_pvec *q;
	t_farm	*farm;
	t_node	*check_elem;
	register int i;

	farm = *farm_ptr;
	nullify(farm->nodes, BOTH);
	farm->start->used = TRUE;
	farm->start->level = 0;
	farm->end->level = -1;
	if (!(q = ft_ptr_vec_init()))
		finish_him(farm_ptr);
	if (ft_ptr_vec_pushback(q, farm->start) != 1)
	{
	    free(q->data);
	    ft_memdel((void**)&q);
		finish_him(farm_ptr);
	}
	while (q->length)
	{
		check_elem = ft_ptr_vec_popback(q);
		i = -1;
		while ((size_t)++i < check_elem->links->length)
			bfs_mark_link(farm_ptr, &q, check_elem, i);
	}
	farm->fixed = farm->end->level;
    free(q->start_data);
    ft_memdel((void**)&q);
	return (farm->end->level != -1);
}

int     zero_one_bfs(t_farm *farm)
{
    t_pvec *q;
    t_node *check_elem;
    t_link *link;
    int     flag = 0;

    if (farm->start->level == -1)
        flag = 1;
    nullify(farm->nodes, BOTH);
    farm->start->level = 0;
    q = ft_ptr_vec_init();
    ft_ptr_vec_pushback(q, farm->start);
    while (q->length)
    {
        check_elem = ft_ptr_vec_popfront(q);
        for (int i = 0; (size_t)i < check_elem->links->length; i++)
        {
            link = check_elem->links->data[i];
            if (flag) {
                if (link->ptr->level > check_elem->level + 1) {
                    link->ptr->level = check_elem->level + 1;
                    link->ptr->prev_level = link->ptr->level;
                    //  link->ptr->used = TRUE;
                    ft_ptr_vec_pushback(q, link->ptr);
                }
            }
            else if (!link->flow && link->ptr->level > check_elem->level + (link->ptr->prev_level < check_elem->level))
            {
                link->ptr->prev_level < check_elem->level ?
                    ft_ptr_vec_pushfront(q, link->ptr) : ft_ptr_vec_pushback(q, link->ptr);
                link->ptr->level = check_elem->level + (link->ptr->prev_level > check_elem->level);
                link->ptr->prev_level = link->ptr->level;
            }
        }
    }
    farm->fixed = farm->end->level;
    return (farm->end->level != INF);
}
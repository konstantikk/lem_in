/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_hashtable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 18:28:37 by vlegros           #+#    #+#             */
/*   Updated: 2019/09/14 22:31:57 by jziemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		del_link(void **link_ptr)
{
	t_link	*link;

	link = *link_ptr;
	ft_memdel((void**)&link->name);
	ft_memdel(link_ptr);
}

static void		del_ht_elem(t_list **head)
{
	t_list *temp;

	temp = *head;
	while (temp)
	{
		*head = temp;
		ft_memdel((void**)&((t_node*)(temp->content))->name);
		ft_ptr_vec_del(&(((t_node*)(temp->content))->links), del_link);
		ft_memdel(&temp->content);
		temp = temp->next;
		ft_memdel((void**)head);
	}
}

static void		ht_delete(t_ht **hashtable)
{
	t_ht			*ht;
	const int		*data = (*hashtable)->loaded->data;
	const size_t	length = (*hashtable)->loaded->length;
	int				i;

	ht = *hashtable;
	i = -1;
	while (++i < length)
		del_ht_elem(&(ht->table[data[i]]));
	free(ht->table);
	ft_int_vec_del(&ht->loaded);
	ft_memdel((void**)hashtable);
}

void			del_path(void **elem)
{
	t_path *path;

	path = *elem;
	ft_ptr_vec_del(&path->path, ft_memdel);
	ft_memdel(elem);
}

void			free_memory(t_farm **farm)
{
	t_farm *to_del;

	to_del = *farm;
	delete_all_flows(&to_del->all_flows);
	ft_int_vec_del(&to_del->loss);
	ft_chr_vec_del(&to_del->output);
	ht_delete(&to_del->nodes);
	ft_memdel((void**)farm);
}

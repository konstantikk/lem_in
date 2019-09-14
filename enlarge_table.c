/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enlarge_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 18:52:12 by vlegros           #+#    #+#             */
/*   Updated: 2019/09/14 22:28:02 by jziemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		del_elem(t_list **head)
{
	t_list *temp;

	temp = *head;
	while (temp)
	{
		*head = temp;
		temp = temp->next;
		ft_memdel((void**)head);
	}
}

static int		copy_element(t_list **dst, t_node *node, size_t capacity, t_ivec *loaded)
{
	const unsigned long index = ft_hash((unsigned char*)node->name, capacity);
	t_list				*temp;
	t_list				*new;

	temp = dst[index];
	if (!temp)
	{
		if (!(dst[index] = ft_lstnew(NULL, 0)))
			return (0);
		dst[index]->content = node;
		ft_int_vec_pushback(loaded, (int)index);
	}
	else
	{
		if (!(new = ft_lstnew(NULL, 0)))
			return (0);
		new->content = node;
		ft_lstadd(&dst[index], new);
	}
	return (1);
}

static int		copy_table(t_ivec *loaded, t_list **dst, t_list **src, t_ht *hashtable)
{
	const size_t		length = hashtable->loaded->length;
	register int		i;
	t_list				*temp;

	i = -1;
	while ((size_t)++i < length)
	{
		temp = src[hashtable->loaded->data[i]];
		while (temp)
		{
			if (!copy_element(dst, temp->content, hashtable->capacity, loaded))
				return (0);
			temp = temp->next;
		}
	}
	return (length);
}

int				ht_enlarge(t_ht *hashtable)
{
	const float load_factor = (float)(hashtable->size + 1) / (float)hashtable->capacity;
	t_list		**resized;
	int			i;
	t_ivec		*new_loaded;

	if (load_factor >= 0.75)
	{
		if (!(resized = (t_list**)malloc(sizeof(t_list*) * (hashtable->capacity * 2))))
			return (0);
		i = -1;
		new_loaded = ft_int_vec_init();
		hashtable->capacity *= 2;
		while ((size_t)++i < hashtable->capacity)
			resized[i] = NULL;
		if (!(i = copy_table(new_loaded, resized, hashtable->table, hashtable)))
			return (0);
		while (i--)
			del_elem(&hashtable->table[ft_int_vec_popback(hashtable->loaded)]);
		ft_int_vec_del(&hashtable->loaded);
		ft_memdel((void**)&hashtable->table);
		hashtable->table = resized;
		hashtable->loaded = new_loaded;
	}
	return (1);
}

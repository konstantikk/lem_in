/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ht_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 17:46:14 by vlegros           #+#    #+#             */
/*   Updated: 2019/08/07 17:46:14 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_ht	*ft_ht_init(void)
{
	t_ht	*hashtable;
	int		i;

	if (!(hashtable = (t_ht*)malloc(sizeof(t_ht))))
		return (NULL);
	if (!(hashtable->loaded = ft_int_vec_init()))
	{
		ft_memdel((void**)&hashtable);
		return (NULL);
	}
	if (!(hashtable->table = (t_list**)malloc(sizeof(t_list*) * HT_START_CAP)))
	{
		ft_int_vec_del(&hashtable->loaded);
		ft_memdel((void**)&hashtable);
		return (NULL);
	}
	i = -1;
	while (++i < HT_START_CAP)
		hashtable->table[i] = NULL;
	hashtable->capacity = HT_START_CAP;
	hashtable->size = 0;
	return (hashtable);
}

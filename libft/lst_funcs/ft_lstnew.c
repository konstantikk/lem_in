/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 16:42:43 by vlegros           #+#    #+#             */
/*   Updated: 2018/12/24 22:42:50 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_elem;

	if (!(new_elem = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		new_elem->content_size = 0;
		new_elem->next = NULL;
		new_elem->content = NULL;
	}
	else
	{
		if (!(new_elem->content = malloc(content_size)))
		{
			ft_memdel((void**)&new_elem);
			new_elem = NULL;
		}
		else
		{
			ft_memcpy(new_elem->content, content, content_size);
			new_elem->content_size = content_size;
			new_elem->next = NULL;
		}
	}
	return (new_elem);
}

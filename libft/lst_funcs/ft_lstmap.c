/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 21:17:37 by vlegros           #+#    #+#             */
/*   Updated: 2018/11/29 14:56:05 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	delete_list(t_list **begin_list)
{
	t_list	*temp;
	t_list	*temp_del;

	temp = *begin_list;
	while (temp)
	{
		temp_del = temp;
		if (temp_del->content)
		{
			free(temp_del->content);
			temp_del->content_size = 0;
		}
		temp = temp->next;
		free(temp_del);
	}
	*begin_list = NULL;
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_list;
	t_list	*new_list_temp;

	new_list = NULL;
	while (lst && f)
	{
		if (!new_list)
		{
			if (!(new_list = f(lst)))
				return (NULL);
			new_list_temp = new_list;
		}
		lst = lst->next;
		if (lst && new_list_temp)
		{
			if (!(new_list_temp->next = f(lst)))
			{
				delete_list(&new_list);
				break ;
			}
			new_list_temp = new_list_temp->next;
		}
	}
	return (new_list);
}

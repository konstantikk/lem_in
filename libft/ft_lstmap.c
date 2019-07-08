/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziemann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 13:44:05 by jziemann          #+#    #+#             */
/*   Updated: 2018/11/29 18:08:22 by jziemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *head;
	t_list *temp;

	head = NULL;
	temp = NULL;
	if (lst == NULL)
		return (NULL);
	head = f(lst);
	if (head)
		temp = head;
	else
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
		if (!(head->next = f(lst)))
		{
			free(head->next);
			return (NULL);
		}
		head = head->next;
	}
	return (temp);
}

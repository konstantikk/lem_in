/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziemann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 13:20:58 by jziemann          #+#    #+#             */
/*   Updated: 2018/11/29 18:08:43 by jziemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*temp;
	t_list	*temp_next;

	if (alst && del)
	{
		temp = *alst;
		while (temp)
		{
			temp_next = temp->next;
			del(temp->content, temp->content_size);
			free(temp);
			temp = temp_next;
		}
		*alst = NULL;
	}
}

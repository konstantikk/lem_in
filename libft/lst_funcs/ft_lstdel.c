/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 19:00:30 by vlegros           #+#    #+#             */
/*   Updated: 2018/11/28 20:52:39 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list *temp;
	t_list *n_temp;

	if (!alst)
		return ;
	temp = *alst;
	while (temp)
	{
		n_temp = temp;
		ft_lstdelone(&n_temp, del);
		temp = temp->next;
	}
	*alst = NULL;
}

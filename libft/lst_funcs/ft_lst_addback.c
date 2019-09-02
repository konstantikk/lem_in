/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_addback.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 19:38:11 by vlegros           #+#    #+#             */
/*   Updated: 2018/12/26 20:01:12 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lst_addback(t_list *head, t_list *new)
{
	t_list	*temp;

	if (!head || !new)
		return ;
	temp = head;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

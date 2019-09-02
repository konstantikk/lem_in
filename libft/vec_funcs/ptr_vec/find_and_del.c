/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_and_del.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 20:22:49 by vlegros           #+#    #+#             */
/*   Updated: 2019/05/20 20:22:49 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		find_and_del(t_pvec *garbage, void *value)
{
	size_t i;

	if (!garbage)
		return ;
	i = -1;
	while (++i < garbage->length)
		if (garbage->data[i] == value)
		{
			ft_memdel(&(garbage->data[i]));
			break ;
		}
}

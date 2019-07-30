/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_vec_del.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 16:40:07 by vlegros           #+#    #+#             */
/*   Updated: 2019/06/30 16:40:07 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_ptr_vec_del(t_vec **vec, void (*del)(void**))
{
	size_t i;

	i = -1;
	if (!(*vec)->data)
		return ;
	while (++i < (*vec)->length)
		del(&(((void**)(*vec)->data)[i]));
	ft_memdel(&((*vec)->data));
	ft_memdel((void**)vec);
}

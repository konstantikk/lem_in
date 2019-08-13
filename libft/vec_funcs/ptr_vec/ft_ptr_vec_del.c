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

void	ft_ptr_vec_del(t_pvec **vec, void (*del)(void**))
{
	size_t i;

	i = -1;
	if (!(*vec)->start_data)
		return ;
	while (++i < (*vec)->length)
		del(&((*vec)->start_data[i]));
	free((*vec)->start_data);
	ft_memdel((void**)vec);
}

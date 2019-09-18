/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chr_vec_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 23:43:20 by vlegros           #+#    #+#             */
/*   Updated: 2019/08/13 23:43:20 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_cvec	*ft_chr_vec_init(size_t size)
{
	t_cvec *vec;

	vec = (t_cvec*)malloc(sizeof(t_cvec));
	if (vec)
	{
		if (!(vec->data = (char*)ft_memalloc(sizeof(char) * size)))
		{
			ft_memdel((void**)&vec);
			return (NULL);
		}
		vec->capacity = size;
		vec->length = 0;
		vec->start_data = vec->data;
	}
	return (vec);
}

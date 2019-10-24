/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chr_vec_enlarge.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 23:51:41 by vlegros           #+#    #+#             */
/*   Updated: 2019/08/13 23:51:41 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_chr_vec_enlarge(t_cvec *vec, size_t len)
{
	char *temp;

	if (!vec)
		return (0);
	if (!vec->capacity)
		vec->capacity = START_CAP;
	if (vec->length + len >= vec->capacity)
	{
		temp = vec->data;
		if (!(vec->data = (char*)ft_memalloc(sizeof(char) *
				(vec->capacity * 2 + len))))
		{
			ft_memdel((void**)&vec->start_data);
			ft_memdel((void**)&vec);
			return (0);
		}
		ft_memmove(vec->data, temp, sizeof(char) * vec->length);
		ft_memdel((void**)&vec->start_data);
		vec->start_data = vec->data;
		vec->capacity = vec->capacity * 2 + len;
	}
	return (1);
}

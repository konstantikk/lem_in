/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_and_enlarge_vec.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 21:44:22 by vlegros           #+#    #+#             */
/*   Updated: 2019/04/14 21:44:22 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "float.h"

int		vec_enlarge(t_vec *vec, long n)
{
	void *new_data;

	if (!vec || n <= 0)
		return (-1);
	if (vec->length + n > vec->capacity)
	{
		if (!(new_data = ft_memalloc((sizeof(char) * (vec->capacity * 2 + n)))))
		{
			vec_del(&vec);
			return (-1);
		}
		vec->capacity = vec->capacity * 2 + n;
		ft_memcpy(new_data, vec->data, vec->length + 1);
		ft_memdel(&(vec->data));
		vec->data = new_data;
		return (1);
	}
	return (0);
}

void	vec_del(t_vec **vec)
{
	t_vec *temp_vec;

	if (!vec && !*vec)
		return ;
	temp_vec = *vec;
	temp_vec->length = 0;
	temp_vec->capacity = 0;
	if (temp_vec->data)
		ft_memdel(&(temp_vec->data));
	free(temp_vec);
	*vec = NULL;
}

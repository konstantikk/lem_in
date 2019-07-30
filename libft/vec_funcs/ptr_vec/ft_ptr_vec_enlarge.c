/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_vec_enlarge.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 18:01:27 by vlegros           #+#    #+#             */
/*   Updated: 2019/05/18 18:01:27 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_ptr_vec_enlarge(t_vec *vec)
{
	void	*temp;

	if (!vec)
		return (0);
	if (vec->length + 1 >= vec->capacity)
	{
		temp = vec->data;
		if (!(vec->data = (void**)malloc(sizeof(void*) * (vec->capacity * 2))))
		{
			ft_memdel((void**)&vec);
			ft_memdel(&temp);
			return (0);
		}
		ft_memcpy(vec->data, temp, sizeof(void*) * vec->length);
		ft_memdel(&temp);
		vec->capacity *= 2;
	}
	return (1);
}

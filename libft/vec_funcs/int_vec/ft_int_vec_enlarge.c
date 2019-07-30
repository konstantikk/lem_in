/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_vec_enlarge.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 13:26:52 by vlegros           #+#    #+#             */
/*   Updated: 2019/05/18 13:26:52 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_int_vec_enlarge(t_ivec *vec)
{
	int *temp;

	if (!vec)
		return (0);
	if (vec->length + 1 >= vec->capacity)
	{
		temp = vec->data;
		if (!(vec->data = (int*)malloc(sizeof(int) * (vec->capacity * 2))))
		{
			ft_memdel((void**)&vec);
			ft_memdel((void**)&temp);
			return (0);
		}
		vec->capacity *= 2;
		ft_memcpy(vec->data, temp, sizeof(int) * vec->length);
		ft_memdel((void**)&temp);
	}
	return (1);
}

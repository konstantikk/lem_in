/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_vec_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 18:00:37 by vlegros           #+#    #+#             */
/*   Updated: 2019/05/18 18:00:37 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vec	*ft_ptr_vec_init(void)
{
	t_vec *vec;

	vec = (t_vec*)malloc(sizeof(t_vec));
	if (vec)
	{
		if (!(vec->data = (void**)malloc(sizeof(void*) * START_CAP)))
		{
			ft_memdel((void**)&vec);
			return (NULL);
		}
		vec->capacity = START_CAP;
		vec->length = 0;
	}
	return (vec);
}

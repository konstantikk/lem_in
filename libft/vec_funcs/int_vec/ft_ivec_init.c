/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ivec_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 13:04:28 by vlegros           #+#    #+#             */
/*   Updated: 2019/05/18 13:04:28 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_ivec	*ft_int_vec_init(void)
{
	t_ivec *vec;

	vec = (t_ivec*)malloc(sizeof(t_ivec));
	if (vec)
	{
		if (!(vec->data = (int*)malloc(sizeof(int) * START_CAP)))
		{
			ft_memdel((void**)&vec);
			return (NULL);
		}
		vec->capacity = START_CAP;
		vec->length = 0;
	}
	return (vec);
}

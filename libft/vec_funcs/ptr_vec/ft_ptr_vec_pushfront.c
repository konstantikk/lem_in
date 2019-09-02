/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_vec_pushfront.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 15:34:04 by vlegros           #+#    #+#             */
/*   Updated: 2019/06/30 15:34:04 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_ptr_vec_pushfront(t_pvec *vec, void *value)
{
	int i;

	if (!vec)
		return (-1);
	if (ft_ptr_vec_enlarge(vec))
	{
		if (vec->length)
		{
			i = vec->length + 1;
			while (--i > 0)
				vec->data[i] = vec->data[i - 1];
		}
		vec->data[0] = value;
		vec->length++;
		return (1);
	}
	return (0);
}

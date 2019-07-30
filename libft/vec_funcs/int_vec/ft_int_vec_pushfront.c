/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_vec_pushfront.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 13:27:40 by vlegros           #+#    #+#             */
/*   Updated: 2019/05/18 13:27:40 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_int_vec_pushfront(t_ivec *vec, int value)
{
	if (!vec)
		return (-1);
	if (ft_int_vec_enlarge(vec))
	{
		if (vec->length)
			ft_memmove(vec->data + 1, vec->data, sizeof(int) * vec->length);
		vec->data[0] = value;
		vec->length++;
		return (1);
	}
	return (0);
}

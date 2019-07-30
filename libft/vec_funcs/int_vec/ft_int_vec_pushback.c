/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_vec_pushback.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 13:27:13 by vlegros           #+#    #+#             */
/*   Updated: 2019/05/18 13:27:13 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_int_vec_pushback(t_ivec *vec, int value)
{
	if (!vec)
		return (-1);
	if (ft_int_vec_enlarge(vec))
	{
		vec->data[vec->length++] = value;
		return (1);
	}
	return (0);
}

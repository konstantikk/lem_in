/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_vec_pushback.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 18:03:09 by vlegros           #+#    #+#             */
/*   Updated: 2019/05/18 18:03:09 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_ptr_vec_pushback(t_pvec *vec, void *value)
{
	if (!vec)
		return (-1);
	if (ft_ptr_vec_enlarge(vec))
	{
		vec->data[vec->length++] = value;
		return (1);
	}
	return (0);
}

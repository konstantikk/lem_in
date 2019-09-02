/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_vec_popfront.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 15:33:40 by vlegros           #+#    #+#             */
/*   Updated: 2019/06/27 15:33:40 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_int_vec_popfront(t_ivec *vec)
{
	int ret_val;

	if (!vec)
		return (-1);
	if (!vec->length || !vec->data)
		return (-1);
	ret_val = vec->data[0];
	ft_memmove(vec->data, vec->data + 1, sizeof(int) * vec->length);
	vec->length--;
	return (ret_val);
}

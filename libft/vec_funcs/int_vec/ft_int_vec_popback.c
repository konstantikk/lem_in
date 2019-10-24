/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_vec_popback.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 22:59:22 by vlegros           #+#    #+#             */
/*   Updated: 2019/08/12 22:59:22 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_int_vec_popback(t_ivec *vec)
{
	int	ret_val;

	if (!vec)
		return (-1);
	if (!vec->length || !vec->data)
		return (-1);
	ret_val = vec->data[vec->length-- - 1];
	return (ret_val);
}

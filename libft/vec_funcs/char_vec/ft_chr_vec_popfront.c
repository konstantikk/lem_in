/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chr_vec_popfront.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 17:28:46 by vlegros           #+#    #+#             */
/*   Updated: 2019/08/14 17:28:46 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_chr_vec_popfront(t_cvec *vec)
{
	char ret_val;

	if (!vec)
		return (-1);
	if (!vec->data)
		return (0);
	if (!vec->capacity || !vec->length)
		return (0);
	ret_val = vec->data[0];
	vec->data++;
	vec->length--;
	vec->capacity--;
	return (ret_val);
}

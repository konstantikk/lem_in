/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chr_vec_pushback.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 23:47:58 by vlegros           #+#    #+#             */
/*   Updated: 2019/08/13 23:47:58 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_chr_vec_pushback(t_cvec *vec, char *value)
{
	const size_t	len = ft_strlen(value);
	register size_t	i;

	if (!vec || !value)
		return (0);
	if (ft_chr_vec_enlarge(vec, len))
	{
		i = -1;
		while (++i < len)
			vec->data[vec->length++] = value[i];
		return (1);
	}
	return (0);
}

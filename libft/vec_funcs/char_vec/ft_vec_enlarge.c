/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_pushback.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 16:02:18 by vlegros           #+#    #+#             */
/*   Updated: 2018/12/09 17:37:43 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_vec_enlarge(t_vec *vec)
{
	void	*temp;

	if (!vec)
		return (-1);
	temp = vec->data;
	if ((vec->data = malloc(vec->capacity * 2)))
	{
		ft_memdel(&temp);
		vec->capacity *= 2;
		return (1);
	}
	return (-1);
}

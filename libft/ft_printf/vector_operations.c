/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 16:15:23 by vlegros           #+#    #+#             */
/*   Updated: 2019/03/30 16:15:23 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "float.h"

int		vec_popfront(t_vec *vec, long n)
{
	if (!vec || n <= 0)
		return (-1);
	vec->length -= n;
	ft_bzero(vec->data, n);
	ft_memmove(vec->data, vec->data + n, vec->length + 1);
	return (1);
}

int		vec_pushfront(t_vec *vec, char c, long n)
{
	long i;

	if (!vec || n <= 0)
		return (-1);
	i = -1;
	if (vec_enlarge(vec, n) != -1)
	{
		ft_memmove(vec->data + n, vec->data, vec->length + 1);
		while (++i < n)
			((char*)(vec->data))[i] = c;
		vec->length += n;
		return (1);
	}
	return (-1);
}

int		vec_insert(t_vec *vec, char c, long n, long place)
{
	if (place <= 0 || !vec || n <= 0)
		return (-1);
	else if (place == 1)
		vec_pushfront(vec, c, n);
	else if (vec_enlarge(vec, n) != -1)
	{
		vec->length += n;
		ft_memmove(vec->data + n + place - 1, vec->data + place - 1,
				vec->length - place + 1);
		while (n--)
			((char*)(vec->data))[place++ - 1] = c;
		return (1);
	}
	return (-1);
}

int		vec_pushback(t_vec *vec, char c, long n)
{
	if (!vec || n <= 0)
		return (-1);
	if (vec_enlarge(vec, n + 1) != -1)
	{
		while (n--)
			((char*)(vec->data))[vec->length++] = c;
		((char*)(vec->data))[vec->length] = '\0';
		return (1);
	}
	return (-1);
}

char	*ft_strrev(char *str)
{
	size_t	i;
	size_t	length;
	char	c;

	i = 0;
	length = ft_strlen(str);
	while (i < length / 2)
	{
		c = str[i];
		str[i] = str[length - 1 - i];
		str[length - 1 - i++] = c;
	}
	return (str);
}

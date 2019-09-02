/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_crt_double_arr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 18:07:34 by vlegros           #+#    #+#             */
/*   Updated: 2019/03/09 17:21:15 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_crt_chmatrix(int height, int length)
{
	char	**arr;
	int		i;

	if (height <= 0 || length <= 0)
		return (NULL);
	if (!(arr = (char**)malloc(sizeof(char*) * (height + 1))))
		return (NULL);
	i = -1;
	while (++i < height)
		if (!(arr[i] = ft_strnew(length)))
		{
			ft_del_twodem_arr((void***)&arr);
			return (NULL);
		}
	arr[i] = NULL;
	return (arr);
}

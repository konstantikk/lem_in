/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziemann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 08:59:07 by jziemann          #+#    #+#             */
/*   Updated: 2018/11/29 19:17:40 by jziemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*del_del(int i, char **arr)
{
	int k;

	k = 0;
	while (k < i)
	{
		free(arr[k]);
		k++;
	}
	free(arr);
	arr = NULL;
	return (arr);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**arr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s == NULL)
		return (0);
	arr = (char **)malloc((ft_count_word(s, c) + 1) * sizeof(char *));
	if (arr == NULL)
		return (NULL);
	while (i < ft_count_word(s, c))
	{
		while (s[j] == c)
			j++;
		arr[i] = ft_find_word(s, j, c);
		if (arr[i] == NULL)
		{
			arr = del_del(i, arr);
			return (arr);
		}
		j += ft_strlen(arr[i++]);
	}
	arr[i] = 0;
	return (arr);
}

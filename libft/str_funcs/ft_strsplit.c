/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 14:08:45 by vlegros           #+#    #+#             */
/*   Updated: 2018/12/24 18:56:43 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define E(x, c) s[x] == c || s[x] == '\0'

static int		words_counter(char const *s, char c)
{
	size_t	counter;
	size_t	i;

	if (!s)
		return (0);
	counter = 0;
	i = 0;
	while (*(s + i))
	{
		if (!(E(i, c)))
			if (E(i + 1, c))
				counter++;
		i++;
	}
	return (counter);
}

static size_t	skip_delim(const char *s, char c, size_t i)
{
	while (E(i, c))
		i++;
	return (i);
}

static char		*get_word(const char *s, char c, size_t ind)
{
	size_t	i;
	size_t	begin;
	size_t	length;

	length = 0;
	begin = skip_delim(s, c, ind);
	i = skip_delim(s, c, ind);
	while (!(E(i, c)))
	{
		length++;
		i++;
	}
	return (ft_strsub(s, begin, length));
}

static	void	del_array(char ***p_arr)
{
	int i;

	i = 0;
	while ((*p_arr)[i])
		free((*p_arr)[i++]);
	free(*p_arr);
	*p_arr = NULL;
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	length;
	char	**arr;
	size_t	i;
	size_t	j;

	length = words_counter(s, c);
	if (!(arr = (char**)malloc(sizeof(char*) * (length + 1))))
		return (NULL);
	i = -1;
	j = 0;
	while (++i < length)
	{
		if (!(arr[i] = get_word(s, c, j)))
		{
			del_array(&arr);
			break ;
		}
		j = skip_delim(s, c, j);
		while (!(E(j, c)))
			j++;
	}
	if (arr)
		arr[i] = NULL;
	return (arr);
}

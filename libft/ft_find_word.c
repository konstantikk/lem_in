/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_word.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziemann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 10:27:05 by jziemann          #+#    #+#             */
/*   Updated: 2018/11/29 19:05:29 by jziemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_find_word(const char *str, int i, char c)
{
	char	*word;
	int		n;
	int		space;

	space = 0;
	n = 0;
	if (str[i] == c)
		while (str[i] == c)
			i++;
	space = i;
	while (str[i++] != c)
		n++;
	word = ft_strsub(str, space, n);
	return (word);
}

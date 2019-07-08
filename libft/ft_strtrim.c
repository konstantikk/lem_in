/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziemann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 12:49:02 by jziemann          #+#    #+#             */
/*   Updated: 2018/11/28 13:24:16 by jziemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char			*clone;
	size_t			len;
	unsigned int	i;

	if (!s)
		return (0);
	i = 0;
	len = ft_strlen(s);
	while (s[len - 1] == ' ' || s[len - 1] == '\t' || s[len - 1] == '\n')
		len--;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
	{
		len--;
		i++;
	}
	if ((int)len <= 0)
		len = 0;
	clone = (char *)malloc(len + 1);
	if (clone == NULL)
		return (NULL);
	s += i;
	ft_strncpy(clone, s, len);
	clone[len] = '\0';
	return (clone);
}

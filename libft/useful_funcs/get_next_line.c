/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 13:24:23 by vlegros           #+#    #+#             */
/*   Updated: 2019/09/18 22:53:48 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static char		*ft_chr_vec_find(t_cvec *vec, char c)
{
	register size_t i;

	i = -1;
	while (++i < vec->length)
		if (vec->data[i] == c)
			return (vec->data + i);
	return (NULL);
}

static char		*ft_chr_vec_pop(t_cvec *vec, char c)
{
	char			*output;
	char			*temp_tail;
	register size_t	i;

	if (!vec->length)
		return (NULL);
	if ((temp_tail = ft_chr_vec_find(vec, c)))
	{
		i = 0;
		*temp_tail = '\0';
		output = (char*)malloc(sizeof(char*) * (temp_tail - vec->data + 1));
		while (vec->data != temp_tail)
			output[i++] = ft_chr_vec_popfront(vec);
		output[i] = ft_chr_vec_popfront(vec);
		return (output);
	}
	output = ft_strnew(vec->length);
	i = -1;
	while (++i < vec->length)
		output[i] = ft_chr_vec_popfront(vec);
	return (output);
}

int				get_next_line(int fd, char **line)
{
	int				rd;
	char			buff[BUFF_SIZE + 1];
	static t_cvec	*vec = NULL;

	if (fd < 0 || !line)
		return (-1);
	if (!vec)
		vec = ft_chr_vec_init(BUFF_SIZE + 1);
	while ((rd = read(fd, buff, BUFF_SIZE)))
	{
		if (!vec || rd == -1)
			return (-1);
		buff[rd] = '\0';
		ft_chr_vec_pushback(vec, buff);
		if (ft_chr_vec_find(vec, '\n'))
			break ;
	}
	if ((*line = ft_chr_vec_pop(vec, '\n')))
		return (1);
	ft_chr_vec_del(&vec);
	return (0);
}

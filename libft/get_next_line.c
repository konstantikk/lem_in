/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziemann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 19:09:17 by jziemann          #+#    #+#             */
/*   Updated: 2019/01/20 19:29:45 by jziemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_list(int fd, t_list **file)
{
	t_list	*temp;
	char	a[1];

	a[0] = '\0';
	temp = *file;
	while (temp)
	{
		if ((int)temp->content_size == fd)
			return (temp);
		temp = temp->next;
	}
	if (!(temp = ft_lstnew(a, fd ? fd : 1)))
		return ((void *)0);
	ft_lstadd(file, temp);
	return (*file);
}

char		*ft_correctline(char **line, char **src)
{
	int i;

	i = ft_strchr((*src), '\n') - (*src);
	if (ft_strchr(*src, '\n'))
	{
		(*src)[i] = '\0';
		if ((*src)[i + 1])
		{
			if ((*line = ft_strdup(*src)) && (ft_strclr(*src)))
				ft_memmove(*src, *(src) + i + 1, ft_strlen(*(src) + i + 1) + 1);
			return (*line);
		}
		else
			*line = ft_strdup(*src);
	}
	else
	{
		if (ft_strlen(*src) > 0)
			*line = ft_strdup(*src);
		else
			return (NULL);
	}
	ft_strclr(*src);
	return (*line);
}

int			read_buffer(char **list, int fd, t_list **file)
{
	char	buff[BUFF_SIZE + 1];
	char	*temp;
	int		rd;

	if (read(fd, buff, 0) < 0)
		return (-1);
	while ((rd = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[rd] = '\0';
		temp = *list;
		if (!(*list = ft_strjoin(temp, buff)))
		{
			*file = (*file)->next;
			return (-1);
		}
		ft_strdel(&temp);
		if (ft_strchr(buff, '\n'))
			return (0);
	}
	return (rd);
}

t_list		*list_rm(t_list *begin, t_list *temp, t_list **file_temp)
{
	if (begin == temp)
		(*file_temp) = begin->next;
	else
	{
		while (begin && begin != temp)
		{
			*file_temp = begin;
			begin = begin->next;
		}
		(*file_temp)->next = (*file_temp)->next->next;
	}
	return (begin);
}

int			get_next_line(const int fd, char **line)
{
	static t_list	*file = NULL;
	t_list			*list;
	int				rd;
	t_list			*file_temp;
	t_list			*file_del;

	if (fd < 0 || !line || FD || !(list = ft_list(fd, &file)))
		return (-1);
	if (!(ft_strchr(list->content, '\n')))
	{
		rd = read_buffer(((char **)(&(list->content))), fd, &file);
		if (rd == -1)
			return (-1);
	}
	if (!(ft_correctline(line, (char**)(&(list->content)))))
	{
		file_temp = NULL;
		file_del = list_rm(file, list, &file_temp);
		free(file_del->content);
		free(file_del);
		if (file == list)
			file = file_temp;
		return (0);
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 13:24:23 by vlegros           #+#    #+#             */
/*   Updated: 2018/12/13 18:52:14 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static int		ft_vec_pushback(t_vec *v, char *buff)
{
	char *temp;

	if (v->capacity >= ft_strlen(buff) + ft_strlen(((char*)v->data)) + 1)
	{
		ft_strcat(__DATA, buff);
		return (1);
	}
	if ((temp = ft_strdup(__DATA)))
	{
		if (ft_vec_enlarge(v) != -1)
		{
			ft_strcpy(__DATA, temp);
			ft_strcat(__DATA, buff);
			ft_strdel(&temp);
			return (1);
		}
		else
			ft_strdel(&temp);
	}
	return (-1);
}

static char		*ft_vec_pop(t_vec *v)
{
	char	*temp_tail;
	char	*output;

	output = NULL;
	if (!(v->data))
		return (NULL);
	temp_tail = ft_strchr(__DATA, '\n');
	if (temp_tail)
	{
		*temp_tail = '\0';
		if (*(temp_tail + 1))
			++temp_tail;
		if ((output = ft_strdup(__DATA)))
		{
			ft_strclr(__DATA);
			ft_memmove(v->data, temp_tail, ft_strlen(temp_tail) + 1);
		}
	}
	else	if (ft_strlen(__DATA) && (output = ft_strdup(__DATA)))
	{
		ft_strclr(__DATA);
		ft_memdel(&(v->data));
	}
	return (output);
}

static t_list	*fd_finder(t_list **head, int fd, size_t size)
{
	t_list	*temp_lst;

	if (!*head)
	{
		if ((*head = ft_lstnew(NULL, 0)))
			if (((*head)->content = ft_vec_init(size)))
			{
				(*head)->content_size = fd;
				return (*head);
			}
	}
	temp_lst = *head;
	while (temp_lst)
	{
		if ((int)temp_lst->content_size == fd)
			return (temp_lst);
		temp_lst = temp_lst->next;
	}
	if ((temp_lst = ft_lstnew(NULL, 0)))
		if ((temp_lst->content = ft_vec_init(size)))
		{
			temp_lst->content_size = fd;
			ft_lstadd(head, temp_lst);
		}
	return (temp_lst);
}

int				get_next_line(int fd, char **line)
{
	int				rd;
	char			buff[BUFF_SIZE + 1];
	static t_list	*lst = NULL;
	t_list			*temp;

	if (fd < 0 || !line)
		return (-1);
	while ((rd = read(fd, buff, BUFF_SIZE)))
	{
		if (!(temp = fd_finder(&lst, fd, BUFF_SIZE + 1)) || rd == -1)
			return (-1);
		buff[rd] = '\0';
		if (ft_vec_pushback(((t_vec*)temp->content), buff) != -1)
			if (ft_strchr(((t_vec*)temp->content)->data, '\n'))
				break ;
	}
	if ((temp = fd_finder(&lst, fd, BUFF_SIZE + 1)))
		if ((*line = ft_vec_pop(((t_vec*)temp->content))))
			return (1);
	return (0);
}

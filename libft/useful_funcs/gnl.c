/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 23:41:59 by vlegros           #+#    #+#             */
/*   Updated: 2019/08/13 23:41:59 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static int             create_string(t_cvec *vec, char **line, char *buff, char *n_ptr)
{
    const size_t buff_len = n_ptr - buff;
    const size_t full_len = vec->length + buff_len + 1;
    register size_t i;
    register size_t j;

    if (!(*line = (char*)malloc(sizeof(char) * full_len)))
        return (-1);
    i = 0;
    while (vec->length)
    {
        (*line)[i] = ft_chr_vec_popfront(vec);
        i++;
    }
    j = -1;
    while (i < full_len)
    {
        (*line)[i] = buff[++j];
        i++;
    }
    (*line)[i] = '\0';
    if (*(n_ptr + 1))
    {
        ft_chr_vec_pushback(vec, n_ptr + 1);
    }
    return (1);
}

int				gnl(int fd, char **line)
{
    int     rd;
    char    buff[BUFF_SIZE + 1];
    static  t_cvec *vec = NULL;
    char    *n_ptr;

    if (!vec)
        vec = ft_chr_vec_init();
    if (fd < 0 || !line)
        return (-1);
    if ((rd = read(fd, buff, BUFF_SIZE)) == -1)
        return (-1);
    buff[rd] = '\0';
    if (rd) {
        if ((n_ptr = ft_strchr(buff, '\n'))) {
            *n_ptr = '\0';
            return (create_string(vec, line, buff, n_ptr));
        } else {
            ft_chr_vec_pushback(vec, buff);
            return (gnl(fd, line));
        }
    }
    return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 20:06:02 by vlegros           #+#    #+#             */
/*   Updated: 2018/12/22 16:41:10 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>

# define BUFF_SIZE 5
# define __DATA ((char*)v->data)
# define DATA_TAIL ((char*)v->data_tail)

int		get_next_line(int fd, char **line);

#endif

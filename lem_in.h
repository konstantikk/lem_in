/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapka                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziemann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 18:51:29 by jziemann          #+#    #+#             */
/*   Updated: 2019/07/08 18:51:29 by jziemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "libft.h"
# include "lem_in.h"
# include <stdio.h>
#include <stdlib.h>

typedef struct	s_link
{
	char	**name;
	char	**start_name;
	size_t	cap;
	size_t	len;
}typedef		t_link;

struct	s_node
{
	char	*name_vertex;
	int		x;
	int		y;
	t_link	*links;
}typedef	t_node;

struct	s_fam
{
	int num_ant;
	int norm_data;

} typedef t_fam;

/*
** char_makevec.c
*/
t_link			*ft_makevec(void);
int				ft_vec_push_back(t_link *vec, char *name);
void			ft_vec_pop_front(t_link *vec);
void			ft_free_vec(t_link **vec);
#endif

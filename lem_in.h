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
	char 	start;
	char 	end;
}				t_link;

typedef struct	s_node
{
	char	**name_vertex;
	//int		x;//coord
	//int		y;//coord
	t_link	**links;

	size_t 	cap;
	size_t 	len;
}				t_node;

typedef struct	s_fam
{
	int num_ant;
	unsigned	norm_ant:1;
	unsigned	norm_start:1;
	unsigned	norm_end:1;
	unsigned	norm_vertex:1;
	unsigned	norm_links:1;
	t_node		*adjacency_list;
}				t_fam;

/*
** char_makevec.c
*/
t_link			*ft_makevec(void);
int				ft_vec_push_back(t_link *vec, char *name);
void			ft_vec_pop_front(t_link *vec);
void			ft_free_vec(t_link **vec);
t_fam			*defective_parse(void);

t_node	*make_vek();
#endif

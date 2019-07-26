/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_makevec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziemann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 18:08:58 by jziemann          #+#    #+#             */
/*   Updated: 2019/07/08 18:08:58 by jziemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"


t_link		*ft_makevec(void)
{
	t_link	*r;

	if (!(r = (t_link *)malloc(sizeof(t_link))))
		return (0);
	r->cap = 10;
	r->len = 0;
	r->start = 0;
	r->end = 0;
	if (!(r->name = (char **)malloc(sizeof(char *) * 10)))
		return (0);
	r->start_name = r->name;
	return (r);
}

int 		ft_vec_push_back(t_link *vec, char *name)
{
	int		i;
	char	**new_name;

	if (!vec)
		return (0);
	if (vec->len + 1 > vec->cap)
	{
		while (vec->len >= vec->cap)
			vec->cap *= 2;
		if (!(new_name = (char **)malloc(vec->cap * sizeof(char *))))
			return (0);
		i = -1;
		while (++i < (int)vec->len)
			new_name[i] = vec->name[i];
		new_name[vec->len++] = name;
		free(vec->start_name);
		vec->name = new_name;
		vec->start_name = vec->name;
	}
	else
		vec->name[vec->len++] = name;
	return (1);
}

char	*ft_vec_pop_front(t_link *vec)//need return vertex
{
	char 	*name;
	if (!vec || !vec->len)
		return (0);
	name = vec->name[0];
	vec->name++;
	vec->cap--;
	vec->len--;
	return (name);
}

void	ft_free_vec(t_link **vec)
{
	if (*vec && (*vec)->start_name)
	{
		free((*vec)->start_name);
		(*vec)->start_name = 0;
	}
	if (*vec)
	{
		free(*vec);
		*vec = 0;
	}
}
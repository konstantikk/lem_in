/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 19:57:47 by vlegros           #+#    #+#             */
/*   Updated: 2019/07/26 19:57:47 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN
# define LEM_IN

#include "./libft/includes/libft.h"

typedef enum e_values
{
	FALSE,
	TRUE,
	START,
	END
}			t_values;

typedef struct	s_node
{
	int		 level;
	unsigned usage:1;
	char	*name;
	t_ivec	*parents;
	t_ivec	*links;
}				t_node;
/*
typedef	struct	s_node
{
	t_hf_node *in;
	t_hf_node *out;
}				t_node;
*/
typedef struct	s_farm
{
	size_t 	ant_num;
	size_t 	start;
	size_t	end;
	t_vec	*nodes;
}				t_farm;

t_farm	*parse(int fd);

#endif
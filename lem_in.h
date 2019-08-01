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

typedef	struct	s_link
{
	int		index;
	int 	capacity;
	int 	reverse;
}				t_link;

typedef struct	s_sub_stream
{
	t_vec	*stream;
	int 	flow_size;
}				t_sub_stream;

typedef struct	s_node
{
	char	*name;
	t_vec	*links;
}				t_node;

typedef struct	s_farm
{
	t_vec	*mainstream;
	t_vec	*nodes;
	int 	*levels;
	int 	*used;
	int 	*parents;
	int		fixed;
	int		ant_num;
	int		start;
	int		end;
}				t_farm;

t_farm	*parse(int fd);
int 	bfs(t_farm *farm);
int 	dfs(t_farm *farm);
int 	dinic(t_farm *farm);
t_sub_stream		*create_substream(t_farm *farm);

#endif
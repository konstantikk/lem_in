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
	int 	flow;
}				t_link;

typedef struct	s_path
{
	t_vec	*path;
	int 	ants_onw;
	int     last_occupied;
}				t_path;

typedef struct  s_room
{
    int node_num;
    int capacity;
    int temp_ant;
}               t_room;

typedef struct	s_node
{
	char	*name;
	t_vec	*links;
}				t_node;

typedef struct	s_farm
{
	t_vec	*stream;
	t_vec	*nodes;
	int 	*levels;
	int 	*used;
	int 	*parents;
	int		fixed;
	int		ant_num;
	int		start;
	int		end;
	int 	max_path;
	int 	min_path;
}				t_farm;

t_farm	*parse(int fd);
int 	bfs(t_farm *farm);
int 	dfs(t_farm *farm);
int 	dinic(t_farm *farm);
t_link	*create_link(int index);
int     release_flow(t_farm *farm);
void    let_the_flow_go(t_farm *farm, t_vec *flow, int ant_num);

#endif
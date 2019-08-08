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
	t_pvec	*path;
	int 	ants_onw;
	int     fixed_ant_num;
	int     last_occupied;
}				t_path;

typedef struct  s_room
{
    int node_num;
    int temp_ant;
}               t_room;

typedef struct	s_node
{
	char	*name;
	t_pvec	*links;
	int *flow;
	int *capacity;
}				t_node;

typedef struct	s_farm
{
	t_pvec	*stream;
	t_ht    *nnodes;
	t_node  *sstart;
	t_node  *eend;
	t_pvec	*nodes;
	int 	*levels;
	int 	*used;
	int 	*parents;
	t_ivec 	*loss;
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
t_vec    *get_flow(t_farm *farm);
int 	*check_profit(t_farm *farm, t_vec *flow, int max);
void    let_the_flow_go(t_farm *farm, t_vec *flow, int ant_num, int *array);
int     ht_insert_node(t_ht *hashtable, t_node *node);
t_node	*create_node(char *name);
int     ht_enlarge(t_ht *hashtable);
void    ht_delete(t_ht **hashtable);
t_node  *ht_find_node(t_ht *hashtable, char *name);
int		new_read_start_end(t_farm *farm, int fd, char **buff, int start_end);
int 	new_read_links(t_farm *farm, char *buff);


#endif
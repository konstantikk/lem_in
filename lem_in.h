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
	END,
	BOTH,
	USED
}			t_values;

typedef struct	s_node t_node;

typedef	struct	s_link
{
	char	*name;
	t_node	*ptr;
	int 	capacity;
	int 	flow;
	int		weight;
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
    char    *name;
    int     temp_ant;
}               t_room;

typedef struct	s_node
{
	char	*name;
	t_pvec	*links;
	int *flow;
	int *capacity;
	int	level;
	struct s_node *parent;
	int used;///
}				t_node;

typedef	struct	s_flow
{
	t_pvec	*flow;
	size_t 	len_flow;
	int 	*ants_allocation;
}				t_flow;

typedef struct	s_farm
{
	t_ht    *nodes;
	t_node  *start;
	t_node  *end;
    t_ivec 	*loss;
    t_pvec	*all_flows;
	int		fixed;
	int		ant_num;
	int     ants_check;

}				t_farm;

t_farm	*parse(int fd);
int		ft_bfs(t_farm **farm_ptr);
int		ft_dfs(t_farm **farm_ptr);
int		ft_dinic(t_farm **farm);
t_link	*create_link(char *name, t_ht *nodes);
void    let_the_flow_go(t_farm **farm_ptr, t_flow **flow, int *ants_allocation);
int     ht_insert_node(t_ht *hashtable, t_node *node);
t_node	*create_node(char *name);
int     ht_enlarge(t_ht *hashtable);
t_node  *ht_find_node(t_ht *hashtable, char *name);
int		read_start_end(t_farm **farm, int fd, char **buff, int start_end);
int 	read_links(t_farm **farm, char *buff);
int 	read_node(t_farm **farm, char *buff);
void    free_memory(t_farm **farm);
void    finish_him(t_farm **farm);
void	nullify(t_ht *nodes, int level_or_used);
t_link	*safe_create_link(t_farm **farm, char *name);
void    safe_pushback(t_farm **farm, t_pvec *links, void *elem);
void    safe_insert(t_farm **farm, t_ht *nodes, t_node *node);
t_path    *create_path(void);
t_room  *create_room(char *name);
void    del_path(void **elem);
void    safe_room_adding(t_farm **farm_ptr, t_path **path_ptr, void *elem, t_pvec **flow);
void	ft_recover_path(t_farm **farm_ptr, t_link *link, t_pvec **flow);
void    sort_flow(t_pvec *flow, size_t len, float step);
t_flow	*ft_get_flow(t_farm **farm_ptr);
int 	ft_check_profit(t_farm *farm, t_pvec *flow, int *ants_allocation, int len_flow);
t_flow	*ft_return_previous_flow(t_farm *farm);
int		dijkstra(t_farm *farm);
void	ft_add_path(t_farm **farm_ptr);
void	dijkstra_potentials(t_farm *farm);
#endif
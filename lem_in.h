/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapka                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 20:23:40 by vlegros           #+#    #+#             */
/*   Updated: 2019/09/19 20:23:40 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "libft.h"
# include "lem_in.h"

# define INF 10000000
# define CAPACITY 7000
# define PATH_LEN(i) ((t_path*)(flow->data[i]))->path->length

enum	e_values
{
	FALSE = 0,
	TRUE,
	START,
	END,
	FULL,
	ANTS_MOVE,
	GRAPH
}				t_values;

typedef struct	s_node
{
	char			*name;
	t_pvec			*links;
	int				level;
	int				potential;
	struct s_node	*parent;
}				t_node;

typedef struct	s_link
{
	char	*name;
	t_node	*ptr;
	int		direction;
	int		flow;
}				t_link;

typedef struct	s_room
{
	char	*name;
	t_node	*ptr;
	int		temp_ant;
}				t_room;

typedef struct	s_path
{
	t_pvec	*path;
	int		ants_onw;
	int		fixed_ant_num;
	int		last_occupied;
}				t_path;

typedef struct	s_flow
{
	t_pvec		*flow;
	size_t		len_flow;
	int			*a_alloc;
}				t_flow;

typedef struct	s_farm
{
	t_ht	*nodes;
	t_node	*start;
	t_node	*end;
	t_ivec	*loss;
	t_pvec	*all_flows;
	t_cvec	*output;
	int		ant_num;
	int		ants_check;
	int		direct_path;
	int		print;
	int		fast;
	int		fd;
	int		num_of_lines;
}				t_farm;

typedef struct	s_parse_link
{
	char	*name1;
	char	*name2;
	t_node	*node1;
	t_node	*node2;
	int		node1_flag;
	int		node2_flag;
}				t_parse_link;

/*
** bin_heap.c
*/
void			bin_heap_swap(void **elem1, void **elem2);
void			sift_up(void **data, int index);
void			sift_down(void **data, int length, int i);
t_node			*pop_min(t_pvec *vec);
/*
** check_profit.c
*/
void			ft_return_previous_flow(t_farm **farm_ptr);
int				ft_release_flow(t_farm **farm_ptr);
/*
** creations.c
*/
t_node			*create_node(char *name);
t_link			*create_link(char *name, t_ht *nodes);
t_path			*create_path(void);
t_room			*create_room(char *name, t_node *node_ptr);
/*
** dijkstra.c
*/
void			check_links(t_node *node, t_pvec **q_ptr, t_farm **farm_ptr);
void			dijkstra(t_farm **farm_ptr);
/*
** enlarge_table.c
*/
int				ht_enlarge(t_ht *ht);
/*
** find_node.c
*/
t_node			*ht_find_node(t_ht *ht, char *name);
/*
** free_memory.c
*/
void			del_path(void **elem);
void			free_memory(t_farm **farm);
/*
** free_memory2.c
*/
void			delete_path(void **elem);
void			delete_one_flow(void **flow_ptr);
void			delete_all_flows(t_pvec **all_flows);
void			delete_parse_link_struct(t_parse_link **pl_ptr);
/*
** ft_add_path.c
*/
void			ft_add_path(t_farm **farm_ptr);
/*
** ft_nullify.c
*/
void			nullify(t_ht *nodes);
/*
** get_optimal_flow.c
*/
void			recalculate_potentials(t_ht *nodes);
void			direct_path(t_farm **farm_ptr);
int				get_optimal_flow(t_farm **farm_ptr);
/*
** insert_node.c
*/
int				ht_help_insert_node(t_ht *hashtable, t_node *node,
			unsigned long index);
int				ht_insert_node(t_ht *hashtable, t_node *node);
/*
** let_the_flow_go.c
*/
void			push_room_with_ant(t_farm **farm_ptr, int ant_index,
			char *room_name);
void			let_the_flow_go(t_farm **farm_ptr, t_flow *flow,
			int *ants_allocation);
/*
** main.c
*/
void			finish_him(t_farm **farm);
/*
** options_parser.c
*/
void			help(t_farm **farm_ptr);
void			get_fd(t_farm **farm_ptr, char *file_name);
void			help_parse_option(char *argv, t_farm **farm_ptr);
void			parse_options(int argc, char **argv, t_farm **farm_ptr);
/*
** parse.c
*/
int				safe_atoi(const char *src, t_farm **farm);
t_farm			*variables_init(void);
void			parse_helper(t_farm **farm_ptr, char **buff_ptr);
void			parse(int fd, t_farm **farm_ptr);
/*
** read_links.c
*/
void			create_link_with_start(t_farm **farm_ptr,
			t_parse_link **pl_ptr);
void			link_with_start(t_farm **farm_ptr, t_parse_link **pl_ptr);
void			link_with_end(t_farm **farm_ptr, t_parse_link **pl_ptr);
void			link_with_typ_nodes(t_farm **farm_ptr, t_parse_link **pl_ptr);
int				read_links(t_farm **farm_ptr, char *buff);
/*
** reading_data.c
*/
int				read_node(t_farm **f, char *buff);
int				read_start_end(t_farm **farm_ptr, int fd, char **buff,
			int start_end);
/*
** recover_path.c
*/
void			ft_recover_path(t_farm **farm_ptr, t_link *link,
			t_pvec **flow);
t_flow			*ft_get_flow(t_farm **farm_ptr);
/*
** safe_creations.c
*/
void			safe_pushback(t_farm **farm, t_pvec *links, void *elem);
void			safe_insert(t_farm **farm, t_ht *nodes, t_node *node);
t_link			*safe_create_link(t_farm **farm, char *name);
void			safe_room_adding(t_farm **farm_ptr, t_path **path_ptr,
			void *elem, t_pvec **flow);
/*
** sort_flow.c
*/
void			bubble_sort(t_pvec *flow, size_t len);
void			sort_flow(t_pvec *flow, size_t len, float step);
#endif

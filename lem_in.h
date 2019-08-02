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

#define NODE(i) ((t_node*)(((void**)(farm->nodes->data))[i]))
#define F_LINK(i, j) ((t_link*)((void**)((t_node*)((void**)(farm->nodes->data))[i])->f_links->data)[j])
#define REV_LINK(i, j) ((t_link*)((void**)((t_node*)((void**)(farm->nodes->data))[i])->rev_links->data)[j])
#define SUBSTREAM(i) ((t_sub_stream*)(((void**)farm->mainstream->data)[i]))

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
}				t_link;

typedef struct	s_sub_stream
{
	t_vec	*stream;
	int 	flow_size;
}				t_sub_stream;

typedef struct	s_node
{
	char	*name;
	t_vec   *f_links;
	t_vec   *rev_links;
	int     reverse;
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

t_farm          *parse(int fd);
int             bfs(t_farm *farm);
int             dfs(t_farm *farm);
int             dinic(t_farm *farm);
t_sub_stream    *create_substream(t_farm *farm);
t_link          *create_link(int index);
void            create_reverse_links(t_farm *farm);

#endif
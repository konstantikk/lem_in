/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flow.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziemann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 17:02:53 by jziemann          #+#    #+#             */
/*   Updated: 2019/08/03 17:02:53 by jziemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

#define NODE(i) ((t_node*)(nodes[i]))
#define LINK(i, j) ((t_link*)((void**)((t_node*)nodes[i])->links->data)[j])
#define LENGTH(i) ((t_path*)(((void**)flow->data)[i]))->path->length
#define ROOM(i, j) ((t_room*)(((void**)((t_path*)(((void**)flow->data)[i]))->path->data)[j]))

int 	*check_profit(t_farm *farm, t_vec *flow, int max)
{
	int *array;
	int sum = 0;
	int additional_ants;
	int residual_ants;
	int max_loss = 0;

	array = (int *)malloc(sizeof(int) * flow->length);
	for (int i = 0; i < (int)flow->length; i++)
	{
		array[i] = max - (int) LENGTH(i) + 1;
		sum += array[i];
		printf(" %2d ", array[i]);
	}

	additional_ants = (farm->ant_num - sum) / flow->length;
	residual_ants = (farm->ant_num - sum) % flow->length;
	printf("\n%d  %d \n", additional_ants, residual_ants);
	for (int i = 0; i < (int)flow->length; i++)
	{
		array[i] += additional_ants;
		if (residual_ants > 0)
		{
			array[i] += 1;
			residual_ants--;
		}
		printf("#%2d ", array[i]);
	}
	for (int i = 0; i < (int)flow->length; i++)
	{
		if (max_loss < LENGTH(i) + array[i] - 1)
			max_loss = LENGTH(i) + array[i] - 1;
	}
	ft_int_vec_pushback(farm->loss, max_loss); ///array[min]
	printf("\n");
	return (array);
}

t_path    *create_path()
{
    t_path *path;

    path = (t_path*)malloc(sizeof(t_path));
    path->path = ft_ptr_vec_init();
    path->ants_onw = 0;
    path->last_occupied = 0;
    return (path);
}

t_room  *create_room(int node_num)
{
    t_room *room;

    room = (t_room*)malloc(sizeof(t_room));
    room->temp_ant = -1;
    room->node_num = node_num;
    return (room);
}

t_vec    *get_flow(t_farm *farm)
{
	void **nodes = farm->nodes->data;
	int		i = -1;
	int		j;
	int 	v;
	t_path *path;
	t_vec *flow;


	flow = ft_ptr_vec_init();
	while (++i < (int) NODE(farm->start)->links->length)
	{
		if ((LINK(farm->start, i)->flow == 1 && LINK(farm->start, i)->capacity == 1))
		{
			path = create_path();
			v = LINK(farm->start, i)->index;
			while (v != farm->end)
			{
				j = -1;
				while (++j < (int)NODE(v)->links->length)
				{
					if (LINK(v, j)->flow == 1 && LINK(v, j)->capacity == 1)
					{
						if (ft_strncmp(NODE(v)->name, "st_", 3))
                        {
						    printf("%s->", NODE(v)->name); ///add strjoin("L",node->name) in vector (path)
						    ft_ptr_vec_pushback(path->path, create_room(v));
                        }
						v = LINK(v, j)->index;
						break ;
					}
				}
			}
			ft_ptr_vec_pushback(path->path, create_room((int)farm->end));
			///add strjoin("L",node->name) in vector (path)
			printf("%s", NODE(farm->end)->name);
			printf("\n");
			if ((int)path->path->length > farm->max_path)
				farm->max_path = (int)path->path->length;
			else if ((int)path->path->length < farm->min_path)
				farm->min_path = (int)path->path->length;
			ft_ptr_vec_pushback(flow, path);
		}
	}

	return (flow);
}

int 	find_previous_max(t_vec *flow, int main_max)
{
	int i;
	int max;

	max = 0;
	i  = -1;
	while (++i < (int)flow->length)
	{
		if (LENGTH(i) > max && LENGTH(i) != main_max)
			max = LENGTH(i);
	}
	return (max);
}

int		release_flow(t_farm *farm)
{
	//void	**nodes = farm->nodes->data;
	int		*array;
	t_vec	*flow;

	printf("\nnew patch \n");
    if (farm->ant_num == 1)
    {
        flow = get_flow(farm);
        //let_the_flow_go(farm, flow, farm->ant_num);
        ///start ant race
        return (0);
    }

    flow = get_flow(farm);

    //let_the_flow_go(farm, flow, farm->ant_num);

    array = check_profit(farm, flow, farm->max_path);
    if (farm->loss->length == 1 || (farm->loss->length > 1 &&
    farm->loss->data[farm->loss->length - 2] > farm->loss->data[farm->loss->length - 1]))
    {
    	/// free array
    	//search continue
      	return (1);
    }
    else if (farm->loss->length > 1 &&
			farm->loss->data[farm->loss->length - 2] < farm->loss->data[farm->loss->length - 1])
    {
      	///free array
      	printf ("AAA\n");
      	array = check_profit(farm, flow,  find_previous_max(flow, farm->max_path));
      	///start and race
      	return (0);
    }
    return (1);
}


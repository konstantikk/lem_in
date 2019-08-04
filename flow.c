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

int 	check_profit()
{

}

t_path    *create_path()
{
    t_path *path;

    path = (t_path*)malloc(sizeof(t_path));
    path->path = ft_ptr_vec_init();
    path->last_occupied = 0;
    return (path);
}

t_room  *create_room(int node_num)
{
    t_room *room;

    room = (t_room*)malloc(sizeof(t_room));
    room->capacity = 0;
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
			ft_ptr_vec_pushback(path->path, create_room((int)farm->nodes));
			///add strjoin("L",node->name) in vector (path)
			printf("%s", NODE(farm->end)->name);
			printf("\n");
			ft_ptr_vec_pushback(flow, path);
		}
	}

	return (flow);
}

int		release_flow(t_farm *farm)
{
	//void	**nodes = farm->nodes->data;
	int		*array;
	t_vec	*flow;

	///int *array_profit;

	printf("\nnew patch \n");
    if (farm->ant_num == 1)
    {
        flow = get_flow(farm);
        ///start ant race
        return (0);
    }
    else
    {
      flow = get_flow(farm);
      array =  (int *)malloc(sizeof(int) * flow->length);
      for (int i = 0; i < (int)flow->length; i++)
	  {
      	array[i] = (int) LENGTH(i) + farm->ant_num - 1;
      	printf("%d ", array[i]);
 	  }
      //sort(array)   new patch it's array[flow->lenght - 1]
      printf("\n");
        /*if (check_profit())
        {
            ///start ant race
            return (0);
        }
        else
        {
            ///array.push_back(profit);
        }*/
    }

    return (1);
}

void    let_the_flow_go(t_farm *farm)
{
    char *ants = (char*)malloc(sizeof(char) * farm->ant_num);
    int i;
    int saved_index = -1;
    int num_of_ways = 68468467;

    i = -1;
    while (++i < farm->ant_num)
        ants[i] = -1;
    while (ants[farm->ant_num - 1] != 1)
    {
        i = -1;
        while (++i < num_of_ways && ++saved_index < farm->ant_num)
        {
            ants[saved_index] = 0; //mark ants that are on their way
            //put them on the start node
            //turn capacity to 1
            //print
        }
        i = -1;
        while (++i < num_of_ways)
        {
            //turn capacity to 0
            //move forward each ant
            /*
             *
             */
            //turn capacity to 1
            //print
            //if ant has reached the finish then mark this ant with 1
            //change index of the last occupied node
        }
        //print '\n'
    }
}


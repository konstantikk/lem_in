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

int 	check_profit()
{

}

t_path    *create_path()
{
    t_path *path;

    path = (t_path*)malloc(sizeof(t_path));
    path->path = ft_ptr_vec_init();
    path->ants_onw = 0;
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
			ft_ptr_vec_pushback(path->path, create_room((int)farm->end));
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
        let_the_flow_go(farm, flow, farm->ant_num);
        ///start ant race
        return (0);
    }
    else
    {
      flow = get_flow(farm);
      let_the_flow_go(farm, flow, farm->ant_num);
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

void    let_the_flow_go(t_farm *farm, t_vec *flow, int ant_num)
{
    char *ants = (char*)malloc(sizeof(char) * ant_num);
    int i;
    int j;
    int saved_index = 0;
    void **nodes = farm->nodes->data;
    int fisrt_entry = FALSE;

    i = -1;
    while (++i < ant_num)
        ants[i] = -1;
    int shit = 0;
    while (ants[ant_num - 1] != 1)
    {
        i = -1;
        while (++i < flow->length && saved_index < ant_num)
        {
            ants[saved_index] = 0;
            ROOM(i, 0)->capacity = 1;
            ROOM(i, 0)->temp_ant = saved_index;
            ((t_path*)((void**)flow->data)[i])->ants_onw++;
            printf("L%d-%s ", saved_index + 1, NODE(ROOM(i, 0)->node_num)->name);
            ++saved_index;

        }
        printf("\n");
        i = -1;
        while (++i < flow->length /*&& fisrt_entry == TRUE*/)
        {
            j = 0;
            while (++j < LENGTH(i)) {

                int l = ROOM(i, j)->capacity, m = ROOM(i, j)->temp_ant;
                int ll = ROOM(i, j - 1)->capacity, mm = ROOM(i, j - 1)->temp_ant;
                if (!ROOM(i, j)->capacity && ROOM(i, j)->temp_ant == -1) {
                        int counter = ((t_path*)((void**)flow->data)[i])->ants_onw;
                        while (counter-- && j > 0)
                        {
                            if (ROOM(i, j)->node_num == farm->end)
                            {
                                ants[ROOM(i, j - 1)->temp_ant] = 1;
                                ((t_path*)((void**)flow->data)[i])->ants_onw--;
                                printf("L%d-%s ", ROOM(i, j - 1)->temp_ant + 1, NODE(ROOM(i, j)->node_num)->name);
                                ROOM(i, j - 1)->temp_ant = -1;
                                ROOM(i, j - 1)->capacity = 0;
                            }
                            else {
                                ROOM(i, j - 1)->capacity = 0;
                                ROOM(i, j)->capacity = 1;
                                ROOM(i, j)->temp_ant = ROOM(i, j - 1)->temp_ant;
                                ROOM(i, j - 1)->temp_ant = -1;
                                printf("L%d-%s ", ROOM(i, j)->temp_ant + 1, NODE(ROOM(i, j)->node_num)->name);
                            }
                            j--;
                        }
                    break ;
                    }
                }
            }
        }

    }



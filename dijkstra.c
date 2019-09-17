/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 15:52:26 by vlegros           #+#    #+#             */
/*   Updated: 2019/09/10 15:52:26 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void    bin_heap_swap(void **elem1, void **elem2)
{
    void *temp;

    temp = *elem1;
    *elem1 = *elem2;
    *elem2 = temp;
}

void    sift_up(void **data, int index)
{
    while (index > 0 &&
     ((t_node*)(data[index]))->level < ((t_node*)(data[(index - 1)/2]))->level)
    {
        bin_heap_swap(&data[index], &data[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

void    sift_down(void **data, int length, int i)
{
    int left;
    int right;
    int j;

    while (2 * i + 1 < length)
    {
        left = 2 * i + 1;
        right = 2 * i + 2;
        j = left;
        if (right < length && ((t_node*)(data[left]))->level > ((t_node*)(data[right]))->level)
            j = right;
        if (((t_node*)(data[j]))->level >= ((t_node*)(data[i]))->level)
            break ;
        bin_heap_swap(&data[i], &data[j]);
        i = j;
    }
}

t_node *pop_min(t_pvec *vec)
{
    //t_node *min_node = ft_ptr_vec_popfront(vec);
    t_node *min_node = vec->data[0];
  //  if (vec->length)
  //  {

        bin_heap_swap(&vec->data[0] , &vec->data[vec->length - 1]);
        vec->length--;
        if(vec->length > 1)
            sift_down(vec->data, vec->length, 0);
   // }
    return (min_node);
}

void        dijkstra(t_farm **farm_ptr)
{
    t_node *node;
    t_link *link;
    t_pvec *q;
    t_farm *farm;
    int 	weight;

    farm = *farm_ptr;
    if (!(q = ft_ptr_vec_init()))
    	finish_him(farm_ptr);
    nullify(farm->nodes, BOTH);
    if (ft_ptr_vec_pushback(q, farm->start) != 1)
	{
		free(q->start_data);
		ft_memdel((void**)&q);
		finish_him(farm_ptr);
	}
    farm->start->level = 0;
    while (q->length)
    {
        //node = ft_ptr_vec_popfront(q);
        node = pop_min(q);
        for (int i = 0; (size_t)i < node->links->length; i++)
        {
             link = node->links->data[i];
             weight = node->level + (link->direction + node->potential - link->ptr->potential);
             if (link->ptr->level > weight && link->flow != 1)
             {
                 link->ptr->level = node->level + weight;
                 link->ptr->parent = node;
                 if (ft_ptr_vec_pushback(q, link->ptr) != 1)
				 {
					 free(q->start_data);
					 ft_memdel((void**)&q);
					 finish_him(farm_ptr);
				 }
          	     sift_up(q->data, q->length - 1);
             }
        }
    }
    free(q->start_data);
    ft_memdel((void**)&q);
}
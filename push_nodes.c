/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 16:42:18 by vlegros           #+#    #+#             */
/*   Updated: 2019/09/15 16:42:18 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void    push_one_node(t_cvec *output, t_node *node)
{
    ft_chr_vec_pushback(output, node->print_line);
    ft_chr_vec_pushback(output, "\n");
}

void    push_nodes(t_farm **farm_ptr, t_flow **flow_ptr)
{
    t_flow *flow;
    t_farm *farm;
    register size_t i;
    register size_t j;
    t_path  *path;

    farm = *farm_ptr;
    flow = *flow_ptr;
    i = -1;
    ft_chr_vec_pushback(farm->output, "##start\n");
    push_one_node(farm->output, farm->start);
    ft_chr_vec_pushback(farm->output, "##end\n");
    push_one_node(farm->output, farm->end);
    while (++i < flow->len_flow)
    {
        j = 1;
        path = flow->flow->data[i];
        while(++j < path->path->length - 1)
            push_one_node(farm->output, ((t_room*)path->path->data[j])->ptr);
    }

}
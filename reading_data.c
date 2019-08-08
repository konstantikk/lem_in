/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 21:26:06 by vlegros           #+#    #+#             */
/*   Updated: 2019/08/08 21:26:06 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		new_read_start_end(t_farm *farm, int fd, char **buff, int start_end)
{
    t_node *node;

    ft_memdel((void**)buff);
    get_next_line(fd, buff);
    if (!(node = create_node(ft_find_word(*buff, 0, ' '))))
        return (0);
    ft_ptr_vec_pushback(farm->nodes, node);
    ht_insert_node(farm->nnodes, node);
    if (start_end == START)
        farm->sstart = node;
    else if (start_end == END)
        farm->eend = node;
    return (1);
}

int 	new_read_links(t_farm *farm, char *buff)
{
    const char	*node_name1 = ft_find_word(buff, 0, '-');
    const char	*node_name2 = ft_strsub(buff, ft_strlen(node_name1) + 1, ft_strlen(buff) - ft_strlen(node_name1) - 1);
    const t_node *node1 = ht_find_node(farm->nnodes, (char*)node_name1);
    const t_node *node2 = ht_find_node(farm->nnodes, (char*)node_name2);

    if (node1 == farm->sstart || node2 == farm->sstart)
    {
        if (node1 == farm->sstart)
        {
            ft_ptr_vec_pushback(node1->links, ft_strjoin("st_", (char*)node_name2));
            //ft_ptr_vec_pushback(((t_node*)(((void**)farm->nodes->data)[index1]))->links, create_link(index2 - 1));
        }
        else
        {
            ft_ptr_vec_pushback(node2->links, ft_strjoin("st_", (char*)node_name1));
            //ft_ptr_vec_pushback(((t_node*)(((void**)farm->nodes->data)[index2]))->links, create_link(index1 - 1));
        }
    }
    else if (node1 == farm->eend || node2 == farm->eend)
    {
        if (node1 == farm->eend)
        {
            ft_ptr_vec_pushback(node2->links, (char*)node_name1);
            //ft_ptr_vec_pushback(((t_node *)(((void **)farm->nodes->data)[index2]))->links, create_link(index1));
        }
        else
        {
            ft_ptr_vec_pushback(node1->links, (char*)node_name2);
            //ft_ptr_vec_pushback(((t_node *)(((void **)farm->nodes->data)[index1]))->links, create_link(index2));
        }
    }
    else
    {
        ft_ptr_vec_pushback(node1->links, ft_strjoin("st_", (char*)node_name2));
        ft_ptr_vec_pushback(node2->links, ft_strjoin("st_", (char*)node_name1));
        //ft_ptr_vec_pushback(((t_node*)(((void**)farm->nodes->data)[index1]))->links, create_link(index2 - 1));
        //ft_ptr_vec_pushback(((t_node*)(((void**)farm->nodes->data)[index2]))->links, create_link(index1 - 1));
    }
    return (1);
}
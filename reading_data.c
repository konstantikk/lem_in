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

int 	read_node(t_farm *farm, char *buff)
{
    t_node	*in_node;
    t_node	*out_node;
    char 	*name;

    name = ft_find_word(buff, 0, ' ');
    if (!(in_node = create_node(ft_strjoin("L", name))))
        return (0);
    if (!(out_node = create_node(name)))
    {
        //del
        return (0);
    }
    ft_ptr_vec_pushback(in_node->links, ft_strdup(out_node->name));
    ft_ptr_vec_pushback(out_node->links, ft_strdup(in_node->name));
    ht_insert_node(farm->nodes, in_node);
    ht_insert_node(farm->nodes, out_node);
    return (1);
}

int		read_start_end(t_farm *farm, int fd, char **buff, int start_end)
{
    t_node *node;

    ft_memdel((void**)buff);
    get_next_line(fd, buff);
    if (!(node = create_node(ft_find_word(*buff, 0, ' '))))
        return (0);
    ht_insert_node(farm->nodes, node);
    if (start_end == START)
        farm->start = node;
    else if (start_end == END)
        farm->end = node;
    return (1);
}

int 	read_links(t_farm *farm, char *buff)
{
    const char	*node_name1 = ft_find_word(buff, 0, '-');
    const char	*node_name2 = ft_strsub(buff, ft_strlen(node_name1) + 1,
            ft_strlen(buff) - ft_strlen(node_name1) - 1);
    const t_node *node1 = ht_find_node(farm->nodes, (char*)node_name1);
    const t_node *node2 = ht_find_node(farm->nodes, (char*)node_name2);

    if (node1 == farm->start || node2 == farm->start)
    {
        if (node1 == farm->start)
            ft_ptr_vec_pushback(node1->links, ft_strjoin("L", (char*)node_name2));
        else
            ft_ptr_vec_pushback(node2->links, ft_strjoin("L", (char*)node_name1));
    }
    else if (node1 == farm->end || node2 == farm->end)
    {
        if (node1 == farm->end)
            ft_ptr_vec_pushback(node2->links, ((char*)node_name1));
        else
            ft_ptr_vec_pushback(node1->links, (char*)node_name2);
    }
    else
    {
        ft_ptr_vec_pushback(node1->links, ft_strjoin("L", (char*)node_name2));
        ft_ptr_vec_pushback(node2->links, ft_strjoin("L", (char*)node_name1));
    }
    return (1);
}
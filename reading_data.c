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

int 	read_node(t_farm **farm, char *buff)
{
    t_node	*in_node;
    t_node	*out_node;
    char 	*name;
    char    *sup_name;

    if (!(name = ft_find_word(buff, 0, ' ')))
        finish_him(farm);
    if (name[0] == 'L' || ft_strchr(name, '-'))
    {
        ft_memdel((void**)&name);
        finish_him(farm);
    }
    if (!(sup_name = ft_strjoin("L", name)))
    {
        ft_memdel((void**)&name);
        finish_him(farm);
    }
    if (!(in_node = create_node(sup_name, buff)))
    {
        ft_memdel((void**)&name);
        ft_memdel((void**)&sup_name);
        finish_him(farm);
    }
    if (!(out_node = create_node(name, buff)))
    {
        ft_memdel((void**)&name);
        ft_memdel((void**)&sup_name);
        finish_him(farm);
    }
    safe_insert(farm, (*farm)->nodes, in_node);
    safe_insert(farm, (*farm)->nodes, out_node);
	safe_pushback(farm, in_node->links, safe_create_link(farm ,ft_strdup(out_node->name)));
	safe_pushback(farm, out_node->links, safe_create_link(farm, ft_strdup(in_node->name)));
    ((t_link*)(out_node->links->data[0]))->direction = -1;
    return (1);
}

int		read_start_end(t_farm **farm, int fd, char **buff, int start_end)
{
    t_node  *node;
    char    *name;

    //ft_memdel((void**)buff);
    get_next_line(fd, buff);
    if (!(name = ft_find_word(*buff, 0, ' ')))
        finish_him(farm);
    if (name[0] == 'L' || ft_strchr(name, '-'))
    {
        ft_memdel((void**)&name);
        finish_him(farm);
    }
    safe_insert(farm, (*farm)->nodes, create_node(name, *buff));
    if (start_end == START)
        (*farm)->start = ht_find_node((*farm)->nodes, name);
    else if (start_end == END)
        (*farm)->end = ht_find_node((*farm)->nodes, name);
    return (1);
}

int 	read_links(t_farm **farm, char *buff)
{
    const char	*node_name1 = ft_find_word(buff, 0, '-');
    const char	*node_name2 = ft_strsub(buff, ft_strlen(node_name1) + 1,
            ft_strlen(buff) - ft_strlen(node_name1) - 1);
    const t_node *node1 = node_name1 ? ht_find_node((*farm)->nodes, (char*)node_name1) : NULL;
    const t_node *node2 = node_name2 ? ht_find_node((*farm)->nodes, (char*)node_name2) : NULL;

//    printf("node_name1: %s\n", node_name1);
 //   printf("node_name2: %s\n", node_name1);
  //  printf("node_ptr1: %s\n", node1);
   // printf("node_ptr2: %s\n\n", node2);
    if (!node1 || !node2)
    {
        ft_memdel((void**)&node_name1);
        ft_memdel((void**)&node_name2);
        finish_him(farm);
    }
    if (node1 == (*farm)->start || node2 == (*farm)->start)
    {
        if (node1 == (*farm)->start)
            safe_pushback(farm, node1->links, safe_create_link(farm, ft_strjoin("L", (char*)node_name2)));
        else
            safe_pushback(farm, node2->links, safe_create_link(farm, ft_strjoin("L", (char*)node_name1)));
    }
    else if (node1 == (*farm)->end || node2 == (*farm)->end)
    {
        if (node1 == (*farm)->end)
            safe_pushback(farm, node2->links, safe_create_link(farm, ((char*)node_name1)));
        else
            safe_pushback(farm, node1->links, safe_create_link(farm, (char*)node_name2));
    }
    else
    {
        safe_pushback(farm, node1->links, safe_create_link(farm, ft_strjoin("L", (char*)node_name2)));
        safe_pushback(farm, node2->links, safe_create_link(farm, ft_strjoin("L", (char*)node_name1)));
    }
    return (1);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_links.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 16:33:42 by vlegros           #+#    #+#             */
/*   Updated: 2019/08/02 16:33:42 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void  push_element(t_vec *f_links, t_vec *rev_links, int index)
{
    if (!index)
        ft_ptr_vec_pushback(rev_links, ft_ptr_vec_popfront(f_links));
    else
    {
        ft_ptr_vec_pushback(rev_links, ((void**)f_links->data)[index]);
        if ((size_t)index == f_links->length - 1)
            ((void **) f_links->data)[index] = NULL;
        else {
            while (index < f_links->length - 1) {
                ((void **) f_links->data)[index] = ((void **) f_links->data)[index + 1];
                index++;
            }
        }
        f_links->length--;
    }
}

void    create_reverse_links(t_farm *farm)
{
    int j;
    for (int i = 0; (size_t)i < farm->nodes->length; i++)
    {
        if (i == farm->start || !ft_strncmp(NODE(i)->name, "st_", 3))
            continue ;
        j = -1;
        while((size_t)++j < NODE(i)->f_links->length)
        {
            if (i == farm->end ||
              (F_LINK(i, j)->index != farm->end && farm->levels[i] > farm->levels[F_LINK(i, j)->index])) {
                push_element(NODE(i)->f_links, NODE(i)->rev_links, j);
                j = -1;
            }
        }
    }
}
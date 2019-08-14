/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chr_vec_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 23:43:20 by vlegros           #+#    #+#             */
/*   Updated: 2019/08/13 23:43:20 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_cvec  *ft_chr_vec_init(void)
{
    t_cvec *vec;

    vec = (t_cvec*)malloc(sizeof(t_cvec));
    if (vec)
    {
        if (!(vec->data = (char*)malloc(sizeof(char) * START_CAP)))
        {
            ft_memdel((void**)&vec);
            return (NULL);
        }
        vec->capacity = START_CAP;
        vec->length = 0;
        vec->start_data = vec->data;
    }
    return (vec);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enlarge_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 18:52:12 by vlegros           #+#    #+#             */
/*   Updated: 2019/08/07 18:52:12 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int     enlarge_table(t_ht *hashtable)
{
    const float load_factor = (float)hashtable->size / (float)hashtable->capacity;
    t_list      **resized;
    int         i;

    if (load_factor >= 0.75)
    {
        if (!(resized = (t_list**)malloc(sizeof(t_list*) * (hashtable->capacity * 2))))
            return (0);
        while (hashtable->loaded->length)
        {

        }
    }
    return (1);
}
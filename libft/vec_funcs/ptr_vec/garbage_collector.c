/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 18:33:34 by vlegros           #+#    #+#             */
/*   Updated: 2019/05/18 18:33:34 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_pvec	*ft_put_in_gc(void *value)
{
	static t_pvec *garbage_collector = NULL;

	if (!garbage_collector)
		if (!(garbage_collector = ft_ptr_vec_init()))
			return (NULL);
	if (value)
		ft_ptr_vec_pushback(garbage_collector, value);
	return (garbage_collector);
}

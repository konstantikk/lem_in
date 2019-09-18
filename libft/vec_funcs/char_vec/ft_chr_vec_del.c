/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chr_vec_del.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 23:59:14 by vlegros           #+#    #+#             */
/*   Updated: 2019/08/13 23:59:14 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_chr_vec_del(t_cvec **vec_ptr)
{
	t_cvec	*vec;

	vec = *vec_ptr;
	ft_memdel((void**)&vec->start_data);
	ft_memdel((void**)vec_ptr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_vec_popback.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 23:02:02 by vlegros           #+#    #+#             */
/*   Updated: 2019/08/12 23:02:02 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_ptr_vec_popback(t_pvec *vec)
{
	void	*ret_val;

	if (!vec)
		return (NULL);
	if (!vec->length || !vec->data)
		return (NULL);
	ret_val = vec->data[vec->length-- - 1];
	return (ret_val);
}

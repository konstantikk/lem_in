/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_vec_popfront.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 15:41:25 by vlegros           #+#    #+#             */
/*   Updated: 2019/06/30 15:41:25 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_ptr_vec_popfront(t_pvec *vec)
{
	void	*ret_val;
	//size_t	i;

	if (!vec)
		return (NULL);
	if (!vec->length || !vec->data)
		return (NULL);
	ret_val = vec->data[0];
	vec->data++;
	vec->capacity--;
	/*i = -1;
	while (++i < vec->length - 1)
		vec->data[i] = vec->data[i + 1];*/
	vec->length--;
	return (ret_val);
}

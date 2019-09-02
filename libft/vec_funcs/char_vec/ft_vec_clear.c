/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 17:41:14 by vlegros           #+#    #+#             */
/*   Updated: 2018/12/09 17:45:58 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_vec_clear(t_vec **vec)
{
	t_vec *temp;

	if (!vec)
		return ;
	temp = *vec;
	if (temp->data)
	{
		free(temp->data);
		temp->data = NULL;
	}
	temp->capacity = 0;
	free(temp);
	temp = NULL;
}

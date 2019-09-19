/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_flow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 20:24:40 by vlegros           #+#    #+#             */
/*   Updated: 2019/09/14 22:35:43 by jziemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		swap_ptr(void **ptr1, void **ptr2)
{
	void	*temp;

	temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
}

void			bubble_sort(t_pvec *flow, size_t len)
{
	register int i;
	register int j;
	register int flag;

	i = -1;
	while ((size_t)++i < len - 1)
	{
		flag = 0;
		j = -1;
		while ((size_t)++j < len - i - 1)
			if (((t_path*)flow->data[j])->path->length >
				((t_path*)flow->data[j + 1])->path->length)
			{
				swap_ptr(&flow->data[j], &flow->data[j + 1]);
				flag = 1;
			}
		if (!flag)
			break ;
	}
}

void			sort_flow(t_pvec *flow, size_t len, float step)
{
	const float		coef = (float)1.247;
	register int	i;

	while ((int)step > 1)
	{
		i = -1;
		while ((size_t)++i + (int)step < len)
			if (((t_path*)flow->data[i])->path->length <
					((t_path*)flow->data[i + (int)step])->path->length)
				swap_ptr(&flow->data[i], &flow->data[i + (int)step]);
		step /= coef;
	}
	bubble_sort(flow, len);
}

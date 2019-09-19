/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_heap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 17:11:39 by vlegros           #+#    #+#             */
/*   Updated: 2019/09/17 17:11:39 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	bin_heap_swap(void **elem1, void **elem2)
{
	void *temp;

	temp = *elem1;
	*elem1 = *elem2;
	*elem2 = temp;
}

void	sift_up(void **data, int index)
{
	while (index > 0 &&
	((t_node*)(data[index]))->level < ((t_node*)(data[(index - 1) / 2]))->level)
	{
		bin_heap_swap(&data[index], &data[(index - 1) / 2]);
		index = (index - 1) / 2;
	}
}

void	sift_down(void **data, int length, int i)
{
	int left;
	int right;
	int j;

	while (2 * i + 1 < length)
	{
		left = 2 * i + 1;
		right = 2 * i + 2;
		j = left;
		if (right < length &&
		((t_node*)(data[left]))->level > ((t_node*)(data[right]))->level)
			j = right;
		if (((t_node*)(data[j]))->level >= ((t_node*)(data[i]))->level)
			break ;
		bin_heap_swap(&data[i], &data[j]);
		i = j;
	}
}

t_node	*pop_min(t_pvec *vec)
{
	t_node *min_node;

	min_node = vec->data[0];
	bin_heap_swap(&vec->data[0], &vec->data[vec->length-- - 1]);
	if (vec->length > 1)
		sift_down(vec->data, vec->length, 0);
	return (min_node);
}

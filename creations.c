/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 21:55:42 by vlegros           #+#    #+#             */
/*   Updated: 2019/07/31 21:55:42 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_sub_stream		*create_substream(t_farm *farm)
{
	t_sub_stream *substream;

	if (!(substream = (t_sub_stream*)malloc(sizeof(t_sub_stream))))
		return (NULL);
	substream->flow_size = farm->fixed;
	substream->stream = ft_ptr_vec_init();
	return (substream);
}
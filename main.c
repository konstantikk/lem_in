/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziemann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 17:18:17 by jziemann          #+#    #+#             */
/*   Updated: 2019/07/08 17:18:17 by jziemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_fam	*parse_map(void)
{
	t_fam	*fam;
	char 	*buff;
	char 	*line;

	if (!(fam = (t_fam *)malloc(sizeof(t_fam))))
		return (0);
	get_next_line(0, &buff);
	if (!ft_isdigit(*buff))
		exit(0);
	fam->num_ant = ft_atoi(buff);
	if (fam->num_ant > 0)
		fam->norm_data = 1;
	while (get_next_line(0, &buff))
	{
		if ((line = ft_strchr(buff, '#')))
		{
			if (++*line == '#')
			{
				///start or finish
			}
			else
			{
				ft_strdel(&buff);
				continue ;
			}
		}
		else if ((line = ft_strchr(buff, '-')))
		{
			///parse links
		}
		else
		{

			///parse vertex [node coord_x coord_y]
		}
		ft_strdel(&buff);
	}
	return (fam);
}

int		main(void)
{
	t_fam *fam;

	fam = parse_map();
	return (0);
}
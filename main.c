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

int 	check_vertex_standard(char *line)
{
	int count;

	count = 0;
	printf("%s\n", line);
	if (!line)
	{
		printf("b");
		exit(0);
	}
	while (*line)
	{
		if (*line == ' ')
			count++;
		else if (count > 1 && !ft_isdigit(*line))
		{
			printf("%c\n", *line);
			exit(0);
		}
		line++;
	}
	if (count == 2)
		return (1);
	else
		return (0);
}

t_fam	*parse_map()
{
	t_fam	*fam;
	char 	*buff;
	char 	*line;

	if (!(fam = (t_fam *)malloc(sizeof(t_fam))))
		return (0);
	get_next_line(0, &buff);
	if (!ft_isdigit(*buff))
	{
		printf("S\n");
		exit(0);
	}
	fam->num_ant = ft_atoi(buff);
	if (fam->num_ant > 0)
		fam->norm_ant++;
	while (get_next_line(0, &buff))
	{
		if ((line = ft_strchr(buff, '#')))
		{
			if (*(++line) == '#')
			{
				///start or end
				if (ft_strcmp(++line, "start"))
					fam->norm_start = 1;///parse next line immediately, it's start
				else if (ft_strcmp(++line, "end"))
					fam->norm_end = 1 ; ///parse next line immediately, it's end
				else
				{
					ft_strdel(&buff);
					continue ;
				}
			}
			else
			{
				ft_strdel(&buff);
				continue ;
			}
		}
		else if (ft_strchr(buff, '-'))
		{
			fam->norm_links = 1;
			///parse links
		}

		else if (check_vertex_standard(buff))
		{
			fam->norm_vertex = 1;
			///parse vertex [node coord_x coord_y]
		}
		else
		{
			ft_strdel(&buff);
			printf("a");
			exit(0);
		}
		ft_strdel(&buff);
	}
	return (fam);
}

int		main()
{
	t_fam *fam;

	fam = defective_parse();//parse_map();
	//printf("!%d\n%c\n%c\n%c\n%c\n%c\n!", fam->num_ant, fam->norm_start, fam->norm_end, fam->norm_links, fam->norm_vertex, fam->norm_ant);
	/**for (int i = 0; i < fam->adjacency_list->len; i++)
	{		//if (fam->adjacency_list->links[i].start == '1' || fam->adjacency_list->links[i].end == '1' )
			printf("%s\t%c\t%c->", fam->adjacency_list->name_vertex[i], fam->adjacency_list->links[i]->start, fam->adjacency_list->links[i]->end);
			for (int j = 0; j < fam->adjacency_list->links[i]->len; j++)
				printf("%s\t", fam->adjacency_list->links[i]->name[j]);
			printf("\n");
	}**/
	bfs(fam->adjacency_list);
	return (0);
}
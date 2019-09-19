/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 16:14:13 by vlegros           #+#    #+#             */
/*   Updated: 2019/09/19 16:14:13 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	help(t_farm **farm_ptr)
{
	ft_printf("options:\n");
	ft_printf("{BLUE}--help -h{GREY}         shows usage\n");
	ft_printf("{BLUE}--fast -f{GREY}         show only number of lines\n");
	ft_printf("{BLUE}--print={RED}full{GREY} shows full output doesnt work with"
"{BLUE}--fast -f{GREY} option   \n");
	ft_printf("{BLUE}--print={RED}ants_move{GREY}");
	ft_printf(" shows only ants movement doesnt work with {BLUE}--fast "
	"-f{GREY} option\n");
	ft_printf("{BLUE}--print={RED}graph{GREY} shows only graph doesnt work "
	"with {BLUE}--fast -f{GREY} option   \n");
	ft_printf("{BLUE}--file={RED}file_name{GREY} default reading from STDIN\n");
	free_memory(farm_ptr);
	exit(1);
}

void	get_fd(t_farm **farm_ptr, char *file_name)
{
	const int	fd = open(file_name, 'r');
	t_farm		*farm;

	farm = *farm_ptr;
	if (fd == -1)
		finish_him(farm_ptr);
	farm->fd = fd;
}

void	help_parse_option(char *argv, t_farm **farm_ptr)
{
	t_farm			*farm;

	farm = *farm_ptr;
	if (!ft_strcmp(argv, "--help") || !ft_strcmp(argv, "-h"))
		help(farm_ptr);
	else if (!ft_strcmp(argv, "--fast") || !ft_strcmp(argv, "-f"))
		farm->fast = TRUE;
	else if (!ft_strcmp(argv, "--print=full"))
		farm->print = FULL;
	else if (!ft_strcmp(argv, "--print=graph"))
		farm->print = GRAPH;
	else if (!ft_strcmp(argv, "--print=ants_move"))
		farm->print = ANTS_MOVE;
	else if (!ft_strncmp(argv, "--file=", 7))
		get_fd(farm_ptr, argv + 7);
	else
	{
		write(2, "WRONG OPTION\n", 13);
		help(farm_ptr);
	}
}

void	parse_options(int argc, char **argv, t_farm **farm_ptr)
{
	register int	i;
	t_farm			*farm;

	farm = *farm_ptr;
	i = 0;
	while (++i < argc)
	{
		if (argv[i][0] == '-')
			help_parse_option(argv[i], farm_ptr);
	}
}

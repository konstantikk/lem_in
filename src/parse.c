/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 19:58:37 by vlegros           #+#    #+#             */
/*   Updated: 2019/07/26 19:58:37 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	dec_check(char c, t_farm **farm)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	finish_him(farm);
	return (-1);
}

int			safe_atoi(const char *src, t_farm **farm)
{
	int result;
	int sign;

	result = 0;
	sign = 1;
	while (*src == 32 || (*src >= 9 && *src <= 13))
		src++;
	if (*src == '+')
	{
		src++;
		sign *= 1;
	}
	while (*src >= '0' && *src <= '9')
		result = result * 10 + dec_check(*src++, farm);
	if (result * sign < 0)
		finish_him(farm);
	return (result * sign);
}

t_farm		*variables_init(void)
{
	t_farm *farm;

	if (!(farm = (t_farm*)ft_memalloc(sizeof(t_farm))))
		return (NULL);
	if (!(farm->nodes = ft_ht_init()) ||
	!(farm->output = ft_chr_vec_init(CAPACITY)) ||
	!(farm->loss = ft_int_vec_init()) ||
	!(farm->all_flows = ft_ptr_vec_init()))
		finish_him(&farm);
	farm->direct_path = FALSE;
	farm->ants_check = 0;
	farm->ant_num = 0;
	farm->print = FULL;
	farm->fast = FALSE;
	farm->num_of_lines = 0;
	farm->fd = 0;
	return (farm);
}

void		parse_helper(t_farm **farm_ptr, char **buff_ptr)
{
	char	*buff;
	t_farm	*farm;

	buff = *buff_ptr;
	farm = *farm_ptr;
	if (buff[0] == '#' && buff[1] && buff[1] != '#')
	{
		ft_memdel((void**)buff_ptr);
		return ;
	}
	if (farm->fast == FALSE && (farm->print == FULL || farm->print == GRAPH))
		if (ft_chr_vec_pushback(farm->output, buff) != 1 ||
		ft_chr_vec_pushback(farm->output, "\n") != 1)
		{
			ft_memdel((void**)buff_ptr);
			finish_him(farm_ptr);
		}
	ft_memdel((void**)buff_ptr);
}

void		parse(int fd, t_farm **farm_ptr)
{
	t_farm	*farm;
	char	*buff;

	farm = *farm_ptr;
	while (get_next_line(fd, &buff) == 1)
	{
		if (!farm->ant_num)
			farm->ant_num = safe_atoi(buff, &farm);
		else if (buff[0] == '#')
		{
			if (!ft_strcmp(buff, "##start"))
				read_start_end(farm_ptr, fd, &buff, START);
			else if (!ft_strcmp(buff, "##end"))
				read_start_end(farm_ptr, fd, &buff, END);
		}
		else if (ft_strchr(buff, '-'))
			read_links(farm_ptr, buff);
		else
			read_node(farm_ptr, buff);
		parse_helper(farm_ptr, &buff);
	}
	if (farm->fast == FALSE && (farm->print == FULL || farm->print == GRAPH))
		ft_chr_vec_pushback(farm->output, "\n");
}

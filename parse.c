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

static int  dec_check(char c, t_farm **farm)
{
     if (c >= '0' && c <= '9')
         return (c - '0');
     finish_him(farm);
     return (-1);
}

int		safe_atoi(const char *src, t_farm **farm)
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
    return (result * sign);
}

t_farm	*parse(int fd)
{
	t_farm	*farm;
	char	*buff = NULL;

	if (!(farm = (t_farm*)ft_memalloc(sizeof(t_farm))))
		return (NULL);
	farm->nodes = ft_ht_init();
	farm->ants_check = 0;
	while (get_next_line(fd, &buff))
	{
		if (!farm->ant_num)
			farm->ant_num = safe_atoi(buff, &farm);
		else if (buff[0] == '#')
		{
			if (!ft_strcmp(buff, "##start"))
			    read_start_end(&farm, fd, &buff, START);
			else if (!ft_strcmp(buff, "##end"))
                read_start_end(&farm, fd, &buff, END);
		}
		else if (ft_strchr(buff, '-'))
		    read_links(&farm, buff);
		else
			read_node(&farm, buff);
		ft_memdel((void**)&buff);
	}
	farm->loss = ft_int_vec_init();/// todo error
	farm->all_flows = ft_ptr_vec_init();/// todo error
	return (farm);
}

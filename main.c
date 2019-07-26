/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 19:57:35 by vlegros           #+#    #+#             */
/*   Updated: 2019/07/26 19:57:35 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int 	main(int argc, char **argv)
{
	t_farm *farm;
	//char *hey = argv[1];
	int fd = open(argv[1], O_RDONLY);
	farm = parse(fd);
	for (int i = 0; (size_t)i < farm->nodes->length; i++)
	{
		printf("%s\n", ((t_node*)(((void**)(farm->nodes->data))[i]))->name);
	}
	printf("\n%zu, %zu", farm->start, farm->end);
	close(fd);
	return (0);
}
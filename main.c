/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 09:48:41 by mlu               #+#    #+#             */
/*   Updated: 2017/06/29 15:51:34 by jkrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utility.h"
#include "fillit.h"
#define BUF_SIZE 21

char	*read_input(int fd)
{
	char			*temp;
	char			*output;
	char			input[BUF_SIZE + 1];
	unsigned int	memory;

	memory = 0;
	temp = (char*)malloc(sizeof(*output) * (memory + 1));
	output = (char*)malloc(sizeof(*output) * (memory + 1));
	while ((read(fd, input, BUF_SIZE)) > 0)
	{
		memory += BUF_SIZE;
		ft_strcpy(temp, output);
		free(output);
		output = (char*)malloc(sizeof(*output) * (memory + 1));
		ft_strcpy(output, temp);
		ft_strcat(output, input, &memory, BUF_SIZE);
		output[memory] = '\0';
		free(temp);
		temp = (char*)malloc(sizeof(*temp) * (memory + 1));
	}
	free(temp);
	return (output);
}

int		main(int ac, char **av)
{
	char	*list;
	int		mluisreallypicky;
	t_shape	*start_shape;
	t_shape	*last_shape;
	t_grid	*gridpls;

	if (ac != 2)
	{
		ft_putstr("error\n");
		return (0);
	}
	list = read_input(open(av[1], O_RDONLY));
	mluisreallypicky = ft_validate(list);
	start_shape = new_shape('@');
	last_shape = start_shape;
	if (mluisreallypicky > 0)
	{
		ft_parseshapes(list, mluisreallypicky, &last_shape);
		gridpls = grid_new(mluisreallypicky, mluisreallypicky);
		solve_grid(gridpls, start_shape->next);
		ft_putstr(gridpls->buffer);
	}
	else
		ft_putstr("error\n");
	return (0);
}

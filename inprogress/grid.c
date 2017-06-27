/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrause <jkrause@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 19:43:54 by jkrause           #+#    #+#             */
/*   Updated: 2017/06/26 21:15:08 by jkrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_grid					*grid_new(int x, int y)
{
	t_grid				*new;

	new = (t_grid*)malloc(sizeof(t_grid));
	new->buffer = (char*)malloc(sizeof(char) * (x * y));
	new->grid = (char**)malloc(sizeof(char*) * x);
	new->rows = x;
	new->columns = y;
	grid_init(new);
	//printf("BUFFER:\n%s\n", new->buffer);
	return (new);
}

void					grid_init(t_grid *grid)
{
	int					i;
	int					j;

	i = -1;
	while (++i < grid->rows)
	{
		grid->grid[i] = grid->buffer + (i * (grid->columns + 1));
		j = -1;
		while (++j < grid->columns)
			grid->grid[i][j] = '.';
		grid->grid[i][j] = '\n';
	}
	grid->grid[grid->rows] = "\0";
}

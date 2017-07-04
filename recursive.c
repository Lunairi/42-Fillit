/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrause <jkrause@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 20:59:44 by jkrause           #+#    #+#             */
/*   Updated: 2017/07/03 17:43:16 by jkrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_n_write(t_grid *grid, t_shape *shape, int curpos, int index)
{
	if (index >= 4)
		return (1);
	if (grid->buffer[curpos + shape->offsets[index]] == '.')
		if (check_n_write(grid, shape, curpos, index + 1))
		{
			grid->buffer[curpos + shape->offsets[index]] = shape->letter;
			return (1);
		}
	return (0);
}

void	unwrite(t_grid *grid, t_shape *shape, int curpos)
{
	int i;

	i = 0;
	while (i < 4)
		grid->buffer[curpos + shape->offsets[i++]] = '.';
}

int		solve_grid(t_grid *grid, t_shape *shape)
{
	int x;
	int y;

	if (shape == 0)
		return (1);
	x = 0;
	while (x < grid->rows)
	{
		y = 0;
		while (y < grid->columns)
		{
			if (check_n_write(grid, shape, GETPOS(x, y), 0))
			{
				if (solve_grid(grid, shape->next))
					return (1);
				unwrite(grid, shape, GETPOS(x, y));
			}
			y++;
		}
		x++;
	}
	return (0);
}

t_shape	*test_shape(int *arr, char ltr)
{
	t_shape		*shape;

	shape = (t_shape*)malloc(sizeof(t_shape));
	shape->offsets = arr;
	shape->letter = ltr;
	shape->next = 0;
	return (shape);
}

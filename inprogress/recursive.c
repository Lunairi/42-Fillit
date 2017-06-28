/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrause <jkrause@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 20:59:44 by jkrause           #+#    #+#             */
/*   Updated: 2017/06/27 22:23:10 by jkrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


int				check_n_write(t_grid *grid, t_shape *shape, int curpos, int index)
{
	if (index >= 4)
		return (1);
	printf("CHK: %c - %d\n", grid->buffer[curpos + shape->offsets[index]], index);
	if (grid->buffer[curpos + shape->offsets[index]] == '.')
		if (check_n_write(grid, shape, curpos, index+1))
		{
			grid->buffer[curpos + shape->offsets[index]] = shape->letter;
			return (1);
		}
	return (0);
}

int				solve_grid(t_grid *grid, t_shape *shape)
{
	int				x;
	int				y;

	if (shape == 0)
		return (1);
	printf("SHAPE: %c\n", shape->letter);
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
			}
			y++;
		}
		x++;
	}
	return (0);
}

t_shape			*test_shape(int *arr, char ltr)
{
	t_shape		*shape = (t_shape*)malloc(sizeof(t_shape));
	shape->offsets = arr;
	shape->letter = ltr;
	shape->next = 0;
	return (shape);
}

int				main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	int aint[4] = {0,1,2,3};
	int bint[4] = {0,5,4,9};
	t_shape *a = test_shape(aint, 'A');
	t_shape *b = test_shape(bint, 'B');
	a->next = b;

	t_grid *grid = grid_new(4, 4);
	printf("%d\n", solve_grid(grid, a));
	printf("%s\n", grid->buffer);
}


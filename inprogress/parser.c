/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrause <jkrause@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 11:58:19 by jkrause           #+#    #+#             */
/*   Updated: 2017/06/28 18:33:10 by jkrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_shape			*new_shape(char ltr)
{
	t_shape		*shape = (t_shape*)malloc(sizeof(t_shape));
	shape->offsets = (int*)malloc(sizeof(int) * 4);
	shape->letter = ltr;
	shape->next = 0;
	return (shape);
}

void				fill_offsets(t_shape *shape, char *arr)
{
	int				i;
	int				c;
	int				oc;

	i = -1;
	c = 0;
	oc = 0;
	while (arr[++i] != '\0')
	{
		if (c > 3)
			break;
		if (arr[i] == '#')
		{
			shape->offsets[c++] = i;
			oc = (shape->offsets[0] > 0 ? shape->offsets[0] : oc);
			shape->offsets[c - 1] -= oc;
			//printf("FO: %c%d: %d\n", shape->letter, i, shape->offsets[c - 1]);
		}
	}
}

int					offtake(int count)
{
	int				i;
	int				t;

	t = count;
	i = 0;
	while (t >= 4)
	{
		t -= 4;
		i++;
	}
	//printf("STATS: %d %d\n", t, i);
	return (i);
}

t_shape				*parse_shape(char *arr, char ltr, int expected_gridsize)
{
	t_shape			*shape;
	int				i;
	int				c;
	int				mul;

	//printf("SHAPE:\n%s\n", arr);
	shape = new_shape(ltr);
	fill_offsets(shape, arr);
	i = -1;
	c = 0;
	while (++i < 4)
	{
	//	printf("O%d: %d\n", i, shape->offsets[i]);
		if (shape->offsets[i] >= 4)
		{
			mul = offtake(shape->offsets[i]);
		//	printf("MUL: %d - %d\n", mul, (mul / 4));
			shape->offsets[i] -= (mul * 4);
			shape->offsets[i] += (expected_gridsize * mul);
		}

	//	printf("F%d: %d\n", i, shape->offsets[i]);
	}
	//shape->offsets[3] += 1;
	return (shape);
}

int				ma2in(int argc, char **argv)
{
	char *test = ".##.\n.#..\n.#..\n....\n";
	int expected_gridsize = 6;

	printf("TEST SHAPE:\n%s\n", test);
	(void)argc;
	(void)argv;
	t_shape *shape = parse_shape(test, 'A', expected_gridsize);
	t_shape *last_shape = shape;
	last_shape->next = parse_shape("....\n....\n.###\n...#\n", 'B', expected_gridsize);
	last_shape = last_shape->next;
	last_shape->next = parse_shape("..#.\n..#.\n.##.\n....\n", 'C', expected_gridsize);
	last_shape = last_shape->next;
	last_shape->next = parse_shape(".###\n..#.\n....\n....\n", 'D', expected_gridsize);
	last_shape = last_shape->next;
	last_shape->next = parse_shape("...#\n..##\n..#.\n....\n", 'E', expected_gridsize);
	last_shape = last_shape->next;
	last_shape->next = parse_shape("..##\n..##\n....\n....\n", 'F', expected_gridsize);
	last_shape = last_shape->next;
	last_shape->next = parse_shape(".##.\n..##\n....\n....\n", 'G', expected_gridsize);
	last_shape = last_shape->next;
	printf("%c\n", shape->letter);
	t_grid *grid = grid_new(expected_gridsize, expected_gridsize);
	solve_grid(grid, shape);
	//solve_grid(grid, shape->next->next->next->next);
	printf("\nSOLUTION:\n%s\n", grid->buffer);
	return (0);
}


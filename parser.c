/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrause <jkrause@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 11:58:19 by jkrause           #+#    #+#             */
/*   Updated: 2017/07/03 17:42:53 by jkrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_shape				*new_shape(char ltr)
{
	t_shape				*shape;

	shape = (t_shape*)malloc(sizeof(t_shape));
	shape->offsets = (int*)malloc(sizeof(int) * 4);
	shape->letter = ltr;
	shape->next = 0;
	return (shape);
}

void				fill_offsets(t_shape *shape, char *arr)
{
	int					i;
	int					c;
	int					oc;

	i = -1;
	c = 0;
	oc = 0;
	while (arr[++i] != '\0')
	{
		if (c > 3)
			break ;
		if (arr[i] == '#')
		{
			shape->offsets[c++] = i;
			oc = (shape->offsets[0] > 0 ? shape->offsets[0] : oc);
			shape->offsets[c - 1] -= oc;
			if (c == 2
					&& ((shape->offsets[c - 1] - shape->offsets[c - 2]) == 3))
				shape->offsets[c - 1] += 1;
		}
	}
}

int					offtake(int count, int max)
{
	int					i;
	int					t;

	t = count;
	i = 0;
	while (t >= max)
	{
		t -= max;
		i++;
	}
	return (i);
}

void				shape_offset_calc(t_shape *shape, int e_gridsize, int i)
{
	int					mul;
	int					offset;

	if (shape->offsets[i] >= 4)
	{
		offset = 4;
		mul = offtake(shape->offsets[i], offset);
		shape->offsets[i] -= (mul * offset);
		shape->offsets[i] += (e_gridsize * mul);
	}
	if (i > 0 && (shape->offsets[i] - shape->offsets[i - 1]) == 0)
		shape->offsets[i - 1] -= 1;
}

t_shape				*parse_shape(char *arr, char ltr, int expected_gridsize)
{
	t_shape				*shape;
	int					i;
	int					c;

	shape = new_shape(ltr);
	fill_offsets(shape, arr);
	i = -1;
	c = 0;
	while (++i < 4)
		shape_offset_calc(shape, expected_gridsize, i);
	return (shape);
}

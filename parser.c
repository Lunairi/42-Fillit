/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrause <jkrause@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 11:58:19 by jkrause           #+#    #+#             */
/*   Updated: 2017/06/29 15:45:30 by jkrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_shape		*new_shape(char ltr)
{
	t_shape	*shape;

	shape = (t_shape*)malloc(sizeof(t_shape));
	shape->offsets = (int*)malloc(sizeof(int) * 4);
	shape->letter = ltr;
	shape->next = 0;
	return (shape);
}

void		fill_offsets(t_shape *shape, char *arr)
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
			break ;
		if (arr[i] == '#')
		{
			shape->offsets[c++] = i;
			oc = (shape->offsets[0] > 0 ? shape->offsets[0] : oc);
			shape->offsets[c - 1] -= oc;
		}
	}
}

int			offtake(int count)
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
	return (i);
}

t_shape		*parse_shape(char *arr, char ltr, int expected_gridsize)
{
	t_shape			*shape;
	int				i;
	int				c;
	int				mul;

	shape = new_shape(ltr);
	fill_offsets(shape, arr);
	i = -1;
	c = 0;
	while (++i < 4)
	{
		if (shape->offsets[i] >= 4)
		{
			mul = offtake(shape->offsets[i]);
			shape->offsets[i] -= (mul * 4);
			shape->offsets[i] += (expected_gridsize * mul);
		}
	}
	return (shape);
}

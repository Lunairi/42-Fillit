/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dans_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrause <jkrause@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 17:39:03 by jkrause           #+#    #+#             */
/*   Updated: 2017/06/29 15:39:10 by jkrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
void			write_shape(t_shape **ptr, char *s, char ltr, int gsize)
{
	t_shape *shape = parse_shape(s, ltr, gsize);
	(*(ptr))->next = shape;
	*ptr = (*(ptr))->next;
}*/

/*
int				main()
{
	t_shape *start_shape;
	t_shape *last_shape;


	int expected_gsize = 7;
	start_shape = parse_shape("##..\n.#..\n.#..\n....\n\n", 'A', expected_gsize);
	last_shape = start_shape;
	write_shape(&last_shape, "####\n....\n....\n....\n", 'B', expected_gsize);
	write_shape(&last_shape, ".#..\n##..\n#...\n....\n", 'C', expected_gsize);
	write_shape(&last_shape, "##..\n.##.\n....\n....\n", 'D', expected_gsize);
	write_shape(&last_shape, "##..\n##..\n....\n....\n", 'E', expected_gsize);
	write_shape(&last_shape, "###.\n..#.\n....\n....\n", 'F', expected_gsize);
	write_shape(&last_shape, ".#..\n##..\n.#..\n....\n", 'G', expected_gsize);
	write_shape(&last_shape, "#...\n###.\n....\n....\n", 'H', expected_gsize);
	write_shape(&last_shape, "##..\n.##.\n....\n....\n", 'I', expected_gsize);
	write_shape(&last_shape, "##..\n##..\n....\n....\n", 'J', expected_gsize);
	write_shape(&last_shape, ".##.\n##..\n....\n....\n", 'K', expected_gsize);
	write_shape(&last_shape, ".#..\n##..\n.#..\n....\n", 'L', expected_gsize);
	t_grid *grid = grid_new(expected_gsize, expected_gsize);
	solve_grid(grid, start_shape);
	printf("SOLUTION:\n%s\n", grid->buffer);
	return (0);
}
*/
/*
int				main()
{
	t_shape *start_shape;
	t_shape *last_shape;

	int expected_gsize = 9;
	start_shape = parse_shape("##..\n##..\n....\n....\n", 'A', expected_gsize);
	last_shape = start_shape;
	write_shape(&last_shape, "##..\n##..\n....\n....\n", 'B', expected_gsize);
	write_shape(&last_shape, "##..\n##..\n....\n....\n", 'C', expected_gsize);
	write_shape(&last_shape, "##..\n##..\n....\n....\n", 'D', expected_gsize);
	write_shape(&last_shape, "##..\n##..\n....\n....\n", 'E', expected_gsize);
	write_shape(&last_shape, "##..\n##..\n....\n....\n", 'F', expected_gsize);
	write_shape(&last_shape, "##..\n##..\n....\n....\n", 'G', expected_gsize);
	write_shape(&last_shape, "##..\n##..\n....\n....\n", 'H', expected_gsize);
	write_shape(&last_shape, "##..\n##..\n....\n....\n", 'I', expected_gsize);
	write_shape(&last_shape, "##..\n##..\n....\n....\n", 'J', expected_gsize);
	write_shape(&last_shape, "##..\n##..\n....\n....\n", 'K', expected_gsize);
	write_shape(&last_shape, "##..\n##..\n....\n....\n", 'L', expected_gsize);
	write_shape(&last_shape, "##..\n##..\n....\n....\n", 'M', expected_gsize);
	write_shape(&last_shape, "##..\n##..\n....\n....\n", 'N', expected_gsize);
	write_shape(&last_shape, "##..\n##..\n....\n....\n", 'O', expected_gsize);
	write_shape(&last_shape, "##..\n##..\n....\n....\n", 'P', expected_gsize);
//	write_shape(&last_shape, "##..\n##..\n....\n....\n", 'Q', expected_gsize);
//	write_shape(&last_shape, "##..\n##..\n....\n....\n", 'R', expected_gsize);
//	write_shape(&last_shape, "##..\n##..\n....\n....\n", 'S', expected_gsize);
	t_grid *grid = grid_new(expected_gsize, expected_gsize);
	solve_grid(grid, start_shape);
	printf("SOLUTION:\n%s\n", grid->buffer);
	return (0);
}*/

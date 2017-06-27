/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrause <jkrause@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 15:38:03 by jkrause           #+#    #+#             */
/*   Updated: 2017/06/26 21:14:37 by jkrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				main(int argc, char **argv)
{
	(void)argv;
	(void)argc;
	t_grid *grid = grid_new(5, 5);
	grid->grid[1][1] = 'm';
	grid->grid[2][2] = 'l';
	grid->grid[3][3] = 'u';

	printf("BUFFER:\n%s", grid->buffer);
}

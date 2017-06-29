/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrause <jkrause@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 15:25:47 by jkrause           #+#    #+#             */
/*   Updated: 2017/06/28 17:39:57 by jkrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

/*
** Shape.h
*/
typedef struct 			s_shape
{
	struct s_shape		*next;
	int					*offsets;
	char				letter;
} 						t_shape;

/*
** Grid.h
*/

# define GETPOS(x, y) (x * (grid->columns + 1)) + y
//# define NEXTLINE(val) (val < 0 ? (y

typedef struct 			s_grid
{
	char				*buffer;
	char				**grid;
	int					rows;
	int					columns;
} 						t_grid;

t_grid					*grid_new(int x, int y);
void					grid_init(t_grid *grid);
int						solve_grid(t_grid *grid, t_shape *shape);
t_shape					*new_shape(char ltr);
t_shape					*parse_shape(char *arr, char ltr, int expected_gridsize);
#endif

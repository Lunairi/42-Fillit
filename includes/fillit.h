/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrause <jkrause@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 15:25:47 by jkrause           #+#    #+#             */
/*   Updated: 2017/06/26 21:14:38 by jkrause          ###   ########.fr       */
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

/*
** Cardinal directions
*/
# define SQ_UP -2
# define SQ_HERE 0
# define SQ_DOWN 2
# define SQ_RIGHT 1
# define SQ_LEFT -1

# define SQ_REV_UP 2
# define SQ_REV_DOWN -2
# define SQ_REV_HERE 0
# define SQ_REV_LEFT 1
# define SQ_REV_RIGHT -1

# define SHAPE_J 0
# define SHAPE_L 1
# define SHAPE_T 2
# define SHAPE_S 3
# define SHAPE_Z 4
# define SHAPE_I 5
# define SHAPE_O 6

# define SHAPE_RED 0
# define SHAPE_YELLOW 1
# define SHAPE_GREN 2
# define SHAPE_CYAN 3
# define SHAPE_BLUE 4
# define SHAPE_PINK 5

# define ROTATE_0 0
# define ROTATE_90 1
# define ROTATE_180 2
# define ROTATE_270 3

typedef struct 			s_shape
{
	struct s_shape		*next;
	short				*shape; // if (shape == SHAPE_L)
	short				*rotation; // if (rotation == ROT_270)
} 						t_shape;

/*
** Grid.h
*/

typedef struct 			s_grid
{
	char				*buffer;
	char				**grid;
	int					rows;
	int					columns;
} 						t_grid;

t_grid					*grid_new(int x, int y);
void					grid_init(t_grid *grid);
#endif

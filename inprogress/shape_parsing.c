/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 09:48:41 by mlu               #+#    #+#             */
/*   Updated: 2017/06/29 15:57:47 by jkrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utility.h"
#define BUF_SIZE 21

int			ft_sqrt(int nb)
{
	int i;

	i = 0;
	while ((i * i) <= nb)
		i++;
	return (i);
}

void			write_shape(t_shape **ptr, char *s, int gsize)
{
	t_shape *shape;
	if (*ptr != 0)
	{
		shape = parse_shape(s, (*(ptr))->letter + 1, gsize);
		(*(ptr))->next = shape;
		*ptr = (*(ptr))->next;
	}
	else
	{
		shape = parse_shape(s, 'A', gsize);
		*ptr = shape;
	}
}

void ft_parseshapes(char *str, int gridsize, t_shape **last_shape)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write_shape(last_shape, str + i, gridsize);
		i += 21;
	}
}

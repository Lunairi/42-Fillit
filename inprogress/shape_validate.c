/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 09:48:41 by mlu               #+#    #+#             */
/*   Updated: 2017/06/29 15:28:58 by jkrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utility.h"

int g_size;
int g_square;
int g_track;

int	ft_sqrt(int nb)
{
	int i;

	i = 0;
	while ((i * i) <= nb)
		i++;
	return (i);
}

int	ft_checkvalue(char *str, int track, int i, int size)
{
	if (track == 5 && str[i] != '\n')
		return (0);
	else if (track != 5 && !(str[i] == '#'
		|| str[i] == '.') && (i != (size + 20)))
		return (0);
	return (1);
}

int	ft_isvalid(char *str, int i, int count)
{
	while (++i < (g_size + 21) && str[i] != '\0')
	{
		g_track++;
		if (!(ft_checkvalue(str, g_track, i, g_size)))
			return (0);
		if (str[i] == '#')
			count++;
		if (g_track == 5)
			g_track = 0;
	}
	if (count != 4)
		return (0);
	if (str[i] != '\0')
	{
		g_size = g_size + 21;
		g_track = 0;
		return (ft_isvalid(str, (g_size - 1), 0));
	}
	if (str[i] == '\0')
	{
		g_square = ft_sqrt(((g_size / 21) + 1) * 4);
		return (ft_scan(str));
	}
	return (0);
}

int	ft_validate(char *str)
{
	int shape;

	shape = 0;
	g_size = 0;
	g_track = 0;
	shape = ft_isvalid(str, -1, 0);
	ft_putnbr(shape);
	if (shape != 0)
		return (g_square);
	return (0);
}

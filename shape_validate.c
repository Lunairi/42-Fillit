/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_validate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 17:49:30 by mlu               #+#    #+#             */
/*   Updated: 2017/07/03 17:51:17 by jkrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utility.h"

int g_size;
int g_square;

int	ft_sqrt(int nb, char *str)
{
	int i;

	i = 0;
	if (nb == 4)
	{
		while (str[i] != '#')
			i++;
		if (str[i + 5] == '#' && str[i + 10] == '#'
			&& str[i + 15] == '#')
			return (4);
		else if (str[i + 1] == '#' && str[i + 2] == '#'
			&& str[i + 3] == '#')
			return (4);
		else
			i = 0;
	}
	while ((i * i) < nb)
		i++;
	return (i);
}

int	ft_checkvalue(char *str, int track, int i, int size)
{
	if (track == 5 && str[i] != '\n' && str[21] != '\0')
		return (0);
	else if (track != 5 && !(str[i] == '#'
		|| str[i] == '.') && (i != (size + 20)))
	{
		return (0);
	}
	return (1);
}

int	ft_isvalid(char *str, int i, int count, int track)
{
	while (++i < (g_size + 20) && str[i] != '\0')
	{
		track++;
		if (!(ft_checkvalue(str, track, i, g_size)))
			return (0);
		if (str[i] == '#')
			count++;
		if (track == 5)
			track = 0;
	}
	if (count != 4)
		return (0);
	if (str[i] != '\0' && str[21] != '\0')
	{
		g_size = g_size + 21;
		track = 0;
		return (ft_isvalid(str, (g_size - 1), 0, track));
	}
	if (str[i] == '\0' || str[21] == '\0')
	{
		g_square = ft_sqrt((((g_size / 21) + 1) * 4), str);
		return (ft_scan(str, ((g_size / 21) + 1), -1));
	}
	return (0);
}

int	ft_validate(char *str)
{
	g_size = 0;
	if (ft_isvalid(str, -1, 0, 0))
		return (g_square);
	return (0);
}

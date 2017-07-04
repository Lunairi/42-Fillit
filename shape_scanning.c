/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 09:48:41 by mlu               #+#    #+#             */
/*   Updated: 2017/07/03 17:26:51 by jkrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utility.h"

int	ft_scan_ws(char *str, int i, int count)
{
	if (count == 3)
		return (1);
	if (str[i - 1] == '#')
		return (ft_scan_ws(str, i - 1, count + 1));
	else if (str[i + 5] == '#')
		return (ft_scan_wes(str, i + 5, count + 1));
	return (0);
}

int	ft_scan_wes(char *str, int i, int count)
{
	if (count == 3)
		return (1);
	if (str[i + 1] == '#')
		return (ft_scan_es(str, i + 1, count + 1));
	else if (str[i + 5] == '#')
		return (ft_scan_wes(str, i + 5, count + 1));
	else if (str[i - 1] == '#')
		return (ft_scan_ws(str, i - 1, count + 1));
	else if (str[i - 6] == '#')
		return (ft_scan_ws(str, i - 6, count + 1));
	return (0);
}

int	ft_scan_es(char *str, int i, int count)
{
	if (count == 3)
		return (1);
	if (str[i + 1] == '#')
		return (ft_scan_es(str, i + 1, count + 1));
	else if (str[i + 5] == '#')
		return (ft_scan_wes(str, i + 5, count + 1));
	else if (str[i + 4] == '#')
		return (ft_scan_wes(str, i + 4, count + 1));
	else if (str[i + 3] == '#' && str[i - 2] == '#')
		return (ft_scan_wes(str, i + 3, count + 1));
	return (0);
}

int	ft_scan_start(char *str, int i, int count)
{
	if (str[i + 1] == '#')
	{
		if (!ft_scan_es(str, i + 1, count + 1))
			return (0);
		return (1);
	}
	else if (str[i + 3] == '#' && str[i + 4] == '#' && str[i + 5] == '#')
	{
		if (!ft_scan_es(str, i + 3, count + 1))
			return (0);
		return (1);
	}
	else if (str[i + 4] == '#' && str[i + 5] == '#')
	{
		if (!ft_scan_es(str, i + 4, count + 1))
			return (0);
		return (1);
	}
	else if (str[i + 5] == '#')
	{
		if (!ft_scan_wes(str, i + 5, count + 1))
			return (0);
		return (1);
	}
	return (0);
}

int	ft_scan(char *str, int shape, int track)
{
	int i;
	int count;

	i = 0;
	if (shape > 26)
		return (0);
	while (++track < shape)
	{
		i = (track * 21);
		count = 0;
		while (str[i] != '#')
			i++;
		if (!ft_scan_start(str, i, count))
			return (0);
	}
	return (1);
}

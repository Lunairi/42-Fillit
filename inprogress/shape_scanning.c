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

int	ft_scan_ws(char *str, int i, int count)
{
	if (count == 4)
		return (1);
	if (str[i - 1] == '#')
	{
		count++;
		i--;
		return (ft_scan_ws(str, i, count));
	}
	else if (str[i + 5] == '#')
	{
		count++;
		i = i + 5;
		return (ft_scan_wes(str, i, count));
	}
	return (0);
}

int	ft_scan_wes(char *str, int i, int count)
{
	if (count == 4)
		return (1);
	if (str[i + 1] == '#')
	{
		count++;
		i++;
		return (ft_scan_es(str, i, count));
	}
	else if (str[i + 5] == '#')
	{
		count++;
		i = i + 5;
		return (ft_scan_wes(str, i, count));
	}
	else if (str[i - 1] == '#')
	{
		count++;
		i--;
		return (ft_scan_ws(str, i, count));
	}
	return (0);
}

int	ft_scan_es(char *str, int i, int count)
{
	if (count == 4)
		return (1);
	if (str[i + 1] == '#')
	{
		count++;
		i++;
		return (ft_scan_es(str, i, count));
	}
	else if (str[i + 5] == '#')
	{
		count++;
		i = i + 5;
		return (ft_scan_wes(str, i, count));
	}
	else if (str[i + 4] == '#')
	{
		count++;
		i = i + 4;
		return (ft_scan_wes(str, i, count));
	}
	else if (str[i + 3] == '#' && str[i - 2] == '#')
	{
		count++;
		i = i + 3;
		return (ft_scan_wes(str, i, count));
	}
	return (0);
}

int	ft_scan(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i] != '#')
		i++;
	count++;
	if (str[i + 1] == '#')
	{
		count++;
		i++;
		if (ft_scan_es(str, i, count))
			return (1);
	}
	else if (str[i + 5] == '#')
	{
		count++;
		i = i + 5;
		if (ft_scan_wes(str, i, count))
			return (1);
	}
	return (0);
}
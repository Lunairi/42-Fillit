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

/*     1      2      3      4      5      6      7      8      9     10   */
/*   ####   ###.   ###.   ###.   ##..   ##..   ##..   ##..   #...   #...  */
/*   ....   #...   .#..   ..#.   ##..   #...   .##.   .#..   ###.   ##..  */
/*   ....   ....   ....   ....   ....   #...   ....   .#..   ....   .#..  */
/*   ....   ....   ....   ....   ....   ....   ....   ....   ....   ....  */

/*    11     12     13     14     15     16     17     18     19   */
/*   #...   #...   #...   .##.   .#..   .#..   .#..   .#..   ..#.  */
/*   ##..   #...   #...   ##..   ###.   ##..   ##..   .#..   ###.  */
/*   #...   ##..   #...   ....   ....   #...   .#..   ##..   ....  */
/*   ....   ....   #...   ....   ....   ....   ....   ....   ....  */


#include "lydeka.h"
int g_size;
int g_square;
int g_track;

int			ft_sqrt(int nb)
{
	int i;

	i = 0;
	while ((i * i) <= nb)
		i++;
	return (i);
}


void	ft_putnbr(int n)
{
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n + '0');
}


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
	printf("Hit end of function_ws\n");
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
	printf("Hit end of function_wes\n");
	return (0);
}

int	ft_scan_es(char *str, int i, int count)
{
		ft_putstr("Check count\n");
	ft_putnbr(count);
	ft_putchar('\n');
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
	printf("Hit end of function_orig\n");
	return (0);
}

int	ft_isvalid(char *str)
{
	int i;
	int count;

	i = g_size - 1;
	count = 0;
	ft_putstr("Initializing validation method.\n");
	while (++i < (g_size + 21) && str[i] != '\0')
	{
		g_track++;
		if (g_track == 5 && str[i] != '\n')
		{
			ft_putstr("Error: Inappropriate new lines.\n");
			ft_putchar(str[i]);
			ft_putchar('\n');
			ft_putnbr(i);
			ft_putchar('\n');
			return (0);
		}
		else if (g_track != 5 && !(str[i] == '#' || str[i] == '.') && (i != (g_size + 20)))
		{
			ft_putstr("Error: Inappropriate symbols.\n");
			ft_putchar(str[i]);
			ft_putchar('\n');
			ft_putnbr(i);
			ft_putchar('\n');
			return (0);
		}
		if (str[i] == '#')
			count++;
		if (g_track == 5)
			g_track = 0;
	}
	if (count != 4)
	{
		printf("Not enough: %d\n", count);
		return (0);
	}
	if (str[i] != '\0')
	{
		g_size = g_size + 21;
		g_track = 0;
		return (ft_isvalid(str));
	}
	if (str[i] == '\0')
	{
		g_square = ft_sqrt(((g_size / 21) + 1) * 4);
		ft_putstr("Number of pieces: ");
		ft_putnbr((g_size / 21) + 1);
		ft_putchar('\n');
		ft_putstr("Grid Size: ");
		ft_putnbr(g_square);
		ft_putchar('x');
		ft_putnbr(g_square);
		ft_putchar('\n');
		return (ft_scan(str));
	}
	return (0);
}

int ft_validate(char *str)
{
	int shape;

	shape = 0;
	g_size = 0;
	g_track = 0;
	ft_putstr("Checking validation.\n");
	shape = ft_isvalid(str);
	ft_putnbr(shape);
	if (shape != 0)
		return (g_square);
	return (0);
}

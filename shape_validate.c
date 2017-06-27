/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 09:48:41 by mlu               #+#    #+#             */
/*   Updated: 2017/04/24 09:48:42 by mlu              ###   ########.fr       */
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

int g_size;
int g_square;

int	ft_scan_ws(char *str, int i, int count)
{
	if (count == 4)
		return (1);
	if (str[i + 1] == '#')
	{
		count++;
		i++;
		return (ft_scan_ws(*str, i, count));
	}
	else if (str[i + 5] == '#')
	{
		count++;
		i = i + 5;
		return (ft_scan_wes(*str, i, count));
	}
	else
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
		return (ft_scan_es(*str, i, count));
	}
	else if (str[i + 5] == '#')
	{
		count++;
		i = i + 5;
		return (ft_scan_wes(*str, i, count));
	}
	else if (str[i - 1] == '#')
	{
		count++;
		i = i + 5;
		return (ft_scan_ws(*str, i, count));
	}
	else
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
		return (ft_scan_es(*str, i, count));
	}
	else if (str[i + 5] == '#')
	{
		count++;
		i = i + 5;
		return (ft_scan_wes(*str, i, count));
	}
	else
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
		return (ft_scan_es(*str, i, count));
	}
	else if (str[i + 5] == '#')
	{
		count++;
		i = i + 5;
		return (ft_scan_wes(*str, i, count));
	}
	else
		return (0);
}

int	ft_isvalid(char *str)
{
	int i;
	int count;

	i = g_size - 1;
	count = 0;
	while (++i < (g_size + 21) && str[i] != '\0')
	{
		if (((i + 1) % 5 == 0) && str[i] != '\n')
			return (0);
		else if (((i + 1) % 5 != 0) && (str[i] != '#' || str[i] != '.'))
			return (0);
		if (str[i] == '#')
			count++;
	}
	if (count != 4)
		return (0);
	if (str[i] != '\0')
	{
		g_size = g_size + 21;
		return (ft_isvalid(*str));
	}
	else if (str[i] == '\0')
	{
		g_square = (g_size / 21);
		return (ft_scan(*str));
	}
}

int ft_validate(char *str)
{
	int shape;

	shape = 0;
	g_size = 0;
	shape = ft_isvalid(*str);
	if (shape != 0)
	{
		g_size++;
		return (shape);
	}
	return (0);
}
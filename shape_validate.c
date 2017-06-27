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

int g_ct;
int g_size;

int	ft_vShape2(char *str, int fill)
{
	if (fill == 3 && str[g_ct] == '#' && str[g_ct - 5] == '#')
		return (2);
	else if (fill == 3 && str[g_ct] == '#' && str[g_ct - 4] == '#')
		return (3);
	else if (fill == 3 && str[g_ct] == '#' && str[g_ct - 3] == '#')
		return (4);
	else if (fill == 2 && str[g_ct] == '#' && str[g_ct + 1] == '#')
		return (5);
	else if (fill == 2 && str[g_ct] == '#' && str[g_ct - 5] == '#' && str[g_ct +5] == '#')
		return (6);
	else if (fill == 2 && str[g_ct + 1] == '#' && str[g_ct - 5] == '#' && str[g_ct + 5] == '#')
		return (8);
	else if (fill == 2 && str[g_ct + 1] == '#' && str[g_ct + 2] == '#'
		&& str[g_ct - 5] == '#' && str[g_ct - 4] == '#')
		return (7);
	else if (fill == 2 && str[g_ct] == '#' && str[g_ct + 1] == '#'
		&& str[g_ct - 4] == '#' && str[g_ct - 3] == '#')
		return (14);
	else if (fill == 1)
		return (ft_vShape3(*str, fill));
	else if(str[g_ct] == '\n')
		return (0);
	else
	{
		g_ct++;
		return (ft_vShape2(*str, fill));
	}
}

int	ft_vShape1(char *str)
{
	int fill;

	fill = 0;
	g_ct++;

	while (str[g_ct] != '\0')
	{
		if (str[g_ct++] == '#')
			fill++;
		else if (str[g_ct] == '\n')
		{
			if (fill == 4)
				return (1);
			else if (fill != 0 && ft_isValid)
				return (ft_vsShape2(*str, fill));
			else if (!ft_isValid && fill != 0)
				return (0);
			else
				return (ft_vShape1(*str));
		}
		else
			g_ct++;
	}
	return (0);
}

int	ft_isValid(char *str, int fill)
{
	g_ct++;

	if (fill == 3 && str[g_ct - 5] == '#' && str[g_ct - 4] == '#' && str[g_ct - 3] == '#' 
		|| fill == 3 && str[g_ct - 4] == '#' && str[g_ct - 3] == '#' && str[g_ct - 2] == '#')
		return (1);
	else if (fill == 3)
		return (0);
	else if (fill == 2 && str[g_ct - 5] == '#' && str[g_ct - 4] == '#'
		|| fill == 2 && str[g_ct - 4] == '#' && str[g_ct - 3] == '#'
		|| fill == 2 && str[g_ct - 3] == '#' && str[g_ct - 2] == '#')
		return (1);
	else if (fill == 2)
		return (0);
	else
		return (1);
}

int ft_vShape(char *str)
{
	int shape;

	g_ct = -1;
	shape = 0;

	shape = ft_vshape_row1(*str);
	if (shape != 0)
	{
		g_size++;
		return (shape);
	}
	return (0);
}
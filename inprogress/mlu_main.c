/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 09:48:41 by mlu               #+#    #+#             */
/*   Updated: 2017/06/29 15:51:34 by jkrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "lydeka.h"
#define BUF_SIZE 21

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putstr(char *str)
{
	while (*str != '\0')
	{
		ft_putchar(*str);
		str++;
	}
}

char	*ft_strcpy(char *dest, const char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	ft_strcat(char *s1, char *s2, unsigned int *size, unsigned int buf)
{
	unsigned int l;
	unsigned int i;

	i = 0;
	if (((*size) > buf) && ((*size) % buf == 0))
		if (s1[*size - buf])
			i = *size - buf;
	l = 0;
	while (s1[i])
		i++;
	while (s2[l] && (l < buf))
	{
		s1[i] = s2[l];
		i++;
		l++;
	}
	while (l-- > 0)
		s2[l] = '\0';
	s1[i] = '\0';
}

char	*read_input(int fd)
{
	char			*temp;
	char			*output;
	char			input[BUF_SIZE + 1];
	unsigned int	memory;

	memory = 0;
	temp = (char*)malloc(sizeof(*output) * (memory + 1));
	output = (char*)malloc(sizeof(*output) * (memory + 1));
	while ((read(fd, input, BUF_SIZE)) > 0)
	{
		memory += BUF_SIZE;
		ft_strcpy(temp, output);
		free(output);
		output = (char*)malloc(sizeof(*output) * (memory + 1));
		ft_strcpy(output, temp);
		ft_strcat(output, input, &memory, BUF_SIZE);
		output[memory] = '\0';
		free(temp);
		temp = (char*)malloc(sizeof(*temp) * (memory + 1));
	}
	free(temp);
	ft_putstr("Displaying input, this has already been malloced and added into a single string array.");
	ft_putchar('\n');
	ft_putstr(output);
	return (output);
}

int		main(int ac, char **av)
{
	char	*list;
	int		fd;
	int		mluisreallypicky;
	t_shape	*start_shape;
	t_shape *last_shape;

	if (ac != 2)
	{
		ft_putstr("error\n");
		return (0);
	}
	else
	{
		fd = open(av[1], O_RDONLY);
		list = read_input(fd);
		ft_putstr("String created\n"); /*******/
		mluisreallypicky = ft_validate(list);
		start_shape = new_shape('@');
		last_shape = start_shape;
		if (mluisreallypicky > 0)
		{
			ft_parseshapes(list, mluisreallypicky, &last_shape);
			t_grid *gridpls = grid_new(mluisreallypicky, mluisreallypicky);
			solve_grid(gridpls, start_shape->next);
			ft_putstr("Victim of mlu's pms.");
			printf("\nSOLUTION:\n%s\n", gridpls->buffer);
		}
		else
			ft_putstr("fail?\n");
	}
	return (0);
}

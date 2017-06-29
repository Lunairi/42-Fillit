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

#include "lydeka.h"
#define BUF_SIZE 21

void	ft_bzero(void *s, size_t n)
{
	char	*arg;
	size_t	i;

	if (!n)
		return ;
	arg = s;
	i = 0;
	while (i < n)
		*(arg + i++) = 0;
}

void	*ft_memalloc(size_t size)
{
	void	*mem;

	mem = malloc(size);
	if (!mem)
		return (NULL);
	ft_bzero(mem, size);
	return (mem);
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
	/*
	int 	i;
	int 	count;
	char	*output;

	output = ft_memalloc(BUF_SIZE + 1);
	i = 0;
	count = 0;
	ft_putstr("Initializing parsing.\n");
	while (++i < 20)
	{
		output[count] = str[i];
		count++;
	}
	ft_putstr("Shape parsing complete.\n");
	ft_putstr(output);
	ft_putstr("End of shape parse.\n");
	ft_putchar('\n');
	// Parse str here. - output, gridsize, ltrmagic
	write_shape(last_shape, output, gridsize);	//mluoptimizerv3000(output, gridsize, 'A');
	free(output);
	if (str[i] != '\0')
	{
		ft_parseshapes(str + 21, gridsize, last_shape);
	}
	ft_putstr("Completed all shape parsing.\n");*/
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write_shape(last_shape, str + i, gridsize);
		i += 21;
	}
}

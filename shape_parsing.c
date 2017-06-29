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

#include "lydeka.h"
#define BUF_SIZE 21

int g_parse;

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

int	ft_parseshapes(char *str, int parse)
{
	int i;
	int count;
	char	input[BUF_SIZE + 1];
	char	*output;

	output = ft_memalloc(BUF_SIZE + 1);
	g_parse = parse;
	i = g_parse - 1;
	count = 0;
	ft_putstr("Initializing parsing.\n");
	while (++i < (g_parse + 20))
	{
		output[count] = str[i];
		count++;
	}
	ft_putstr("Shape parsing complete.\n");
	ft_putstr(output);
	ft_putstr("End of shape parse.\n");
	ft_putchar('\n');
	free(output);
	if (str[i] != '\0')
	{
		g_parse = g_parse + 21;
		ft_parseshapes(str, g_parse);
	}
	ft_putstr("Completed all shape parsing.\n");
	return (0);
}
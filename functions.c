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

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
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

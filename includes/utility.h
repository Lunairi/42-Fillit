/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lydeka.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschaffe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 14:26:59 by mlu               #+#    #+#             */
/*   Updated: 2017/06/29 15:38:15 by jkrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITY_H
# define UTILITY_H
# include "fillit.h"
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/stat.h>

int	ft_isvalid(char *str, int i, int count);
int	ft_scan_wes(char *str, int i, int count);
int	ft_scan_es(char *str, int i, int count);
void ft_parseshapes(char *str, int gridsize, t_shape **last_shape);
int	ft_sqrt(int nb);

#endif

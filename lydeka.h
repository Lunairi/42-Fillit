/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lydeka.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschaffe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 14:26:59 by mlu               #+#    #+#             */
/*   Updated: 2017/04/25 14:27:00 by mlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LYDEKA_H
# define LYDEKA_H
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/stat.h>

int	ft_validate(char *str);
int	ft_scan_wes(char *str, int i, int count);
int	ft_scan_es(char *str, int i, int count);
void	ft_putstr(char *str);
void	ft_putchar(char c);

#endif

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
	return (output);
}

int		main(int ac, char **av)
{
	char	*list;

	if (ac != 2)
	{
		ft_putstr_err("error\n");
		return (0);
	}
	else
	{
		list = read_input(0);
		// validation here
	}
	return (0);
}

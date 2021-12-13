/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_map_parsing_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 15:13:11 by mafortin          #+#    #+#             */
/*   Updated: 2021/12/10 15:15:12 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"
#include <fcntl.h>

int	cb_nbline_file(char *file)
{
	int	fd;
	int	nb_line;

	fd = open(file, O_RDONLY);
	if (fd <= 0)
	{
		ft_putstr_fd("Error\nMap file\n", 2);
		return (-1);
	}
	nb_line = ft_nbline_file(fd);
	if (nb_line == -1)
		ft_putstr_fd("Error\nMap formating\n", 2);
	return (nb_line);
}

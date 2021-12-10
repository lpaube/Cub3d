/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_map_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 11:37:12 by mafortin          #+#    #+#             */
/*   Updated: 2021/12/10 15:56:46 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../includes/parsing.h"
#include "../libft/libft.h"

//Map file in array of string
char **cb_get_content(int fd, char *file, int nb_line)
{
	char	**line;
	int		ret;
	int		i;

	line = malloc(sizeof(char *) * nb_line + 1);
	fd = open(file, O_RDONLY);
	ret = 1;
	i = 0;
	while (ret > 0)
	{
		ret = get_next_line(fd, line + i);
		if (ret < 0)
		{
			ft_putstr_fd("Error\nMap content corrupted\n", 2);//p-e a changer
			close (fd);
			return (NULL);
		}
		i++;
	}
	close (fd);
	return (line);
}

bool	cb_parsing_main(char *file, t_map *map_info)
{
	int		fd;
	char	**content;
	int		nb_line;

	(void)map_info;
	fd = open(file, O_RDONLY);
	if (fd <= 0)
	{
		ft_putstr_fd("Error\nMap file\n", 2);
		return (false);
	}
	nb_line = ft_nbline_file(fd);
	if (nb_line == -1)
	{
		ft_putstr_fd("Error\nMap formating\n", 2);
		return (false);
	}
	content = cb_get_content(fd, file, nb_line);
	if (!content)
		return (false);
	return (true);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_map_parsing_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 15:13:11 by mafortin          #+#    #+#             */
/*   Updated: 2022/01/10 12:55:14 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"
#include "../libft/libft.h"
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

//Tell if a line contains info about map / pos or color.
//0 for empty line, 1 for map, 2 for pos, 3 for color and 4 for anything else.
int	cb_line_type(char *string)
{
	int		i;

	i = 0;
	while (string[i] == SPACES)
		i++;
	if (!string[i])
		return (0);
	if (string[i] == '1')
		return (1);
	if (string[i] == 'N' || string[i] == 'S' || string[i] == 'W' || string[i] == 'E')
		return (2);
	if (string[i] == 'F' || string[i] == 'C')
		return (3);
	else
	{
		ft_putstr_fd("Error\nMap format error\n", 1);
		return (4);
	}
}

//Trim spaces, skip positions, parse map file and validate.
bool	cb_map_parsing(char **content, t_map *map_info)
{
	int	i;
	int	ret;

	i = 0;
	while (content[i])
	{
		ret = cb_line_type(content[i])
		if (ret == 1)
			break ;
		i++;
	}
	if (ret != 1)
		return (false);
	return (cb_map_parsing_loop(content, map_info));
	
}

bool	cb_valid_map(t_map *map_info, bool start)
{
	
}
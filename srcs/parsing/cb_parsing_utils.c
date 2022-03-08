/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_parsing_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 15:13:11 by mafortin          #+#    #+#             */
/*   Updated: 2022/03/08 16:44:21 by mafortin         ###   ########.fr       */
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
		return (-1);
	nb_line = ft_nbline_file(fd);
	return (nb_line);
}

//Tell if a line contains info about map / pos or color.
//0 for empty line, 1 for map, 2 for pos, 3 for color and 4 for anything else.
int	cb_line_type(char *string)
{
	int		i;

	i = 0;
	while (string[i] == ' ')
		i++;
	if (!string[i])
		return (0);
	if (string[i] == '1' || string[i] == '0')
		return (1);
	if (string[i] == 'N' || string[i] == 'S' || string[i] == 'W'
		|| string[i] == 'E')
		return (2);
	if (string[i] == 'F' || string[i] == 'C')
		return (3);
	else
		return (4);
}

bool	cb_valid_tile(char c)
{
	if (c == '\0' || c == '1' || c == 'N' || c == 'S'
		|| c == 'W' || c == 'W' || c == 'E' || c == 'F'
		|| c == 'C' || c == '0' || c == ' ')
		return (true);
	else
		return (false);
}

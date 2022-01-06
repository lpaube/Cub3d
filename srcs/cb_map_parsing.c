/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_map_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 11:37:12 by mafortin          #+#    #+#             */
/*   Updated: 2022/01/06 14:44:14 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../includes/parsing.h"
#include "../libft/libft.h"

//Map file in array of string
char	**cb_get_content(char *file)
{
	char	**line;
	int		ret;
	int		i;
	int		fd;

	i = cb_nbline_file(file);
	if (i <= 0)
		return (NULL);
	line = malloc(sizeof(char *) * i + 1);
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

//Parsing map file with argv[1]
bool	cb_parsing_main(int argc, char **argv, t_map *map_info)
{
	char	**content;

	if (argc != 2)
	{
		free(map_info);
		return (false);
	}
	content = cb_get_content(argv[1]);
	if (!content)
	{
		free(map_info);
		return (false);
	}
	return (true);
}

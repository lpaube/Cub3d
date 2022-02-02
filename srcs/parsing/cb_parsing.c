/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 13:08:44 by mafortin          #+#    #+#             */
/*   Updated: 2022/02/02 17:34:12 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "parsing.h"
#include "../libft/libft.h"


//Map file in array of string
char	**cb_get_content(char *file, int fd, char **line)
{
	int		ret;
	int		i;

	i = cb_nbline_file(file);
	if (i <= 0)
		return (NULL);
	line = ft_calloc(sizeof(char *), i + 1);
	fd = open(file, O_RDONLY);
	ret = 1;
	i = 0;
	while (ret > 0)
	{
		ret = get_next_line(fd, line + i);
		if (ret < 0)
		{
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
		return (false);
	content = cb_get_content(argv[1], 0, NULL);
	if (!content)
		return (false);
	if (cb_valid_content(content) == false || cb_map_parsing(content, map_info) == false ||
		cb_texture_parsing(content, map_info) == false || cb_color_parsing(content, map_info, 'F') == false ||
			cb_color_parsing(content, map_info, 'C') == false)
	{
		ft_free_tab(content);
		return (false);
	}
	ft_free_tab(content);
	return (true);
}
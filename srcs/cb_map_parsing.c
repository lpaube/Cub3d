/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_map_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 11:37:12 by mafortin          #+#    #+#             */
/*   Updated: 2022/01/12 16:04:33 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "../includes/parsing.h"
#include "../libft/libft.h"

//Validate if line countains only characters allowed in a map.
//" 1, 0, S, W, E, N"
//Return -1 if an error is encountered.
int	cb_valid_mapline(char *string, int i, int start, int end)
{
	while (string[i])
	{
		while (string[i] == ' ')
			i++;
		if (string[i] == '\0')
			break ;
		if (string[i] != '1' && string[i] != '0' && string[i] != 'N'
			&& string[i] != 'S' && string[i] != 'W' && string[i] != 'E')
			return (-1);
		start = 1;
		i++;
	}
	if (start == 0 && i < end)
		return (-1);
	return (0);
}

//Loop through content as soon as we find a 1 as first char.
//Validate line by line and add string to the map.
//Return false if an error is encountered.
bool	cb_map_parsing_loop(char **content, t_map *map_info, int i, int depth)
{
	int	index;

	index = 0;
	map_info->map = ft_calloc(sizeof(char *), depth + 1);
	map_info->map_width = cb_mapwidth(content, i, depth);
	while (index < depth)
	{
		if (cb_valid_mapline(content[i], index, 0, 0) == -1)
		{
			if (index == 0)
				ft_free_tab(map_info->map);
			return (false);
		}
		map_info->map[index] = cb_line_dup(content[i + index], map_info->map_width);
		index++;
	}
	return (true);
}

//Trim spaces, skip positions, parse map file and validate.
//Return valse if an error is encountered.
bool	cb_map_parsing(char **content, t_map *map_info)
{
	int	i;
	int	ret;

	i = 0;
	while (content[i])
	{
		ret = cb_line_type(content[i]);
		if (ret == 1)
			break ;
		i++;
	}
	if (ret != 1)
		return (false);
	ret = cb_map_end(content, i, 0, map_info);
	if (ret == -1)
		return (false);
	return (cb_map_parsing_loop(content, map_info, i, ret - i));
}

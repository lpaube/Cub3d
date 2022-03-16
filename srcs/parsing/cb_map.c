/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 11:37:12 by mafortin          #+#    #+#             */
/*   Updated: 2022/03/16 13:56:03 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "../includes/parsing.h"
#include "../libft/libft.h"

bool	cb_playerpos(t_map *map_info, int i, int j, bool done)
{
	while (map_info->map[i])
	{
		j = 0;
		while (map_info->map[i][j])
		{
			if (ft_strchr(DIRECTION, map_info->map[i][j]) != NULL)
			{
				if (done == true)
					return (false);
				done = true;
				map_info->player_y = i;
				map_info->player_x = j;
				map_info->orientation = map_info->map[i][j];
			}
			j++;
		}
		i++;
	}
	return (done);
}

//Loop through content as soon as we find a 1 as first char.
//Validate line by line and add string to the map.
//Return false if an error is encountered.
bool	cb_map_parsing_loop(char **content, t_map *map_info, int i)
{
	int	index;

	index = 0;
	map_info->map = ft_calloc(sizeof(char *), map_info->map_height + 1);
	while (index < map_info->map_height)
	{
		if (cb_valid_mapline(content[index + i], 0, 0) == -1)
			return (ft_false("Error\nMap: Invalid char\n", 1));
		map_info->map[index] = cb_line_dup(content[i + index],
				map_info->map_width);
		index++;
	}
	if (cb_playerpos(map_info, 0, 0, false) == false)
		return (ft_false("Error\nMap: player position invalid\n", 1));
	return (cb_closedmap(map_info, 0, 0));
}

//Check if the map is the last info of the file. Return -1 if its not.
int	cb_map_order(char **content, int start)
{
	int	j;
	int	cpy;

	cpy = start;
	while (content[start])
	{
		j = 0;
		while (content[start][j])
		{
			if (content[start][j] != ' ' && content[start][j] != '\n')
				return (-1);
			j++;
		}
		start++;
	}
	return (cpy);
}

//Return the index representing the end of the map.
//-1 if an error is encountered.
int	cb_map_end(char **content, int start, int j, t_map *map_info)
{
	int	len;

	map_info->map_width = 0;
	while (content[start])
	{
		j = 0;
		len = ft_strlen(content[start]);
		if (len >= map_info->map_width)
			map_info->map_width = len;
		while (content[start][j] == ' ')
			j++;
		if (cb_valid_tile(content[start][j]) == false)
			return (-1);
		if (content[start][j] != '1')
			break ;
		start++;
	}
	return (cb_map_order(content, start));
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
		return (ft_false("Error\nMap: Invalid\n", 1));
	ret = cb_map_end(content, i, 0, map_info);
	map_info->map_height = ret - i;
	if (map_info->map_height < 3)
		return (ft_false("Error\nMap: Invalid\n", 1));
	return (cb_map_parsing_loop(content, map_info, i));
}

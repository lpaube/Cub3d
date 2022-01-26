/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_map_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 11:37:12 by mafortin          #+#    #+#             */
/*   Updated: 2022/01/26 16:27:07 by mafortin         ###   ########.fr       */
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
int	cb_valid_mapline(char *string, int i, int start)
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
	if (start == 0 && string[i] != '\0')
		return (-1);
	return (0);
}

//Loop through the map and by the help of cb_check_wall
//Verify every direction of a position to check if it colides with a wall.
//If not, return false and end the program.
bool	cb_closedmap(t_map *map_info, int i, int j)
{
	while (map_info->map[i])
	{
		j = 0;
		while (map_info->map[i][j])
		{
			if (map_info->map[i][j] != '1' && map_info->map[i][j] != '-')
			{
				if (cb_wall_vert(map_info, i, i, j) == false
					|| cb_wall_hor(map_info, i, j, j) == false)
				{
					ft_free_tab(map_info->map);
					return (false);
				}
			}
			j++;
		}
		i++;
	}
	return (true);
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
		{
			if (index == 0)
				ft_free_tab(map_info->map);
			return (false);
		}
		map_info->map[index] = cb_line_dup(content[i + index], map_info->map_width);
		index++;
	}
	ft_print_matrice(map_info->map);
	if (cb_closedmap(map_info, 0 , 0) == false)//|| cb_playerpos(map_info) == false)
		return (false);
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
	map_info->map_height = ret - i;
	if (map_info->map_height < 3)
		return (false);
	return (cb_map_parsing_loop(content, map_info, i));
}

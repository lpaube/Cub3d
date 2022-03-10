/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 14:10:51 by mafortin          #+#    #+#             */
/*   Updated: 2022/03/08 16:31:04 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "../includes/parsing.h"
#include "../libft/libft.h"

bool	cb_find_texture(char **content, char *ori, char **texture, int x)
{
	int	i;
	int	j;

	i = 0;
	while (content[i])
	{
		j = 0;
		while (content[i][j] == ' ')
			j++;
		if (ft_strncmp(content[i] + j, ori, 2) == 0)
		{
			if (texture[x] == NULL)
				texture[x] = ft_strdup(content[i] + j + 3);
			else
				return (false);
		}
		i++;
	}
	if (texture[x] == NULL)
		return (false);
	return (true);
}

bool	cb_xpmfile_check(char *string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (string[i] == '.')
		{
			if (ft_strncmp(string + i, ".xpm", 4) == 0)
				return (true);
		}
		i++;
	}
	return (false);
}

//check if the file can be opened and if its the right type (.xpm)
bool	cb_check_texture(char **texture)
{
	if (open(texture[0], O_RDONLY) == -1
		|| cb_xpmfile_check(texture[0]) == false)
		return (false);
	if (open(texture[1], O_RDONLY) == -1
		|| cb_xpmfile_check(texture[1]) == false)
		return (false);
	if (open(texture[2], O_RDONLY) == -1
		|| cb_xpmfile_check(texture[2]) == false)
		return (false);
	if (open(texture[3], O_RDONLY) == -1
		|| cb_xpmfile_check(texture[3]) == false)
		return (false);
	return (true);
}

bool	cb_texture_parsing(char **content, t_map *map_info)
{
	map_info->texture = ft_calloc(sizeof(char *), 5);
	(void)content;
	if (cb_find_texture(content, "NO", map_info->texture, 0) == false ||
			cb_find_texture(content, "EA", map_info->texture, 1) == false ||
				cb_find_texture(content, "SO", map_info->texture, 2) == false ||
					cb_find_texture(content, "WE", map_info->texture, 3) == false)
		return (ft_false("Error\nMissing texture\n", 1));
	if (cb_check_texture(map_info->texture) == false)
		return (ft_false("Error\nTexture file error\n", 1));
	return (true);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_texture_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 14:10:51 by mafortin          #+#    #+#             */
/*   Updated: 2022/02/02 16:10:01 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "../includes/parsing.h"
#include "../libft/libft.h"

char	*cb_find_color(char **content, char type)
{
	int		i;
	int		j;
	char	*save;

	i = 0;
	save = NULL;
	while (content[i])
	{
		j = 0;
		while (content[i][j] == ' ')
			j++;
		if (content[i][j] == type)
		{
			while (content[i][j + 1] == ' ')
				j++;
			if (save == NULL)
				save = content[i] + j;
			else
				return (NULL);
		}
		i++;
	}
	return (save);
}

bool	cb_valid_colorline(char *string)
{
	int	i;

	i = 1;
	while (string[i])
	{
		if (ft_isdigit(string[i]) != 1)
			return (false);
		i++;
	}
	return (true);
}

bool	cb_color_parsing(char **content, t_map *map_info, char type)
{
	int		color[3];
	char	*line;
	char	**numbers;
	int		i;

	i = 0;
	line = cb_find_color(content, type);
	if (!line)
		return (false);
	numbers = ft_split(line + 1, ',');
	if (!numbers)
		return (false);
	if (ft_matrice_size(numbers) != 3)
	{
		ft_free_tab(numbers);
		return (false);
	}
	while (numbers[i])
	{
		if (cb_valid_colorline(numbers[i]) == false)
		{
			ft_free_tab(numbers);
			return (false);
		}
		color[i] = ft_atoi(numbers[i]);
		if (color[i] < 0 || color[i] > 255)
		{
			ft_free_tab(numbers);
			return (false);
		}
		i++;
	}
	if (type == 'F')
		map_info->floor = color;
	else
		map_info->ceilling = color;
	return (true);
}

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

bool	cb_texture_parsing(char **content, t_map *map_info)
{
	map_info->texture = ft_calloc(sizeof(char *), 4);
	if (cb_find_texture(content, "NO", map_info->texture, 0) == false)
	{
		//ft_free_tab(map_info->texture;
		return (false);
	}
	if (cb_find_texture(content, "EA", map_info->texture, 1) == false)
	{
		//ft_free_tab(map_info->texture);
		return (false);
	}
	if (cb_find_texture(content, "SO", map_info->texture, 2) == false)
	{
		//ft_free_tab(map_info->texture);
		return (false);
	}
	if (cb_find_texture(content, "WE", map_info->texture, 3) == false)
	{
		//ft_free_tab(map_info->texture);
		return (false);
	}
	return (true);
}


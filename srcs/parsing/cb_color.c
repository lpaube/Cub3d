/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 16:39:21 by mafortin          #+#    #+#             */
/*   Updated: 2022/03/04 17:11:16 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "../includes/parsing.h"
#include "../libft/libft.h"

char	*cb_colorloop(char **content, int i, int j, char *save)
{
	while (content[i][j + 1] == ' ')
				j++;
	if (save == NULL)
		save = content[i] + j;
	else
	{
		printf("Error\nCeilling or floor color duplicate\n");
		return (NULL);
	}
	return (save);
}

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
			save = cb_colorloop(content, i, j, save);
			if (save == NULL)
				return (NULL);
		}
		i++;
	}
	if (save == false)
		printf("Error\nCeilling or floor color not found\n");
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

bool	cb_color_loop(char **numbers, int *color)
{
	int	i;

	i = 0;
	while (numbers[i])
	{
		if (cb_valid_colorline(numbers[i]) == false)
		{
			ft_free_tab(numbers);
			return (ft_false("Error\nInvalid char in colors\n", 1));
		}
		color[i] = ft_atoi(numbers[i]);
		if (color[i] < 0 || color[i] > 255)
		{
			ft_free_tab(numbers);
			return (ft_false("Error\nInvalid ceilling or floor color\n", 1));
		}
		i++;
	}
	return (true);
}

bool	cb_color_parsing(char **content, t_map *map_info, char type)
{
	char	*line;
	char	**numbers;
	int		*color;

	line = cb_find_color(content, type);
	if (!line)
		return (false);
	numbers = ft_split(line + 1, ',');
	if (ft_matrice_size(numbers) != 3)
	{
		ft_free_tab(numbers);
		return (false);
	}
	color = malloc(sizeof(int) * 3);
	if (cb_color_loop(numbers, color) == false)
	{
		ft_free_tab(numbers);
		return (false);
	}
	if (type == 'F')
		map_info->floor = color;
	else
		map_info->ceilling = color;
	ft_free_tab(numbers);
	return (true);
}

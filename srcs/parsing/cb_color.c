#include <fcntl.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "../includes/parsing.h"
#include "../libft/libft.h"

char	*cb_color_trim(char **content, int i, char *save)
{
	if (save == NULL)
		save = ft_trim_string(content[i], ' ');
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
			save = cb_color_trim(content, i, save);
			if (save == NULL)
				return (NULL);
		}
		i++;
	}
	if (save == NULL)
		printf("Error\nCeilling or floor color not found\n");
	return (save);
}

bool	cb_valid_colorline(char *string)
{
	int	i;

	i = 0;
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
			return (false);
		color[i] = ft_atoi(numbers[i]);
		if (color[i] < 0 || color[i] > 255)
			return (false);
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
	free(line);
	if (ft_matrice_size(numbers) != 3)
		return (free_color(numbers));
	color = malloc(sizeof(int) * 3);
	if (cb_color_loop(numbers, color) == false)
	{
		free(color);
		return (free_color(numbers));
	}
	if (type == 'F')
		map_info->floor = color;
	else
		map_info->ceilling = color;
	ft_free_tab(numbers);
	return (true);
}

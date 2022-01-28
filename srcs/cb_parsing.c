//HEADER

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
			texture[x] = ft_strdup(content[i] + j + 3);
			return (true);
		}
		i++;
	}
	return (false);
}

bool	cb_texture_parsing(char **content, t_map *map_info)
{
	map_info->texture = malloc(sizeof(char *) * 4);
	if (cb_find_texture(content, "NO", map_info->texture, 0) == false)
	{
		//ft_free_tab(map_info->texture);
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
	if (cb_map_parsing(content, map_info) == false)
	{
		ft_free_tab(content);
		return (false);
	}
	if (cb_texture_parsing(content, map_info) == false)
	{
		ft_free_tab(content);
		return (false);
	}
	printf("North : %s\nEast : %s\nSouth : %s\nWest : %s\n", map_info->texture[0], map_info->texture[1], map_info->texture[2], map_info->texture[3]);
	ft_free_tab(content);
	return (true);
}
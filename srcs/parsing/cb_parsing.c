#include <fcntl.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "parsing.h"
#include "cub3d.h"
#include "../libft/libft.h"

//check if the file has .cub type
bool	cb_cubfile(char *file)
{
	int	i;

	i = 0;
	while (file[i])
	{
		if (file[i] == '.')
		{
			if (ft_strncmp(file + i, ".cub", 5) == 0)
				return (true);
			else
				return (false);
		}
		i++;
	}
	return (false);
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
bool	cb_parsing_main(char **argv, t_map *map_info)
{
	char	**content;

	content = cb_get_content(argv[1], 0, NULL);
	if (!content)
	{
		free(map_info);
		return (ft_false("Error\nWhile reading map file\n", 1));
	}
	if (cb_valid_content(content) == false
		|| cb_map_parsing(content, map_info) == false
		|| cb_texture_parsing(content, map_info) == false
		|| cb_color_parsing(content, map_info, 'F') == false
		|| cb_color_parsing(content, map_info, 'C') == false)
	{
		ft_free_tab(content);
		free_map(map_info);
		return (false);
	}
	ft_free_tab(content);
	return (true);
}

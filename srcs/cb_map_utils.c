//HEADER

#include <fcntl.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "../includes/parsing.h"
#include "../libft/libft.h"

//Copy map line and add spaces to fill the map up to the len 
//of the longest string.
char	*cb_line_dup(const char *s1, size_t len)
{
	char	*cpy;
	size_t	i;

	i = 0;
	cpy = ft_fill(len, '-');
	if (!cpy)
		return (0);
	while (s1[i])
	{
		while(s1[i] == ' ')
			i++;
		if (s1[i] == '\0')
			break ;
		cpy[i] = s1[i];
		i++; 
	}
	return (cpy);
}

bool	cb_wall_hor(t_map *map_info, int i, int j2, int j)
{
	bool	ret;

	ret = false;
	while (j2 >= 0)
	{
		if (map_info->map[i][j2] == '1')
		{
			ret = true;
			break ;
		}
		if (map_info->map[i][j2] == '-')
			return (false);
		if (j2 == 0)
			break ;
		j2--;
	}
	if (ret == false)
		return (false);
	while (j < map_info->map_width)
	{
		if (map_info->map[i][j] == '1')
			return (true);
		if (map_info->map[i][j] == '-')
			return (false);
		j++;
	}
	return (false);
}

bool	cb_wall_vert(t_map *map_info, int i, int i2, int j)
{
	bool	ret;

	ret = false;
	while (i2 >= 0)
	{
		if (map_info->map[i2][j] == '1')
		{
			ret = true;
			break ;
		}
		if (map_info->map[i2][j] == '-')
			return (false);
		if (i2 == 0)
			break ;
		i2--;
	}
	if (ret == false)
		return (false);
	while (i < map_info->map_height)
	{
		if (map_info->map[i][j] == '1')
			return (true);
		if (map_info->map[i][j] == '-')
			return (false);
		i++;
	}
	return (false);
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
	return (start);
}

//Return the len of the longest string in the map.
int	cb_mapwidth(char **content, int i, int depth)
{
	int	len_save;
	int	len;

	len_save = 0;
	while (i <= depth)
	{
		len = ft_strlen(content[i]);
		if (len > len_save)
			len_save = len;
		i++;
	}
	return (len_save);
}

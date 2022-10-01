#include <fcntl.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "../includes/parsing.h"
#include "../libft/libft.h"

bool	cb_hor_loop(t_map *map_info, int i, int j)
{
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
	return (cb_hor_loop(map_info, i, j));
}

bool	cb_vert_loop(t_map *map_info, int i, int j)
{
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
	return (cb_vert_loop(map_info, i, j));
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
					return (ft_false("Error\nMap: Not closed by walls\n", 1));
			}
			j++;
		}
		i++;
	}
	return (true);
}

//HEADER

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

//Check if a line start with an invalid identifier (!= 1, 0, N, S, W, E, F or C)
bool	cb_valid_content(char **content)
{
	int	i;

	i = 0;
	while (content[i])
	{
		if (cb_line_type(content[i]) == 4)
		{
			printf("Error\nMap file: Invalid entry\n");
			return (false);
		}
		else
			i++;
	}
	return (true);
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
					printf("Error\nMap: Not closed by walls\n");
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

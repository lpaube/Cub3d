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
	size_t	s1_len;

	i = 0;
	cpy = ft_calloc(sizeof(*s1), len + 1);
	s1_len = ft_strlen(s1) + 1;
	if (!cpy)
		return (0);
	while (i < len)
	{
		if (i >= s1_len)
			cpy[i] = ' ';
		else
			cpy[i] = s1[i];
		i++; 
	}
	cpy[i] = '\0';
	return (cpy);
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

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
		while (s1[i] == ' ')
			i++;
		if (s1[i] == '\0')
			break ;
		cpy[i] = s1[i];
		i++;
	}
	return (cpy);
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

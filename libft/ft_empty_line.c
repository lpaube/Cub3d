//42 HEADER

#include <stdbool.h>

bool	ft_empty_line(char *string)
{
	int		i;
	char	c;

	i = 0;
	while (string[i])
	{
		c = string[i];
		if (c != ' ' || c != '\n' || c !=  '\t' || c != '\v' || c != '\f'
			|| c != '\r')
			return (false);
		i++;
	}
	return (true);
}

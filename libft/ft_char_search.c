#include "libft.h"

//search for the char to_find in the string. Return 1 if found 0 if not
int	ft_char_search(char *string, char to_find)
{
	int	index;
	int	ret;

	index = 0;
	ret = 0;
	while (string[index])
	{
		if (string[index] == to_find)
			ret++;
		index++;
	}
	return (ret);
}

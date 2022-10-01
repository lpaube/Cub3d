#include "libft.h"

char	*ft_trim_string(char *str, char c)
{
	char	*new_str;
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] != c)
			len++;
		i++;
	}
	new_str = ft_calloc(sizeof(char), len + 1);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			new_str[len] = str[i];
			len++;
		}
		i++;
	}
	return (new_str);
}

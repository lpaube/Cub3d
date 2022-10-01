#include "libft.h"

char	*ft_inv_string(char *str, int size)
{
	int	temp;
	int	start;
	int	end;

	start = 0;
	end = size - 1;
	if (str[start] == '-')
		start++;
	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
	return (str);
}

#include "libft.h"

int	ft_isdigit_s(int *c)
{
	int	index;

	index = 0;
	if (c[index] == '-')
		index++;
	while (c[index + 1])
	{
		if (c[index] >= 48 && c[index] <= 57)
			index++;
		else
			return (0);
	}
	if (c[index] >= 48 && c[index] <= 57)
		return (1);
	else
		return (0);
}

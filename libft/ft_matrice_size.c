#include "libft.h"

int	ft_matrice_size(char **tab)
{
	int	size;

	size = 0;
	if (tab)
		while (tab[size])
			size++;
	return (size);
}

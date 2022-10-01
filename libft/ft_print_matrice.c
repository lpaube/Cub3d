#include "libft.h"

void	ft_print_matrice(char **matrice)
{
	int	x;
	int	y;

	x = 0;
	while (matrice[x])
	{
		y = 0;
		while (matrice[x][y])
		{
			write(1, &matrice[x][y], 1);
			y++;
		}
		write(1, "\n", 1);
		x++;
	}
	return ;
}

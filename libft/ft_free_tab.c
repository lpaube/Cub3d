#include "libft.h"

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			if (tab[i] != NULL)
				free(tab[i]);
			i++;
		}
		free (tab);
	}
	return ;
}

//HEADER

#include "libft.h"

//Return the index of the longest string in an array of string.
int	ft_longest_string(char **matrice)
{
	int	len;
	int	len_save;
	int	i;
	int	ret;
	
	i = 1;
	ret = 0;
	len_save = ft_strlen(matrice[0]);
	while (matrice[i])
	{
		len = ft_strlen(matrice[i]);
		if (len > len_save)
		{
			len_save = len;
			ret = i;
		}
		i++;
	}
	return(ret);
}

#include "libft.h"

bool	ft_majchar(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (true);
	else
		return (false);
}

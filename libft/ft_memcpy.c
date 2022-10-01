#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	index;
	char	*a;
	char	*b;

	a = (char *) src;
	b = (char *) dst;
	index = 0;
	while (index < n)
	{
		b[index] = a[index];
		index ++;
	}
	dst = b;
	return (dst);
}

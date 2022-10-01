#include "libft.h"

char	*ft_strndup(const char *s1, size_t len)
{
	char	*cpy;

	cpy = ft_calloc(sizeof(*s1), len + 1);
	if (!cpy)
		return (0);
	cpy = ft_memcpy((void *)cpy, s1, len);
	return (cpy);
}


void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			index;
	unsigned char	*a;
	unsigned char	*b;

	if (!dst && !src)
		return (NULL);
	a = (unsigned char *) src;
	b = (unsigned char *) dst;
	index = 0;
	while (index < n)
	{
		b[index] = a[index];
		if (b[index] == (unsigned char)c)
			return (dst + index + 1);
		index++;
	}
	return (NULL);
}

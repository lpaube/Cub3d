
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*cmp;
	const unsigned char	*cmp2;
	size_t				i;

	i = 0;
	cmp = (const unsigned char *)s1;
	cmp2 = (const unsigned char *)s2;
	if (n == 0)
		return (0);
	while (n-- > 0 && cmp[i] == cmp2[i])
	{
		i++;
		if (n == 0)
			return (0);
	}
	return (cmp[i] - cmp2[i]);
}

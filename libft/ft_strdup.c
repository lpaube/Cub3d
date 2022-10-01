
char	*ft_strdup(const char *s1)
{
	char		*cpy;
	size_t		len;

	len = ft_strlen(s1) + 1;
	cpy = malloc(sizeof(*s1) * len);
	if (!cpy)
		return (0);
	cpy = ft_memcpy((void *)cpy, s1, len);
	return (cpy);
}

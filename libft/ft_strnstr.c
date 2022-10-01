
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!needle[j])
		return ((char *)haystack);
	while (i < len && haystack[i])
	{
		j = 0;
		while (needle[j] == haystack[i] && len != i)
		{
			j++;
			i++;
			if (needle[j] == '\0')
				return ((char *)&haystack[i - j]);
		}
		i++;
	}
	return (NULL);
}

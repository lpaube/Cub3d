
char	*ft_strrchr(const char *s, int c)
{
	int	index;
	int	len;

	index = 0;
	len = ft_strlen(s) - 1;
	if (c == '\0')
		return ((char *)s + len + 1);
	while (s[index] != (char)c && s[index])
		index++;
	if ((char)c == s[index])
	{
		s = s + len;
		while (*s != (char)c)
			s--;
		return ((char *)s);
	}
	else
		return (NULL);
}

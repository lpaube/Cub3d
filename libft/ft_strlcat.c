
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	lensrc;
	size_t	lendst;
	size_t	index;

	index = 0;
	lensrc = ft_strlen(src);
	lendst = ft_strlen(dst);
	if (dstsize == 0)
		return (lensrc);
	while (src[index] && (index + lendst) < (dstsize - 1))
	{
		dst[index + lendst] = src[index];
		index++;
	}
	dst[index + lendst] = '\0';
	if (dstsize > lendst)
		return (lendst + lensrc);
	return (dstsize + lensrc);
}

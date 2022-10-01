
void	ft_putendl_fd(char *s, int fd)
{
	char	n;

	n = '\n';
	if (!s)
		return ;
	ft_putstr_fd(s, fd);
	write(fd, &n, 1);
}

#include "libft.h"

int	ft_check_file(int fd)
{
	char	buf;

	if (read(fd, &buf, 0) == -1)
	{
		close(fd);
		return (1);
	}
	return (0);
}

int	ft_nbline_file(int fd)
{
	int		count;
	char	buf;
	int		ret;

	ret = 1;
	count = 0;
	if (ft_check_file(fd) == 1)
		return (-1);
	while (ret > 0)
	{
		ret = read(fd, &buf, 1);
		if (ret == 0)
			break ;
		if (ret < 0)
		{
			close(fd);
			return (-1);
		}
		if (buf == '\n')
			count++;
	}
	close (fd);
	return (count + 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 10:57:01 by marvin            #+#    #+#             */
/*   Updated: 2021/06/03 10:57:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gnl_nl_chr(const char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] != '\n')
		return (0);
	return (1);
}

static int	gnl_line(char **save, char **line)
{
	int		i;
	char	*temp;

	i = 0;
	while ((*save)[i] != '\n' && (*save)[i] != '\0')
		i++;
	if ((*save)[i] == '\n')
	{
		*line = ft_substr(*save, 0, i);
		temp = ft_strdup(&((*save)[i + 1]));
		free(*save);
		*save = temp;
		if ((*save)[0] == '\0')
			gnl_free(save);
		return (1);
	}
	else
	{
		*line = ft_strdup(*save);
		gnl_free(save);
		return (0);
	}
}

int	gnl_return(char **save, char **line, int ret, int fd)
{
	if (ret < 0)
		return (-1);
	else if (!ret && !save[fd])
	{
		*line = ft_strdup("\0");
		return (0);
	}
	return (gnl_line(&save[fd], line));
}

int	gnl_loop(int ret, int fd, char *buf, char **save)
{
	char	*temp;

	ret = read(fd, buf, 0);
	if (ret < 0)
		return (-1);
	ret = 1;
	while (ret > 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		buf[ret] = '\0';
		if (!save[fd])
			save[fd] = ft_strdup(buf);
		else
		{
			temp = ft_strjoin(save[fd], buf);
			free(save[fd]);
			save[fd] = temp;
		}
		if (gnl_nl_chr(buf))
			break ;
	}
	return (ret);
}

int	get_next_line(int fd, char **line)
{
	static char	*save[1024];
	char		*buf;
	int			ret;

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (-1);
	ret = 1;
	ret = gnl_loop(ret, fd, buf, save);
	gnl_free(&buf);
	return (gnl_return(save, line, ret, fd));
}

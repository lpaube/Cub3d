/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbline_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 18:50:40 by mafortin          #+#    #+#             */
/*   Updated: 2022/01/28 17:26:20 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nbline_file(int fd)
{
	int		count;
	char	buf;
	int		ret;

	ret = 1;
	count = 0;
	while (ret > 0)
	{
		ret = read(fd, &buf, 1);
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

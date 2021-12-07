/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_matrice_fd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 21:02:29 by mafortin          #+#    #+#             */
/*   Updated: 2021/09/30 21:04:14 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_matrice_fd(char **matrice, int fd)
{
	int	x;
	int	y;

	x = 0;
	while (matrice[x])
	{
		y = 0;
		while (matrice[x][y])
		{
			write(fd, &matrice[x][y], 1);
			y++;
		}
		write(fd, "\n", 1);
		x++;
	}
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_matrice.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 12:54:32 by mafortin          #+#    #+#             */
/*   Updated: 2021/09/30 21:13:38 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_matrice(char **matrice)
{
	int	x;
	int	y;

	x = 0;
	while (matrice[x])
	{
		y = 0;
		while (matrice[x][y])
		{
			write(1, &matrice[x][y], 1);
			y++;
		}
		write(1, "\n", 1);
		x++;
	}
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 16:29:46 by mafortin          #+#    #+#             */
/*   Updated: 2021/10/25 13:42:50 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_remove_line(char **matrice, int index)
{
	char	**new_matrice;
	int		depth;
	int		x;
	int		x_2;

	x = 0;
	x_2 = 0;
	depth = ft_matrice_size(matrice);
	new_matrice = ft_calloc(depth, sizeof(char *));
	while (matrice[x])
	{
		if (x == depth - 1)
			break ;
		if (x == index)
			x++;
		new_matrice[x_2] = ft_strdup(matrice[x]);
		x_2++;
		x++;
	}
	ft_free_tab(matrice);
	matrice = NULL;
	return (new_matrice);
}

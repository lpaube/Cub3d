/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 17:01:29 by mafortin          #+#    #+#             */
/*   Updated: 2021/09/30 21:14:48 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//change une ligne dans une matrice. prend l'index de la ligne a changer et
//un char * de la nouvelle ligne
char	**ft_change_line(char **matrice, char *newline, int index)
{
	int		i;
	char	**new_matrice;
	int		depth;

	i = 0;
	depth = ft_matrice_size(matrice);
	new_matrice = malloc(sizeof(char *) * depth + 1);
	if (!new_matrice)
		return (NULL);
	while (matrice[i])
	{
		if (i == index)
		{
			new_matrice[i] = ft_calloc(ft_strlen(newline) + 1, sizeof(char));
			ft_strdup(matrice[i]);
		}
		else
			new_matrice[i] = ft_strdup(matrice[i]);
		i++;
	}
	return (new_matrice);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 13:34:37 by mafortin          #+#    #+#             */
/*   Updated: 2021/10/04 13:35:37 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Alloc un nouveau char**, copy la matrice a l'interieur
//et rajoute line a la fin.
//Free matrice original. Le retour doit etre free a
//l'exterieur de la fonction.
char	**ft_addline(char **matrice, char *line)
{
	int		depth;
	char	**new_matrice;
	int		index;

	index = 0;
	depth = ft_matrice_size(matrice) + 1;
	new_matrice = ft_calloc(depth + 1, sizeof(char *));
	while (matrice[index])
	{
		new_matrice[index] = ft_strdup(matrice[index]);
		index++;
	}
	new_matrice[index] = ft_strdup(line);
	ft_free_tab(matrice);
	return (new_matrice);
}

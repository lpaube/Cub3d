/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longest_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:13:14 by mafortin          #+#    #+#             */
/*   Updated: 2022/02/07 15:13:27 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Return the index of the longest string in an array of string.
int	ft_longest_string(char **matrice)
{
	int	len;
	int	len_save;
	int	i;
	int	ret;

	i = 1;
	ret = 0;
	len_save = ft_strlen(matrice[0]);
	while (matrice[i])
	{
		len = ft_strlen(matrice[i]);
		if (len > len_save)
		{
			len_save = len;
			ret = i;
		}
		i++;
	}
	return (ret);
}

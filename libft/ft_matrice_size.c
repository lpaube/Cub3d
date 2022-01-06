/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrice_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 19:32:58 by mafortin          #+#    #+#             */
/*   Updated: 2021/12/09 17:50:27 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_matrice_size(char **tab)
{
	int	size;

	size = 0;
	if (tab)
		while (tab[size])
			size++;
	return (size);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 11:41:15 by mafortin          #+#    #+#             */
/*   Updated: 2021/08/23 17:18:49 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit_s(int *c)
{
	int	index;

	index = 0;
	if (c[index] == '-')
		index++;
	while (c[index + 1])
	{
		if (c[index] >= 48 && c[index] <= 57)
			index++;
		else
			return (0);
	}
	if (c[index] >= 48 && c[index] <= 57)
		return (1);
	else
		return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_empty_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:11:58 by mafortin          #+#    #+#             */
/*   Updated: 2022/02/07 15:12:11 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

bool	ft_empty_line(char *string)
{
	int		i;
	char	c;

	i = 0;
	while (string[i])
	{
		c = string[i];
		if (c != ' ' || c != '\n' || c != '\t' || c != '\v' || c != '\f'
			|| c != '\r')
			return (false);
		i++;
	}
	return (true);
}

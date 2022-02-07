/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:13:49 by mafortin          #+#    #+#             */
/*   Updated: 2022/02/07 15:14:05 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Alloc for len and fill the string with char c
char	*ft_fill(int len, char c)
{
	char	*string;

	string = malloc(sizeof(char) * len + 1);
	if (!string)
		return (NULL);
	string[len + 1] = '\0';
	while (len >= 0)
	{
		string[len] = c;
		len--;
	}
	return (string);
}

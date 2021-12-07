/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 13:33:29 by mafortin          #+#    #+#             */
/*   Updated: 2021/05/18 12:36:30 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			index;
	unsigned char	*a;
	unsigned char	*b;

	if (!dst && !src)
		return (NULL);
	a = (unsigned char *) src;
	b = (unsigned char *) dst;
	index = 0;
	while (index < n)
	{
		b[index] = a[index];
		if (b[index] == (unsigned char)c)
			return (dst + index + 1);
		index++;
	}
	return (NULL);
}

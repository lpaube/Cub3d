/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 11:57:30 by mafortin          #+#    #+#             */
/*   Updated: 2021/09/22 18:11:25 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	index;
	char	*a;
	char	*b;

	a = (char *) src;
	b = (char *) dst;
	index = 0;
	while (index < n)
	{
		b[index] = a[index];
		index ++;
	}
	dst = b;
	return (dst);
}

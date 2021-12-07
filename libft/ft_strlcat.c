/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 15:19:32 by mafortin          #+#    #+#             */
/*   Updated: 2021/05/17 18:11:25 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	lensrc;
	size_t	lendst;
	size_t	index;

	index = 0;
	lensrc = ft_strlen(src);
	lendst = ft_strlen(dst);
	if (dstsize == 0)
		return (lensrc);
	while (src[index] && (index + lendst) < (dstsize - 1))
	{
		dst[index + lendst] = src[index];
		index++;
	}
	dst[index + lendst] = '\0';
	if (dstsize > lendst)
		return (lendst + lensrc);
	return (dstsize + lensrc);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 14:06:43 by mafortin          #+#    #+#             */
/*   Updated: 2021/05/17 13:28:34 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*cmp;
	const unsigned char	*cmp2;
	size_t				i;

	i = 0;
	cmp = (const unsigned char *)s1;
	cmp2 = (const unsigned char *)s2;
	if (n == 0)
		return (0);
	while (n-- > 0 && cmp[i] == cmp2[i])
	{
		i++;
		if (n == 0)
			return (0);
	}
	return (cmp[i] - cmp2[i]);
}

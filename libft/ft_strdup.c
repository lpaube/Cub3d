/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 15:18:21 by mafortin          #+#    #+#             */
/*   Updated: 2021/05/17 16:57:20 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char		*cpy;
	size_t		len;

	len = ft_strlen(s1) + 1;
	cpy = malloc(sizeof(*s1) * len);
	if (!cpy)
		return (0);
	cpy = ft_memcpy((void *)cpy, s1, len);
	return (cpy);
}

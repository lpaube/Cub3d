/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpst <hpst@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 23:12:16 by mafortin          #+#    #+#             */
/*   Updated: 2021/10/15 22:24:39 by hpst             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t len)
{
	char	*cpy;

	cpy = ft_calloc(sizeof(*s1), len + 1);
	if (!cpy)
		return (0);
	cpy = ft_memcpy((void *)cpy, s1, len);
	return (cpy);
}

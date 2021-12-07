/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 13:07:49 by mafortin          #+#    #+#             */
/*   Updated: 2021/05/17 17:51:23 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	index;
	int	len;

	index = 0;
	len = ft_strlen(s) - 1;
	if (c == '\0')
		return ((char *)s + len + 1);
	while (s[index] != (char)c && s[index])
		index++;
	if ((char)c == s[index])
	{
		s = s + len;
		while (*s != (char)c)
			s--;
		return ((char *)s);
	}
	else
		return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_rev.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 17:18:07 by mafortin          #+#    #+#             */
/*   Updated: 2021/08/23 17:18:09 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nbw(const char *s, char c)
{
	size_t	i;
	size_t	nb;

	i = 0;
	nb = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] != c && s[i])
			i++;
		nb++;
	}
	if (s[i - 1] == c)
		nb--;
	return (nb);
}

static size_t	ft_wlen(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (*s != c && *s)
	{
		s++;
		len++;
	}
	return (len);
}

static char	**ft_freetab(char **tab, size_t nb)
{
	size_t	i;

	if (tab)
	{
		i = 0;
		while (i < nb)
		{
			if (tab[i] != NULL)
				free(tab[i]);
			i++;
		}
		free(tab);
	}
	return (NULL);
}

static char	**ft_maketab(char **tab, const char *s, char c)
{
	size_t	x;
	size_t	y;

	x = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s == '\0')
			continue ;
		tab[x] = malloc(sizeof(char *) * ft_wlen(s, c) + 1);
		if (!tab[x])
			return (ft_freetab(tab, x));
		y = 0;
		while (*s != c && *s)
		{
			tab[x][y] = *s;
			y++;
			s++;
		}
		tab[x][y] = '\0';
		x++;
	}
	tab[x] = 0;
	return (tab);
}

char	**ft_split(const char *s, char c)
{
	char	**tab;

	if (!s)
		return (NULL);
	tab = malloc(sizeof(char *) * (ft_nbw(s, c) + 1));
	if (!tab)
	{
		free (tab);
		return (NULL);
	}
	ft_maketab(tab, s, c);
	return (tab);
}

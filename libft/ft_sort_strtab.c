/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_strtab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 11:04:31 by mmondell          #+#    #+#             */
/*   Updated: 2021/11/14 13:27:14 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**sort_tab(char **new_tab, int tab_size)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	while (i < tab_size)
	{
		j = i + 1;
		while (j < tab_size)
		{
			if (ft_strncmp(new_tab[i], new_tab[j], ft_strlen(new_tab[j])) > 0)
			{
				temp = new_tab[i];
				new_tab[i] = new_tab[j];
				new_tab[j] = temp;
			}
			j++;
		}
		i++;
	}
	return (new_tab);
}

char	**ft_sort_strtab(char **tab)
{
	char	**sorted_tab;
	int		tab_size;

	tab_size = ft_matrice_size(tab);
	sorted_tab = ft_matrice_cpy(tab);
	sorted_tab = sort_tab(sorted_tab, tab_size);
	return (sorted_tab);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 14:10:51 by mafortin          #+#    #+#             */
/*   Updated: 2022/02/07 12:14:09 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "../includes/parsing.h"
#include "../libft/libft.h"

bool	cb_find_texture(char **content, char *ori, char **texture, int x)
{
	int	i;
	int	j;

	i = 0;
	while (content[i])
	{
		j = 0;
		while (content[i][j] == ' ')
			j++;
		if (ft_strncmp(content[i] + j, ori, 2) == 0)
		{
			if (texture[x] == NULL)
				texture[x] = ft_strdup(content[i] + j + 3);
			else
				return (false);
		}
		i++;
	}
	if (texture[x] == NULL)
		return (false);
	return (true);
}

bool	cb_texture_parsing(char **content, t_map *map_info)
{
	bool	ret;

	ret = true;
	map_info->texture = ft_calloc(sizeof(char *), 4);
	if (cb_find_texture(content, "NO", map_info->texture, 0) == false)
		ret = false;
	if (cb_find_texture(content, "EA", map_info->texture, 1) == false)
		ret = false;
	if (cb_find_texture(content, "SO", map_info->texture, 2) == false)
		ret = false;
	if (cb_find_texture(content, "WE", map_info->texture, 3) == false)
		ret = false;
	if (ret == false)
		printf("Error\nTexture\n");
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:37:58 by mafortin          #+#    #+#             */
/*   Updated: 2022/02/07 19:36:41 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "cub3d.h"
#include "graphics.h"

void	put_background(t_mlx *mlx_inst, t_graph *screen)
{
	int	i;
	int	j;

	i = 0;
	while (i <= WIN_HEIGTH)
	{
		j = 0;
		while (j <= WIN_WIDTH)
		{
			if (i <= (WIN_HEIGTH / 2))
				my_pixel_put(mlx_inst, j, i, screen->rgb_ceilling);
			else
				my_pixel_put(mlx_inst, j, i, screen->rgb_floor);
			j++;
		}
		i++;
	}
}

int	rgb_converter(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	background_converter(t_map *map_info, t_graph *screen)
{
	screen->rgb_floor = rgb_converter(0, map_info->floor[0],
			map_info->floor[1], map_info->floor[2]);
	screen->rgb_ceilling = rgb_converter(0, map_info->ceilling[0],
			map_info->ceilling[1], map_info->ceilling[2]);
}

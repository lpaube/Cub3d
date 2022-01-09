/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <laube@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 16:48:47 by laube             #+#    #+#             */
/*   Updated: 2022/01/08 17:04:17 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "raycasting.h"

void	draw_map_contour(t_cub2d *cub2d)
{
	t_rect	rect;

	rect.x = 0;
	rect.y = 0;
	rect.width = TILE_SIZE * map_width;
	rect.heigth = TILE_SIZE * map_height;
	rect.color = 0xFFFFFF;
	draw_rect(&cub2d->mlx_inst, rect);
}

void	draw_map_squares(t_cub2d *cub2d)
{
	t_rect	rect;
	int		i;
	int		j;

	j = -1;
	while (++j < map_height)
	{
		i = -1;
		while (++i < map_width)
		{
			rect.x = TILE_SIZE * i;
			rect.y = TILE_SIZE * j;
			rect.width = TILE_SIZE;
			rect.heigth = TILE_SIZE;
			rect.color = 0x0000FF;
			if (map[j][i] == '1')
				draw_rect(&cub2d->mlx_inst, rect);
			else
			{
				rect.color = 0x000000;
				draw_rect(&cub2d->mlx_inst, rect);
			}
		}
	}
}

void	draw_map_grids(t_cub2d *cub2d)
{
	t_line	line;
	int		i;

	i = -1;
	while (++i <= map_height)
	{
		line.x1 = 0;
		line.x2 = TILE_SIZE * map_width;
		line.y1 = TILE_SIZE * i;
		line.y2 = TILE_SIZE * i;
		line.color = 0xAAAAAA;
		draw_line(&cub2d->mlx_inst, line);
	}
	i = -1;
	while (++i <= map_width)
	{
		line.x1 = TILE_SIZE * i;
		line.x2 = TILE_SIZE * i;
		line.y1 = 0;
		line.y2 = TILE_SIZE * map_height;
		line.color = 0x888888;
		draw_line(&cub2d->mlx_inst, line);
	}
}

void	draw_map(t_cub2d *cub2d)
{
	draw_map_contour(cub2d);
	draw_map_squares(cub2d);
	draw_map_grids(cub2d);
}

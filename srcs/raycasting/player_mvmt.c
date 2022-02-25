/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mvmt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 20:04:13 by laube             #+#    #+#             */
/*   Updated: 2022/01/28 23:41:49 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "raycasting.h"

int	has_clipping(t_cub2d *cub2d, int newtile_x, int newtile_y)
{
	int	tile_y;
	int	tile_x;

	tile_y = cub2d->player.tile_y;
	tile_x = cub2d->player.tile_x;
	if (cub2d->map.map[tile_y][newtile_x]
			&& cub2d->map.map[newtile_y][tile_x] == '1')
		return (1);
	return (0);
}

int	has_collision(t_cub2d *cub2d, int mvmt)
{
	int	newpos_x;
	int	newpos_y;
	int	newtile_x;
	int	newtile_y;

	newpos_x = cub2d->player.circle.mid_x + mvmt * cub2d->player.dir_x;
	newpos_y = cub2d->player.circle.mid_y + mvmt * cub2d->player.dir_y;
	newtile_x = newpos_x / cub2d->tile_size;
	newtile_y = newpos_y / cub2d->tile_size;
	if (cub2d->map.map[newtile_y][newtile_x] == '1')
		return (1);
	if (has_clipping(cub2d, newtile_x, newtile_y))
	{
		return (1);
	}
	return (0);
}

void	player_mvmt(int keycode, t_cub2d *cub2d)
{
	if (keycode == MAIN_W)
	{
		if (!has_collision(cub2d, cub2d->player.mvmt))
		{
			cub2d->player.circle.mid_x += cub2d->player.mvmt * cub2d->player.dir_x;
			cub2d->player.circle.mid_y += cub2d->player.mvmt * cub2d->player.dir_y;
		}
	}
	if (keycode == MAIN_S)
	{
		if (!has_collision(cub2d, -cub2d->player.mvmt))
		{
			cub2d->player.circle.mid_x -= cub2d->player.mvmt * cub2d->player.dir_x;
			cub2d->player.circle.mid_y -= cub2d->player.mvmt * cub2d->player.dir_y;
		}
	}
	if (keycode == MAIN_A)
		cub2d->player.angle += 2;
	if (keycode == MAIN_D)
		cub2d->player.angle -= 2;
	if (cub2d->player.angle >= 360)
		cub2d->player.angle = 0;
	if (cub2d->player.angle < 0)
		cub2d->player.angle = 359;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mvmt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 20:04:13 by laube             #+#    #+#             */
/*   Updated: 2022/03/16 18:14:27 by laube            ###   ########.fr       */
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

int	check_collision(t_cub2d *cub2d, int newtile_x, int newtile_y)
{
	if (newtile_x >= cub2d->map.map_width || newtile_x < 0
		|| newtile_y >= cub2d->map.map_height || newtile_y < 0)
		return (1);
	if (cub2d->map.map[newtile_y][newtile_x] == '1')
		return (2);
	if (has_clipping(cub2d, newtile_x, newtile_y))
		return (2);
	return (0);
}

int	check_all_collision(t_cub2d *cub2d, int newpos_x, int newpos_y)
{
	int	margin;
	int	angle;
	int	tmp_pos_x;
	int	tmp_pos_y;

	angle = 0;
	margin = 3;
	while (angle < 360)
	{
		tmp_pos_x = newpos_x + margin * (cos(deg_to_rad(angle)));
		tmp_pos_y = newpos_y + margin * (sin(deg_to_rad(angle)));
		if (check_collision(cub2d, tmp_pos_x / cub2d->tile_size,
				tmp_pos_y / cub2d->tile_size) == 1)
			return (1);
		angle++;
	}
	return (0);
}

int	has_collision(t_cub2d *cub2d)
{
	double	newpos_x;
	double	newpos_y;

	newpos_x = cub2d->player.circle.mid_x + ((cub2d->player.vel_u
				- cub2d->player.vel_d) * 0.5) * cub2d->player.dir_x;
	newpos_x += ((cub2d->player.vel_r - cub2d->player.vel_l) * 0.5)
		* (1 * cos(deg_to_rad(cub2d->player.angle - 90)));
	newpos_y = cub2d->player.circle.mid_y + ((cub2d->player.vel_u
				- cub2d->player.vel_d) * 0.5) * cub2d->player.dir_y;
	newpos_y += ((cub2d->player.vel_r - cub2d->player.vel_l) * 0.5)
		* (-1 * sin(deg_to_rad(cub2d->player.angle - 90)));
	if (check_all_collision(cub2d, newpos_x, newpos_y) == 0)
		return (0);
	if (check_all_collision(cub2d, cub2d->player.circle.mid_x, newpos_y) == 0)
		return (1);
	if (check_all_collision(cub2d, newpos_x, cub2d->player.circle.mid_y) == 0)
		return (2);
	return (3);
}

void	player_mvmt(t_cub2d *cub2d)
{
	int			move_possible;
	t_player	*plyr;

	plyr = &cub2d->player;
	move_possible = has_collision(cub2d);
	if (move_possible % 2 == 0)
	{
		plyr->circle.mid_x += ((plyr->vel_u - plyr->vel_d) * 0.5) * plyr->dir_x;
		plyr->circle.mid_x += ((plyr->vel_r - plyr->vel_l) * 0.5)
			* (1 * cos(deg_to_rad(plyr->angle - 90)));
	}
	if (move_possible < 2)
	{
		plyr->circle.mid_y += ((plyr->vel_u - plyr->vel_d) * 0.5) * plyr->dir_y;
		plyr->circle.mid_y += ((plyr->vel_r - plyr->vel_l) * 0.5)
			* (-1 * sin(deg_to_rad(plyr->angle - 90)));
	}
	if (plyr->rot_l == 1)
		plyr->angle += 2;
	if (plyr->rot_r == 1)
		plyr->angle -= 2;
	if (plyr->angle >= 360)
		plyr->angle = 0;
	if (plyr->angle < 0)
		plyr->angle = 359;
}

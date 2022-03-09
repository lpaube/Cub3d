/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 13:53:34 by laube             #+#    #+#             */
/*   Updated: 2022/03/09 11:57:33 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "raycasting.h"

void	hitpos_side_x(t_cub2d *cub2d, int x)
{
	double	distance;
	int		tmp_map;

	tmp_map = cub2d->raycast.map_y;
	distance = cub2d->rays[x].len * cub2d->rays[x].ray_dir_y;
	if (cub2d->raycast.step_y == -1)
		distance += cub2d->raycast.offset_y;
	else
		distance += cub2d->tile_size - cub2d->raycast.offset_y;
	while (cub2d->player.tile_y - tmp_map != 0)
	{
		distance -= cub2d->tile_size * cub2d->raycast.step_y;
		tmp_map -= cub2d->raycast.step_y;
	}
	cub2d->rays[x].hit_pos = distance / cub2d->tile_size;
	cub2d->rays[x].hit_pos -= floor((cub2d->rays[x].hit_pos));
}

void	hitpos_side_y(t_cub2d *cub2d, int x)
{
	double	distance;
	int		tmp_map;

	tmp_map = cub2d->raycast.map_x;
	distance = cub2d->rays[x].len * cub2d->raycast.ray_dir_x;
	if (cub2d->raycast.step_x == -1)
		distance += cub2d->raycast.offset_x;
	else
		distance += cub2d->tile_size - cub2d->raycast.offset_x;
	while (cub2d->player.tile_x - tmp_map != 0)
	{
		distance -= cub2d->tile_size * cub2d->raycast.step_x;
		tmp_map -= cub2d->raycast.step_x;
	}
	cub2d->rays[x].hit_pos = distance / cub2d->tile_size;
	cub2d->rays[x].hit_pos -= floor((cub2d->rays[x].hit_pos));
}

void	get_hitpos(t_cub2d *cub2d, int x)
{
	if (cub2d->raycast.side == 0)
		hitpos_side_x(cub2d, x);
	else
		hitpos_side_y(cub2d, x);
}

void	get_ray_side(t_cub2d *cub2d, int x)
{
	if (cub2d->raycast.side == 0)
	{
		cub2d->raycast.dist_x -= cub2d->raycast.delta_x * cub2d->tile_size;
		cub2d->rays[x].len = cub2d->raycast.dist_x;
		if (cub2d->raycast.step_x == 1)
			cub2d->rays[x].face = 'W';
		else
			cub2d->rays[x].face = 'E';
	}
	else if (cub2d->raycast.side == 1)
	{
		cub2d->raycast.dist_y -= cub2d->raycast.delta_y * cub2d->tile_size;
		cub2d->rays[x].len = cub2d->raycast.dist_y;
		if (cub2d->raycast.step_y == 1)
			cub2d->rays[x].face = 'N';
		else
			cub2d->rays[x].face = 'S';
	}
}

void	get_ray_data(t_cub2d *cub2d, int x)
{
	cub2d->rays[x].ray_dir_x = cub2d->raycast.ray_dir_x;
	cub2d->rays[x].ray_dir_y = cub2d->raycast.ray_dir_y;
	cub2d->rays[x].map_x = cub2d->raycast.map_x;
	cub2d->rays[x].map_y = cub2d->raycast.map_y;
	get_hitpos(cub2d, x);
	cub2d->rays[x].height = (int)(cub2d->mlx_inst.win_height
			/ cub2d->rays[x].len * 20);
	cub2d->rays[x].draw_top = -(cub2d->rays[x].height / 2)
		+ (cub2d->mlx_inst.win_height / 2);
	if (cub2d->rays[x].draw_top < 0)
		cub2d->rays[x].draw_top = 0;
	cub2d->rays[x].draw_bottom = (cub2d->rays[x].height / 2)
		+ (cub2d->mlx_inst.win_height / 2);
	if (cub2d->rays[x].draw_bottom >= cub2d->mlx_inst.win_height)
		cub2d->rays[x].draw_bottom = cub2d->mlx_inst.win_height - 1;
}

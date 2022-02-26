/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 22:39:46 by laube             #+#    #+#             */
/*   Updated: 2022/02/26 13:57:05 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "raycasting.h"

void	offset_x(t_cub2d *cub2d)
{
	if (cub2d->raycast.ray_dir_x < 0)
	{
		cub2d->raycast.step_x = -1;
		cub2d->raycast.offset_x = cub2d->player.circle.mid_x
			- (cub2d->raycast.map_x * cub2d->tile_size);
		cub2d->raycast.dist_x = cub2d->raycast.offset_x
			* cub2d->raycast.delta_x;
	}
	else
	{
		cub2d->raycast.step_x = 1;
		cub2d->raycast.offset_x = (cub2d->raycast.map_x + 1)
			* cub2d->tile_size - cub2d->player.circle.mid_x;
		cub2d->raycast.dist_x = cub2d->raycast.offset_x
			* cub2d->raycast.delta_x;
	}
}

void	offset_y(t_cub2d *cub2d)
{
	if (cub2d->raycast.ray_dir_y < 0)
	{
		cub2d->raycast.step_y = -1;
		cub2d->raycast.offset_y = (cub2d->player.circle.mid_y
				- (cub2d->raycast.map_y * cub2d->tile_size));
		cub2d->raycast.dist_y = cub2d->raycast.offset_y
			* cub2d->raycast.delta_y;
	}
	else
	{
		cub2d->raycast.step_y = 1;
		cub2d->raycast.offset_y = ((cub2d->player.tile_y + 1)
				* cub2d->tile_size - cub2d->player.circle.mid_y);
		cub2d->raycast.dist_y = cub2d->raycast.offset_y
			* cub2d->raycast.delta_y;
	}
}

void	dist_offset(t_cub2d *cub2d)
{
	offset_x(cub2d);
	offset_y(cub2d);
}

void	init_raycast(t_cub2d *cub2d, int x)
{
	cub2d->raycast.camera_x = 2 * x
		/ ((double)cub2d->mlx_inst.win_width - 1) - 1;
	cub2d->raycast.ray_dir_x = cub2d->player.dir_x
		+ cub2d->player.plane_x * cub2d->raycast.camera_x;
	cub2d->raycast.ray_dir_y = cub2d->player.dir_y
		+ cub2d->player.plane_y * cub2d->raycast.camera_x;
	cub2d->raycast.map_x = cub2d->player.tile_x;
	cub2d->raycast.map_y = cub2d->player.tile_y;
	cub2d->raycast.delta_x = fabs(1 / cub2d->raycast.ray_dir_x);
	cub2d->raycast.delta_y = fabs(1 / cub2d->raycast.ray_dir_y);
}

void	ray_cast(t_cub2d *cub2d)
{
	int		hit;
	int		x;

	x = -1;
	cub2d->ray_num = cub2d->mlx_inst.win_width;
	cub2d->rays = malloc(sizeof(t_rays) * cub2d->ray_num);
	while (++x < cub2d->ray_num)
	{
		hit = 0;
		init_raycast(cub2d, x);
		dist_offset(cub2d);
		while (hit == 0)
		{
			inc_ray_len(cub2d);
			if (cub2d->map.map[cub2d->raycast.map_y]
				[cub2d->raycast.map_x] == '1')
			{
				hit = 1;
				get_ray_side(cub2d, x);
				get_ray_data(cub2d, x);
			}
		}
	}
}

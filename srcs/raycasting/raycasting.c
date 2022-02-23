/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 22:39:46 by laube             #+#    #+#             */
/*   Updated: 2022/02/22 12:14:19 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "raycasting.h"

void	dist_offset(t_cub2d *cub2d)
{
	if (cub2d->raycast.ray_dir_x < 0)
	{
		cub2d->raycast.step_x = -1;
	//	cub2d->raycast.dist_x = (cub2d->player.circle.mid_x
	//			- (cub2d->raycast.map_x * cub2d->tile_size)) * cub2d->raycast.delta_x;
		cub2d->raycast.offset_x = cub2d->player.circle.mid_x
				- (cub2d->raycast.map_x * cub2d->tile_size);
		cub2d->raycast.dist_x = cub2d->raycast.offset_x * cub2d->raycast.delta_x;
	}
	else
	{
		cub2d->raycast.step_x = 1;
//		cub2d->raycast.dist_x = ((cub2d->raycast.map_x + 1) * cub2d->tile_size
//				- cub2d->player.circle.mid_x) * cub2d->raycast.delta_x;
		cub2d->raycast.offset_x = (cub2d->raycast.map_x + 1) * cub2d->tile_size - cub2d->player.circle.mid_x;
		cub2d->raycast.dist_x = cub2d->raycast.offset_x * cub2d->raycast.delta_x;
	}
	if (cub2d->raycast.ray_dir_y < 0)
	{
		cub2d->raycast.step_y = -1;
//		cub2d->raycast.dist_y = (cub2d->player.circle.mid_y
//				- (cub2d->raycast.map_y * cub2d->tile_size)) * cub2d->raycast.delta_y;
		cub2d->raycast.offset_y = (cub2d->player.circle.mid_y - (cub2d->raycast.map_y * cub2d->tile_size));
		cub2d->raycast.dist_y = cub2d->raycast.offset_y * cub2d->raycast.delta_y;
	}
	else
	{
		cub2d->raycast.step_y = 1;
	//	cub2d->raycast.dist_y = ((cub2d->player.tile_y + 1) * cub2d->tile_size
	//			- cub2d->player.circle.mid_y) * cub2d->raycast.delta_y;
		cub2d->raycast.offset_y = ((cub2d->player.tile_y + 1) * cub2d->tile_size - cub2d->player.circle.mid_y);
		cub2d->raycast.dist_y = cub2d->raycast.offset_y * cub2d->raycast.delta_y;
	}
}

void	init_raycast(t_cub2d *cub2d, int x)
{
	cub2d->raycast.camera_x = 2 * x / ((double)cub2d->mlx_inst.win_width - 1) - 1;
	cub2d->raycast.ray_dir_x = cub2d->player.dir_x
		+ cub2d->player.plane_x * cub2d->raycast.camera_x;
	cub2d->raycast.ray_dir_y = cub2d->player.dir_y
		+ cub2d->player.plane_y * cub2d->raycast.camera_x;
	cub2d->raycast.map_x = cub2d->player.tile_x;
	cub2d->raycast.map_y = cub2d->player.tile_y;
	cub2d->raycast.delta_x = fabs(1 / cub2d->raycast.ray_dir_x);
	cub2d->raycast.delta_y = fabs(1 / cub2d->raycast.ray_dir_y);
}

void	inc_ray_len(t_cub2d *cub2d)
{
	if (cub2d->raycast.dist_x < cub2d->raycast.dist_y)
	{
		cub2d->raycast.dist_x += cub2d->raycast.delta_x * cub2d->tile_size;
		cub2d->raycast.map_x += cub2d->raycast.step_x;
		cub2d->raycast.side = 0;
	}
	else
	{
		cub2d->raycast.dist_y += cub2d->raycast.delta_y * cub2d->tile_size;
		cub2d->raycast.map_y += cub2d->raycast.step_y;
		cub2d->raycast.side = 1;
	}
}

void	get_hitpos(t_cub2d *cub2d, int x)
{
	double	distance;
	int	tmp_map;

	if (cub2d->raycast.side == 0)
	{
		tmp_map = cub2d->raycast.map_y;
		distance = cub2d->rays[x].len * cub2d->raycast.ray_dir_y;
		if (cub2d->raycast.step_y == -1)
		{
			distance += cub2d->raycast.offset_y;
		}
		else
		{
			distance += cub2d->tile_size - cub2d->raycast.offset_y;
		}
		while (cub2d->player.tile_y - tmp_map != 0)
		{
			distance -= cub2d->tile_size * cub2d->raycast.step_y;
			tmp_map -= cub2d->raycast.step_y;
		}
	}
	else
	{
		tmp_map = cub2d->raycast.map_x;
		distance = cub2d->rays[x].len * cub2d->raycast.ray_dir_x;
		if (cub2d->raycast.step_x == -1)
		{
			distance += cub2d->raycast.offset_x;
		}
		else
		{
			distance += cub2d->tile_size - cub2d->raycast.offset_x;
		}
		while (cub2d->player.tile_x - tmp_map != 0)
		{
			distance -= cub2d->tile_size * cub2d->raycast.step_x;
			tmp_map -= cub2d->raycast.step_x;
		}
	}
	//printf("x: %d | dist: %f | tile_size: %d\n", x, distance, cub2d->tile_size);
	cub2d->rays[x].hit_pos = distance / cub2d->tile_size * 100;
	printf("x: %d | hitpos: %f\n", x, cub2d->rays[x].hit_pos);
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
	// To make view closer
	cub2d->rays[x].len /= 10;

	// To print 2d map for debugging
	cub2d->rays[x].ray_dir_x = cub2d->raycast.ray_dir_x;
	cub2d->rays[x].ray_dir_y = cub2d->raycast.ray_dir_y;
	cub2d->rays[x].map_x = cub2d->raycast.map_x;
	cub2d->rays[x].map_y = cub2d->raycast.map_y;

	get_hitpos(cub2d, x);
	cub2d->rays[x].hit_pos -= floor(cub2d->rays[x].hit_pos);
	cub2d->rays[x].height = (int)(cub2d->mlx_inst.win_height / cub2d->rays[x].len);
	cub2d->rays[x].draw_top = -(cub2d->rays[x].height / 2) + (cub2d->mlx_inst.win_height / 2);
	if (cub2d->rays[x].draw_top < 0)
		cub2d->rays[x].draw_top = 0;
	cub2d->rays[x].draw_bottom = (cub2d->rays[x].height / 2) + (cub2d->mlx_inst.win_height / 2);
	if (cub2d->rays[x].draw_bottom >= cub2d->mlx_inst.win_height)
		cub2d->rays[x].draw_bottom = cub2d->mlx_inst.win_height - 1;
}

void	ray_cast(t_cub2d *cub2d)
{
	int		hit;
	int		x;

	x = -1;
	//cub2d->ray_num = cub2d->mlx_inst.win_width;
	cub2d->ray_num = 1;
	cub2d->rays = malloc(sizeof(t_rays) * cub2d->ray_num);
	while (++x < cub2d->ray_num)//cub2d->mlx_inst.win_width)
	{
		hit = 0;
		init_raycast(cub2d, x);
		dist_offset(cub2d);
		while (hit == 0)
		{
			inc_ray_len(cub2d);
			if (cub2d->map.map[cub2d->raycast.map_y][cub2d->raycast.map_x] == '1')
			{
				hit = 1;
				get_ray_side(cub2d, x);
			}
		}
		/*
		if ((x + 1) % (cub2d->mlx_inst.win_width / 10) == 0 || x == 0 || x == cub2d->mlx_inst.win_width - 1)
		{
			if (cub2d->debug == 2)
				draw_rays(cub2d, x);
		}
		if (cub2d->debug == 2)
			draw_seen_square(cub2d);
		*/
	}
}

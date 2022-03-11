/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_offset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 01:23:17 by laube             #+#    #+#             */
/*   Updated: 2022/03/11 01:25:38 by laube            ###   ########.fr       */
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

#include "cub3d.h"
#include "raycasting.h"

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

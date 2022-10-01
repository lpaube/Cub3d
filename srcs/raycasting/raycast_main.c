#include "cub3d.h"
#include "raycasting.h"

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

void	out_of_bounds(t_cub2d *cub2d)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIN_WIDTH)
	{
		j = 0;
		while (j < WIN_HEIGHT)
		{
			my_pixel_put(&cub2d->mlx_inst, i, j, 0x009999);
			j++;
		}
		i++;
	}
}

void	ray_cast_hit(t_cub2d *cub2d, int *hit, int x)
{
	inc_ray_len(cub2d);
	if (cub2d->raycast.map_x < 0 || cub2d->raycast.map_y < 0
		|| cub2d->raycast.map_x >= cub2d->map.map_width
		|| cub2d->raycast.map_y >= cub2d->map.map_height)
	{
		*hit = 1;
		cub2d->rays[x].height = 0;
		return ;
	}
	if (cub2d->map.map[cub2d->raycast.map_y]
		[cub2d->raycast.map_x] == '1')
	{
		*hit = 1;
		get_ray_side(cub2d, x);
		get_ray_data(cub2d, x);
	}
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
			ray_cast_hit(cub2d, &hit, x);
		}
	}
}

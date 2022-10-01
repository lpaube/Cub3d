#include "cub3d.h"
#include "raycasting.h"

void	draw_map_contour(t_cub2d *cub2d)
{
	t_rect	rect;

	rect.x = 0;
	rect.y = 0;
	rect.width = cub2d->tile_size * cub2d->map.map_width;
	rect.heigth = cub2d->tile_size * cub2d->map.map_height;
	rect.color = 0xFFFFFF;
	draw_rect(&cub2d->mlx_inst, rect);
}

t_rect	get_map_square(t_cub2d *cub2d, int i, int j)
{
	t_rect	rect;

	rect.x = cub2d->tile_size * i;
	rect.y = cub2d->tile_size * j;
	rect.width = cub2d->tile_size;
	rect.heigth = cub2d->tile_size;
	rect.color = 0x0000FF;
	return (rect);
}

void	draw_map_squares(t_cub2d *cub2d)
{
	t_rect	rect;
	int		i;
	int		j;

	j = -1;
	while (++j < cub2d->map.map_height)
	{
		i = -1;
		while (++i < cub2d->map.map_width)
		{
			rect = get_map_square(cub2d, i, j);
			if (cub2d->map.map[j][i] == '1')
				draw_rect(&cub2d->mlx_inst, rect);
			else if (cub2d->map.map[j][i] == '-')
			{
				rect.color = 0x888888;
				draw_rect(&cub2d->mlx_inst, rect);
			}
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
	while (++i <= cub2d->map.map_height)
	{
		line.x1 = 0;
		line.x2 = cub2d->tile_size * cub2d->map.map_width;
		line.y1 = cub2d->tile_size * i;
		line.y2 = cub2d->tile_size * i;
		line.color = 0x888888;
		draw_line(&cub2d->mlx_inst, line);
	}
	i = -1;
	while (++i <= cub2d->map.map_width)
	{
		line.x1 = cub2d->tile_size * i;
		line.x2 = cub2d->tile_size * i;
		line.y1 = 0;
		line.y2 = cub2d->tile_size * cub2d->map.map_height;
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

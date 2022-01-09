/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_raycasting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <laube@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 22:32:25 by laube             #+#    #+#             */
/*   Updated: 2022/01/08 19:57:32 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "raycasting.h"

void	draw_seen_square(t_cub2d *cub2d)
{
	t_rect	square;

	square.x = cub2d->raycast.map_x * TILE_SIZE + 1;
	square.y = cub2d->raycast.map_y * TILE_SIZE + 1;
	square.width = TILE_SIZE - 1;
	square.heigth = TILE_SIZE - 1;
	square.color = 0xFF0000;
	draw_rect(&cub2d->mlx_inst, square);
}

void	draw_direction(t_cub2d *cub2d)
{
	t_line	line;
	int		tmp_x;
	int		tmp_y;

	line.x1 = cub2d->player.circle.mid_x;
	line.y1 = cub2d->player.circle.mid_y;
	line.x2 = cub2d->player.circle.mid_x + cub2d->player.dir_x * TILE_SIZE * 2;
	line.y2 = cub2d->player.circle.mid_y + cub2d->player.dir_y * TILE_SIZE * 2;
	line.color = 0xFF00FF;
	draw_line(&cub2d->mlx_inst, line);
	tmp_x = line.x2;
	tmp_y = line.y2;
	line.x1 = tmp_x + cub2d->player.plane_x * TILE_SIZE * 2;
	line.y1 = tmp_y + cub2d->player.plane_y * TILE_SIZE * 2;
	line.x2 = tmp_x - cub2d->player.plane_x * TILE_SIZE * 2;
	line.y2 = tmp_y - cub2d->player.plane_y * TILE_SIZE * 2;
	line.color = 0x00FFFF;
	draw_line(&cub2d->mlx_inst, line);
}

void	draw_rays(t_cub2d *cub2d, int x)
{
	t_line	line;

	line.x1 = cub2d->player.circle.mid_x;
	line.y1 = cub2d->player.circle.mid_y;
	line.x2 = cub2d->player.circle.mid_x
		+ (cub2d->rays[x].len * cub2d->raycast.ray_dir_x);
	line.y2 = cub2d->player.circle.mid_y
		+ (cub2d->rays[x].len * cub2d->raycast.ray_dir_y);
	line.color = 0xFFFFFF;
	draw_line(&cub2d->mlx_inst, line);
}

void	draw_player(t_mlx *mlx_inst, t_player player)
{
	draw_circle(mlx_inst, player.circle);
}

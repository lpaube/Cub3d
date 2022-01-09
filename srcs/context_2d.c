/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context_2d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 19:15:44 by laube             #+#    #+#             */
/*   Updated: 2022/01/08 23:11:10 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "raycasting.h"

double	deg_to_rad(int deg)
{
	return (deg * (M_PI / 180));
}

void	update_vectors(t_cub2d *cub2d, t_player *player)
{
	player->plane_x = tan(deg_to_rad(player->fov) / 2)
		* cos(deg_to_rad(player->angle - 90));
	player->plane_y = tan(deg_to_rad(player->fov) / 2)
		* -sin(deg_to_rad(player->angle - 90));
	player->dir_x = 1 * cos(deg_to_rad(player->angle));
	player->dir_y = -(1 * sin(deg_to_rad(player->angle)));
	player->tile_x = player->circle.mid_x / cub2d->tile_size;
	player->tile_y = player->circle.mid_y / cub2d->tile_size;
}

void	put_diagnostics(t_cub2d *cub2d)
{
	char		buf[100];
	t_mlx		m;
	t_player	p;

	m = cub2d->mlx_inst;
	p = cub2d->player;
	mlx_string_put(cub2d->mlx_inst.mlx, cub2d->mlx_inst.win,
		500, 160, 0xFF0000, "Dir angle:");
	mlx_string_put(cub2d->mlx_inst.mlx, cub2d->mlx_inst.win,
		500, 180, 0xFF0000, "Dir X [cos(Dir angle)]:");
	mlx_string_put(cub2d->mlx_inst.mlx, cub2d->mlx_inst.win,
		500, 200, 0xFF0000, "Dir Y [-sin(Dir angle)]:");
	mlx_string_put(m.mlx, m.win, 500, 240, 0xFFFF00, "Cam angle:");
	mlx_string_put(m.mlx, m.win, 500, 260, 0xFFFF00, "FOV (deg)");
	mlx_string_put(m.mlx, m.win, 500, 280, 0xFFFF00, "Plane x:");
	mlx_string_put(m.mlx, m.win, 500, 300, 0xFFFF00, "Plane y:");
	mlx_string_put(m.mlx, m.win, 500, 340, 0x00FFFF, "Tile x:");
	mlx_string_put(m.mlx, m.win, 500, 360, 0x00FFFF, "Tile y:");
	mlx_string_put(m.mlx, m.win, 650, 160, 0xFF0000, ft_itoa(p.angle));
	mlx_string_put(m.mlx, m.win, 650, 180, 0xFF0000, gcvt(p.dir_x, 5, buf));
	mlx_string_put(m.mlx, m.win, 650, 200, 0xFF0000, gcvt(p.dir_y, 5, buf));
	mlx_string_put(m.mlx, m.win, 650, 240, 0xFFFF00, ft_itoa(p.angle - 90));
	mlx_string_put(m.mlx, m.win, 650, 260, 0xFFFF00, ft_itoa(p.fov));
	mlx_string_put(m.mlx, m.win, 650, 280, 0xFFFF00, gcvt(p.plane_x, 5, buf));
	mlx_string_put(m.mlx, m.win, 650, 300, 0xFFFF00, gcvt(p.plane_y, 5, buf));
	mlx_string_put(m.mlx, m.win, 650, 340, 0x00FFFF, ft_itoa(p.tile_x));
	mlx_string_put(m.mlx, m.win, 650, 360, 0x00FFFF, ft_itoa(p.tile_y));
}

void	game_loop_2d(t_cub2d *cub2d)
{
	printf("hello0\n");
	draw_map(cub2d);
	printf("hello1\n");
	draw_player(&cub2d->mlx_inst, cub2d->player);
	printf("hello2\n");
	ray_cast(cub2d);
	printf("hello3\n");
	draw_direction(cub2d);
	printf("hello4\n");
	mlx_put_image_to_window(cub2d->mlx_inst.mlx, cub2d->mlx_inst.win,
		cub2d->mlx_inst.img, 0, 0);
	printf("hello5\n");
	put_diagnostics(cub2d);
}

int	set_tile_size(t_mlx mlx_inst)
{
	// Add something here..
	cub2d.mlx_inst.game_width / map_width;
}

void	context_2d(void)
{
	t_cub2d	cub2d;

	cub2d.mlx_inst = mlx_inst_init(&cub2d);
	printf("test1\n");
	cub2d.tile_size = set_tile_size(cub2d.mlx_inst);
	printf("test2\n");
	cub2d.player = init_player(&cub2d);
	printf("test3\n");
	game_loop_2d(&cub2d);
	printf("test4\n");
	hook_handler(&cub2d);
	mlx_loop(cub2d.mlx_inst.mlx);
}

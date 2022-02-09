/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_context.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 19:15:44 by laube             #+#    #+#             */
/*   Updated: 2022/02/09 16:58:12 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "raycasting.h"
#include "graphics.h"

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
		cub2d->mlx_inst.game_width + 20, 60, 0xFF0000, "Dir angle:");
	mlx_string_put(cub2d->mlx_inst.mlx, cub2d->mlx_inst.win,
		cub2d->mlx_inst.game_width + 20, 80, 0xFF0000, "Dir X:");
	mlx_string_put(cub2d->mlx_inst.mlx, cub2d->mlx_inst.win,
		cub2d->mlx_inst.game_width + 20, 100, 0xFF0000, "Dir Y:");
	mlx_string_put(m.mlx, m.win, cub2d->mlx_inst.game_width + 20, 140, 0xFFFF00, "Cam angle:");
	mlx_string_put(m.mlx, m.win, cub2d->mlx_inst.game_width + 20, 160, 0xFFFF00, "FOV (deg)");
	mlx_string_put(m.mlx, m.win, cub2d->mlx_inst.game_width + 20, 180, 0xFFFF00, "Plane x:");
	mlx_string_put(m.mlx, m.win, cub2d->mlx_inst.game_width + 20, 200, 0xFFFF00, "Plane y:");
	mlx_string_put(m.mlx, m.win, cub2d->mlx_inst.game_width + 20, 240, 0x00FFFF, "Tile x:");
	mlx_string_put(m.mlx, m.win, cub2d->mlx_inst.game_width + 20, 260, 0x00FFFF, "Tile y:");
	mlx_string_put(m.mlx, m.win, cub2d->mlx_inst.game_width + 20, 300, 0xFF00FF, "Mouse x:");
	mlx_string_put(m.mlx, m.win, cub2d->mlx_inst.game_width + 20, 320, 0xFF00FF, "Mouse y:");
	mlx_string_put(m.mlx, m.win, cub2d->mlx_inst.game_width + 100, 60, 0xFF0000, ft_itoa(p.angle));
	mlx_string_put(m.mlx, m.win, cub2d->mlx_inst.game_width + 100, 80, 0xFF0000, gcvt(p.dir_x, 5, buf));
	mlx_string_put(m.mlx, m.win, cub2d->mlx_inst.game_width + 100, 100, 0xFF0000, gcvt(p.dir_y, 5, buf));
	mlx_string_put(m.mlx, m.win, cub2d->mlx_inst.game_width + 100, 140, 0xFFFF00, ft_itoa(p.angle - 90));
	mlx_string_put(m.mlx, m.win, cub2d->mlx_inst.game_width + 100, 160, 0xFFFF00, ft_itoa(p.fov));
	mlx_string_put(m.mlx, m.win, cub2d->mlx_inst.game_width + 100, 180, 0xFFFF00, gcvt(p.plane_x, 5, buf));
	mlx_string_put(m.mlx, m.win, cub2d->mlx_inst.game_width + 100, 200, 0xFFFF00, gcvt(p.plane_y, 5, buf));
	mlx_string_put(m.mlx, m.win, cub2d->mlx_inst.game_width + 100, 240, 0x00FFFF, ft_itoa(p.tile_x));
	mlx_string_put(m.mlx, m.win, cub2d->mlx_inst.game_width + 100, 260, 0x00FFFF, ft_itoa(p.tile_y));
	mlx_string_put(m.mlx, m.win, cub2d->mlx_inst.game_width + 100, 300, 0x000000, ft_itoa(cub2d->prev_mouse_x));
	mlx_string_put(m.mlx, m.win, cub2d->mlx_inst.game_width + 100, 320, 0x000000, ft_itoa(cub2d->prev_mouse_y));
	mlx_string_put(m.mlx, m.win, cub2d->mlx_inst.game_width + 100, 300, 0xFF00FF, ft_itoa(cub2d->mouse_x));
	mlx_string_put(m.mlx, m.win, cub2d->mlx_inst.game_width + 100, 320, 0xFF00FF, ft_itoa(cub2d->mouse_y));
	cub2d->prev_mouse_x = cub2d->mouse_x;
	cub2d->prev_mouse_y = cub2d->mouse_y;
}

void	game_loop_2d(t_cub2d *cub2d)
{
	if (cub2d->debug == 2)
	{
		draw_map(cub2d);
		draw_player(&cub2d->mlx_inst, cub2d->player);
	}
	ray_cast(cub2d);
	if (cub2d->debug == 2)
	{
		draw_direction(cub2d);
		mlx_put_image_to_window(cub2d->mlx_inst.mlx, cub2d->mlx_inst.win,
				cub2d->mlx_inst.img, 0, 0);
		put_diagnostics(cub2d);
	}
}

void	game_context(int debug, t_map *map)
{
	t_cub2d	cub2d;
	t_graph	*screen;
	t_mlx	mlx_inst;

	screen = malloc(sizeof(t_graph));
	mlx_inst = mlx_inst_init();
	cub2d.map = *map;
	cub2d.debug = debug;
	cub2d.mlx_inst = mlx_inst;
	cub2d.tile_size = 20;
	cub2d.player = init_player(&cub2d);
	cub2d.mouse_x = 0;
	cub2d.mouse_y = 0;
	background_converter(map, screen);
	if (textures_converter(screen, &mlx_inst, map->texture) == false)
		return;//BESOIN DE CREE UN MSG D'ERREUR ET D'EXIT ICI
	cub2d.screen = screen;
	game_loop_2d(&cub2d);
	if (debug != 2)
		show_3d(&cub2d);
	hook_handler(&cub2d);
	mlx_loop(cub2d.mlx_inst.mlx);
}

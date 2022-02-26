/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_context.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 19:15:44 by laube             #+#    #+#             */
/*   Updated: 2022/02/26 14:21:38 by laube            ###   ########.fr       */
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

void	game_loop(t_cub2d *cub2d)
{
	ray_cast(cub2d);
	show_3d(cub2d);
	free(cub2d->rays);
}

void	game_context(int debug, t_map *map)
{
	t_cub2d	cub2d;
	t_graph	screen;
	t_mlx	mlx_inst;

	mlx_inst = mlx_inst_init();
	cub2d.map = *map;
	cub2d.debug = debug;
	cub2d.mlx_inst = mlx_inst;
	cub2d.tile_size = 20;
	cub2d.player = init_player(&cub2d);
	cub2d.mouse_x = 0;
	cub2d.mouse_y = 0;
	screen = background_converter(map);
	if (textures_converter(&screen, &mlx_inst, map->texture) == false)
		return;//BESOIN DE CREE UN MSG D'ERREUR ET D'EXIT ICI
	cub2d.screen = &screen;
	game_loop(&cub2d);
	hook_handler(&cub2d);
	mlx_loop(cub2d.mlx_inst.mlx);
}

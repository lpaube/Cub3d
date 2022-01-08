/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_2d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <laube@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 19:15:44 by laube             #+#    #+#             */
/*   Updated: 2022/01/07 22:56:01 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "raycasting.h"

double  deg_to_rad(int deg)
{
    return deg * (M_PI / 180);
}

void    update_vectors(t_player *player)
{
    player->plane_x = tan(deg_to_rad(player->fov) / 2) * cos(deg_to_rad(player->angle - 90));
    player->plane_y = tan(deg_to_rad(player->fov) / 2) * -sin(deg_to_rad(player->angle - 90));
    player->dir_x = 1 * cos(deg_to_rad(player->angle));
    player->dir_y = -(1 * sin(deg_to_rad(player->angle)));

    player->tile_x = player->circle.mid_x / TILE_SIZE;
    player->tile_y = player->circle.mid_y / TILE_SIZE;
}

void    put_diagnostics(t_cub2d *cub2d)
{
    // NOT ALLOWED: TO BE REMOVED FOR CORRECTION
    char buf[100];

    mlx_string_put(cub2d->mlx_inst.mlx, cub2d->mlx_inst.win, 500, 160, 0xFF0000, "Dir angle:");
    mlx_string_put(cub2d->mlx_inst.mlx, cub2d->mlx_inst.win, 500, 180, 0xFF0000, "Dir X [cos(Dir angle)]:");
    mlx_string_put(cub2d->mlx_inst.mlx, cub2d->mlx_inst.win, 500, 200, 0xFF0000, "Dir Y [-sin(Dir angle)]:");

    mlx_string_put(cub2d->mlx_inst.mlx, cub2d->mlx_inst.win, 500, 240, 0xFFFF00, "Cam angle:");
    mlx_string_put(cub2d->mlx_inst.mlx, cub2d->mlx_inst.win, 500, 260, 0xFFFF00, "FOV (deg)");
    mlx_string_put(cub2d->mlx_inst.mlx, cub2d->mlx_inst.win, 500, 280, 0xFFFF00, "Plane x:");
    mlx_string_put(cub2d->mlx_inst.mlx, cub2d->mlx_inst.win, 500, 300, 0xFFFF00, "Plane y:");

    mlx_string_put(cub2d->mlx_inst.mlx, cub2d->mlx_inst.win, 650, 160, 0xFF0000, ft_itoa(cub2d->player.angle));
    mlx_string_put(cub2d->mlx_inst.mlx, cub2d->mlx_inst.win, 650, 180, 0xFF0000, gcvt(cub2d->player.dir_x, 5, buf));
    mlx_string_put(cub2d->mlx_inst.mlx, cub2d->mlx_inst.win, 650, 200, 0xFF0000, gcvt(cub2d->player.dir_y, 5, buf));

    mlx_string_put(cub2d->mlx_inst.mlx, cub2d->mlx_inst.win, 650, 240, 0xFFFF00, ft_itoa(cub2d->player.angle - 90));
    mlx_string_put(cub2d->mlx_inst.mlx, cub2d->mlx_inst.win, 650, 260, 0xFFFF00, ft_itoa(cub2d->player.fov));
    mlx_string_put(cub2d->mlx_inst.mlx, cub2d->mlx_inst.win, 650, 280, 0xFFFF00, gcvt(cub2d->player.plane_x, 5, buf));
    mlx_string_put(cub2d->mlx_inst.mlx, cub2d->mlx_inst.win, 650, 300, 0xFFFF00, gcvt(cub2d->player.plane_y, 5, buf));
}

void    game_loop_2d(t_cub2d *cub2d)
{
    draw_cub2d(cub2d, &cub2d->mlx_inst);
    ray_cast(cub2d, &cub2d->player);
    draw_direction(cub2d);
    mlx_put_image_to_window(cub2d->mlx_inst.mlx, cub2d->mlx_inst.win, cub2d->mlx_inst.img, 0, 0);
    put_diagnostics(cub2d);
}

void handle_2d(void)
{
    t_cub2d cub2d;

    cub2d.mlx_inst = mlx_inst_init(&cub2d);
    game_loop_2d(&cub2d);
    hook_handler(&cub2d);
    mlx_loop(cub2d.mlx_inst.mlx);
}

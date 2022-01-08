/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_2d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <laube@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 19:15:44 by laube             #+#    #+#             */
/*   Updated: 2022/01/07 22:34:28 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "raycasting.h"

// MAP STRUCTURE WILL BE PROVIDED BY MAFORTIN
char map[24][24] = {
    {'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},
    {'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
    {'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
    {'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
    {'1','0','0','0','0','0','1','1','1','1','1','0','0','0','0','1','0','1','0','1','0','0','0','1'},
    {'1','0','0','0','0','0','1','0','0','0','1','0','0','0','0','0','0','0','0','0','0','0','0','1'},
    {'1','0','0','0','0','0','1','0','0','0','1','0','0','0','0','1','0','0','0','1','0','0','0','1'},
    {'1','0','0','0','0','0','1','0','0','0','1','0','0','0','0','0','0','0','0','0','0','0','0','1'},
    {'1','0','0','0','0','0','1','1','0','1','1','0','0','0','0','1','0','1','0','1','0','0','0','1'},
    {'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
    {'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
    {'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','E','1'},
    {'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
    {'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
    {'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
    {'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
    {'1','0','0','1','1','1','1','1','1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
    {'1','0','0','1','0','0','0','0','1','0','0','0','1','0','0','0','0','0','0','0','0','0','0','1'},
    {'1','0','0','0','0','0','1','0','1','0','0','1','0','0','0','0','0','0','0','0','0','0','0','1'},
    {'1','0','0','1','0','0','0','0','1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
    {'1','0','0','1','1','1','1','1','1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
    {'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
    {'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
    {'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'}
};

// Will be included in map struct

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

void ray_cast(t_cub2d *cub2d, t_player *player)
{
    int hit;
    int x;
    double  camera_x;

    x = -1;
    cub2d->rays = malloc(sizeof(t_rays) * WIN_WIDTH);
    //while (++x < WIN_WIDTH)
    for (x = 0; x < WIN_WIDTH; x += 1)
    {
        camera_x = 2 * x / ((double)WIN_WIDTH - 1) - 1;
        cub2d->raycast.ray_dir_x = player->dir_x + player->plane_x * camera_x;
        cub2d->raycast.ray_dir_y = player->dir_y + player->plane_y * camera_x;

        cub2d->raycast.map_x = player->tile_x;
        cub2d->raycast.map_y = player->tile_y;
        cub2d->raycast.delta_x = fabs(1 / cub2d->raycast.ray_dir_x);
        cub2d->raycast.delta_y = fabs(1 / cub2d->raycast.ray_dir_y);
        hit = 0;
        if (cub2d->raycast.ray_dir_x < 0)
        {
            cub2d->raycast.step_x = -1;
            cub2d->raycast.dist_x = (player->circle.mid_x - (cub2d->raycast.map_x * TILE_SIZE)) * cub2d->raycast.delta_x;
        }
        else
        {
            cub2d->raycast.step_x = 1;
            cub2d->raycast.dist_x = ((cub2d->raycast.map_x + 1) * TILE_SIZE - player->circle.mid_x) * cub2d->raycast.delta_x;
        }
        if (cub2d->raycast.ray_dir_y < 0)
        {
            cub2d->raycast.step_y = -1;
            cub2d->raycast.dist_y = (player->circle.mid_y - (cub2d->raycast.map_y * TILE_SIZE)) * cub2d->raycast.delta_y;
        }
        else
        {
            cub2d->raycast.step_y = 1;
            cub2d->raycast.dist_y = ((player->tile_y + 1) * TILE_SIZE - player->circle.mid_y) * cub2d->raycast.delta_y;
        }
        while (hit == 0)
        {
            if (cub2d->raycast.dist_x < cub2d->raycast.dist_y)
            {
                cub2d->raycast.dist_x += cub2d->raycast.delta_x * TILE_SIZE;
                cub2d->raycast.map_x += cub2d->raycast.step_x;
                cub2d->raycast.side = 0;
            }
            else
            {
                cub2d->raycast.dist_y += cub2d->raycast.delta_y * TILE_SIZE;
                cub2d->raycast.map_y += cub2d->raycast.step_y;
                cub2d->raycast.side = 1;
            }
            if (map[cub2d->raycast.map_y][cub2d->raycast.map_x] == '1')
            {
                hit = 1;
                if (cub2d->raycast.side == 0)
                {
                    cub2d->raycast.dist_x -= cub2d->raycast.delta_x * TILE_SIZE;
                    cub2d->raycast.len = cub2d->raycast.dist_x;
                    cub2d->rays[x].len = cub2d->raycast.dist_x;
                    if (cub2d->raycast.step_x == 1)
                        cub2d->rays[x].face = 'W';
                    else
                        cub2d->rays[x].face = 'E';
                }
                else if (cub2d->raycast.side == 1)
                {
                    cub2d->raycast.dist_y -= cub2d->raycast.delta_y * TILE_SIZE;
                    cub2d->raycast.len = cub2d->raycast.dist_y;
                    cub2d->rays[x].len = cub2d->raycast.dist_y;
                    if (cub2d->raycast.step_y == 1)
                        cub2d->rays[x].face = 'N';
                    else
                        cub2d->rays[x].face = 'S';
                }
            }
        }
        if ((x + 1) % (WIN_WIDTH / 10) == 0 || x == 0 || x == WIN_WIDTH - 1)
        {
            draw_rays(cub2d);
        }
        t_rect square = {.x = (cub2d->raycast.map_x * TILE_SIZE) + 1, .y = cub2d->raycast.map_y * TILE_SIZE + 1, .width = TILE_SIZE - 1, .heigth = TILE_SIZE - 1, .color = 0xFF0000};
        draw_rect(&cub2d->mlx_inst, square);
    }
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

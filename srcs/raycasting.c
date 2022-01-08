/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <laube@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 22:39:46 by laube             #+#    #+#             */
/*   Updated: 2022/01/07 23:02:57 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "raycasting.h"

void ray_cast(t_cub2d *cub2d, t_player *player)
{
    int hit;
    int x;
    double  camera_x;

    x = -1;
    cub2d->rays = malloc(sizeof(t_rays) * WIN_WIDTH);
    while (++x < WIN_WIDTH)
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

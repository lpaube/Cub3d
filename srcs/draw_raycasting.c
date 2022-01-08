/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_raycasting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <laube@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 22:32:25 by laube             #+#    #+#             */
/*   Updated: 2022/01/07 22:34:36 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "raycasting.h"

void    draw_direction(t_cub2d *cub2d)
{
    t_line  line;
    int tmp_x;
    int tmp_y;

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

void    draw_rays(t_cub2d *cub2d)
{
    t_line  line;

    line.x1 = cub2d->player.circle.mid_x;
    line.y1 = cub2d->player.circle.mid_y;
    line.x2 = cub2d->player.circle.mid_x + (cub2d->raycast.len * cub2d->raycast.ray_dir_x);
    line.y2 = cub2d->player.circle.mid_y + (cub2d->raycast.len * cub2d->raycast.ray_dir_y);
    line.color = 0xFFFFFF;
    draw_line(&cub2d->mlx_inst, line);
}

void    draw_player(t_mlx *mlx_inst, t_player player)
{
    draw_circle(mlx_inst, player.circle);
}

void	draw_cub2d(t_cub2d *cub2d, t_mlx *mlx_inst)
{
    t_rect	rect;
    t_line      line;
    int i;
    int j;

    // Map background
    rect.x = 0;
    rect.y = 0;
    rect.width = TILE_SIZE * map_width;
    rect.heigth = TILE_SIZE * map_height;
    rect.color = 0xFFFFFF;
    draw_rect(mlx_inst, rect);

    // Reading map; creating blocks and player
    j = -1;
    while (++j < map_height)
    {
        i = -1;
        while (++i < map_width)
        {
            rect.x = TILE_SIZE * i;
            rect.y = TILE_SIZE * j;
            rect.width = TILE_SIZE;
            rect.heigth = TILE_SIZE;
            if (map[j][i] == '1')
            {
                rect.color = 0x0000FF;
                draw_rect(mlx_inst, rect);
            }
            // else if (map[j][i] == 'N' || map[j][i] == 'S' || 
            //         map[j][i] == 'E' || map[j][i] == 'O')
            // {
            // 	continue ;
            // }
            else
            {
                rect.color = 0x000000;
                draw_rect(mlx_inst, rect);
            }
        }
    }

    // Horizontal lines
    i = -1;
    while (++i <= map_height)
    {
        line.x1 = 0;
        line.x2 = TILE_SIZE * map_width;
        line.y1 = TILE_SIZE * i;
        line.y2 = TILE_SIZE * i;
        line.color = 0xAAAAAA;
        draw_line(mlx_inst, line);
    }

    // Vertical lines
    i = -1;
    while (++i <= map_width)
    {
        line.x1 = TILE_SIZE * i;
        line.x2 = TILE_SIZE * i;
        line.y1 = 0;
        line.y2 = TILE_SIZE * map_height;
        line.color = 0x888888;
        draw_line(mlx_inst, line);
    }

    draw_player(mlx_inst, cub2d->player);
}


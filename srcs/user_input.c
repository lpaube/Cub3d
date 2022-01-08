/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <laube@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 21:49:30 by laube             #+#    #+#             */
/*   Updated: 2022/01/07 21:50:56 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "raycasting.h"

int has_collision(t_cub2d *cub2d, int mvmt)
{
    int newpos_x;
    int newpos_y;

    newpos_x = cub2d->player.circle.mid_x + mvmt * cub2d->player.dir_x;
    newpos_y = cub2d->player.circle.mid_y + mvmt * cub2d->player.dir_y;
    if (map[newpos_y / TILE_SIZE][newpos_x / TILE_SIZE] != '1')
        return (0);
    return (1);
}

void    player_mvmt(int keycode, t_cub2d *cub2d)
{
    if (keycode == MAIN_W)
    {
        if (!has_collision(cub2d, 2))
        {
            cub2d->player.circle.mid_x += 2 * cub2d->player.dir_x;
            cub2d->player.circle.mid_y += 2 * cub2d->player.dir_y;
        }
    }
    if (keycode == MAIN_S)
    {
        if (!has_collision(cub2d, -2))
        {
            cub2d->player.circle.mid_x -= 2 * cub2d->player.dir_x;
            cub2d->player.circle.mid_y -= 2 * cub2d->player.dir_y;
        }
    }
    if (keycode == MAIN_A)
    {
        cub2d->player.angle += 2;
    }
    if (keycode == MAIN_D)
    {
        cub2d->player.angle -= 2;
    }
    if (cub2d->player.angle >= 360)
    {
        cub2d->player.angle = 0;
    }
    if (cub2d->player.angle < 0)
    {
        cub2d->player.angle = 359;
    }
}

int key_press(int keycode, t_cub2d *cub2d)
{
    if (keycode == MAIN_ESC)
        exit(0);
    else if (keycode == MAIN_W || keycode == MAIN_A || keycode == MAIN_S || keycode == MAIN_D)
    {
        player_mvmt(keycode, cub2d);
        update_vectors(&cub2d->player);
    }
    game_loop_2d(cub2d);
    return (0);
}

int click_close(void* param)
{
    (void)param;
    exit(0);
}

int hook_handler(t_cub2d *cub2d)
{
    mlx_hook(cub2d->mlx_inst.win, 2, 1L<<0, key_press, cub2d);
    mlx_hook(cub2d->mlx_inst.win, 17, 0, click_close, cub2d);
    return (0);
}

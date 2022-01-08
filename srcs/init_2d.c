/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_2d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <laube@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 21:13:24 by laube             #+#    #+#             */
/*   Updated: 2022/01/07 21:43:06 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "raycasting.h"

int map_width = 24;
int map_height = 24;
int player_x = 22;
int player_y = 11;
char    player_orien = 'W';

t_player init_player(void) //Will later take map struct as argument
{
    t_player    player;
    t_circle      circle;

    circle.mid_x = (TILE_SIZE * player_x) + (TILE_SIZE / 2);
    circle.mid_y = (TILE_SIZE * player_y) + (TILE_SIZE / 2);
    circle.radius = TILE_SIZE / 4;
    circle.color = 0x00FF00;
    player.circle = circle;
    player.orien = player_orien;
    player.fov = 66;
    init_vectors(&player);
    return (player);
}

t_mlx mlx_inst_init(t_cub2d *cub2d) // Will later take the map as argument
{
    t_mlx mlx_inst;

    mlx_inst.mlx = mlx_init();
    mlx_inst.win = mlx_new_window(mlx_inst.mlx, WIN_WIDTH, WIN_HEIGTH, "Cub3d");
    mlx_inst.img = mlx_new_image(mlx_inst.mlx, WIN_WIDTH, WIN_HEIGTH);
    mlx_inst.addr = mlx_get_data_addr(mlx_inst.img, &mlx_inst.bits_per_pixel,
            &mlx_inst.line_len, &mlx_inst.endian);
    cub2d->player = init_player();// will send the map with the player coordinates later
    return (mlx_inst);
}

void    init_vectors(t_player *player)
{
    if (player->orien == 'N')
    {
        player->angle = 90;
    }
    if (player->orien == 'S')
    {
        player->angle = 270;
    }
    if (player->orien == 'E')
    {
        player->angle = 0;
    }
    if (player->orien == 'W')
    {
        player->angle = 180;
    }
    update_vectors(player);
}


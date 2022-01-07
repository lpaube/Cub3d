/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_2d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <laube@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 19:15:44 by laube             #+#    #+#             */
/*   Updated: 2022/01/06 23:55:09 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "mlx.h"
#include "cub3d.h"
#include "../libft/libft.h"

#define TILE_SIZE 20
#define WIN_WIDTH 1000
#define WIN_HEIGTH 600

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
    {'1','0','0','1','0','0','0','0','1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
    {'1','0','0','0','0','0','1','0','1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
    {'1','0','0','1','0','0','0','0','1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
    {'1','0','0','1','1','1','1','1','1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
    {'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
    {'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
    {'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'}
};

int map_width = 24;
int map_height = 24;
int player_x = 22;
int player_y = 11;
char    player_orien = 'W';

double planeX = 0;
double planeY = 0.66;
double cameraX;
double rayDirX;
double rayDirY;

double  deg_to_rad(int deg)
{
    return deg * (M_PI / 180);
}

void    update_vectors(t_player *player)
{
    double tmpPlaneX = planeX;
    player->dir_x = 1 * cos(deg_to_rad(player->angle));
    player->dir_y = -(1 * sin(deg_to_rad(player->angle)));

    player->tile_x = player->circle.mid_x / TILE_SIZE;
    player->tile_y = player->circle.mid_y / TILE_SIZE;
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

t_player init_player(t_mlx *mlx_inst) //Will later take map struct as argument
{
    t_player    player;
    t_circle      circle;

    (void)mlx_inst;
    circle.mid_x = (TILE_SIZE * player_x) + (TILE_SIZE / 2);
    circle.mid_y = (TILE_SIZE * player_y) + (TILE_SIZE / 2);
    circle.radius = TILE_SIZE / 4;
    circle.color = 0x00FF00;
    player.circle = circle;
    player.orien = player_orien;
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
    cub2d->player = init_player(&mlx_inst);// will send the map with the player coordinates later
    return (mlx_inst);
}

void	my_pixel_put(t_mlx *mlx_inst, int x, int y, int color)
{
    char *pxl;

    //printf("x: %d | y: %d\n", x, y);
    if (y >= WIN_HEIGTH || y < 0 || x >= WIN_WIDTH || x < 0)
        return ;
    pxl = mlx_inst->addr + (y * mlx_inst->line_len) + (x * (mlx_inst->bits_per_pixel / 8));
    *(unsigned int*)pxl = color;
}

void draw_rect(t_mlx *mlx_inst, t_rect rect)
{
    int	j;
    int	i;

    j = -1;
    while (++j < rect.heigth)
    {
        i = -1;
        while (++i < rect.width)
        {
            if ((rect.x + i < WIN_WIDTH && rect.x + i >= 0) && (rect.y + j < WIN_HEIGTH && rect.y + j >= 0))
                my_pixel_put(mlx_inst, rect.x + i, rect.y + j, rect.color);
        }
    }
}

// Using DDA algorithm
void draw_line(t_mlx *mlx_inst, t_line line)
{
    int	    i;
    int	    steps;
    float   xinc;
    float   yinc;

    steps = abs(line.x2 - line.x1);
    if (abs(line.y2 - line.y1) > abs(line.x2 - line.x1))
        steps = abs(line.y2 - line.y1);
    xinc = (line.x2 - line.x1) / (float)steps;
    yinc = (line.y2 - line.y1) / (float)steps;
    i = -1;
    while (++i < steps)
    {
        my_pixel_put(mlx_inst, round(line.x1 + (i * xinc)), 
                round(line.y1 + (i * yinc)), line.color);
    }
}

void draw_circle(t_mlx *mlx_inst, t_circle circle)
{
    float	x;
    float	y;
    int		j;

    x = -1;
    while (++x < circle.radius)
    {
        y = sqrt(pow(circle.radius, 2) - pow(x, 2));
        j = y + 1;
        while (--j >= -y)
        {
            my_pixel_put(mlx_inst, circle.mid_x + x, round(circle.mid_y) + j, circle.color);
            my_pixel_put(mlx_inst, circle.mid_x - x, round(circle.mid_y) + j, circle.color);
        }
    }
}

void    draw_direction(t_cub2d *cub2d)
{
    t_line  line;

    line.x1 = cub2d->player.circle.mid_x;
    line.y1 = cub2d->player.circle.mid_y;
    line.x2 = cub2d->player.circle.mid_x + (cub2d->raycast.len * rayDirX);
    line.y2 = cub2d->player.circle.mid_y + (cub2d->raycast.len * rayDirY);
    line.color = 0xFFFFFF;
    draw_line(&cub2d->mlx_inst, line);
}

void    draw_player(t_mlx *mlx_inst, t_player player)
{
    draw_circle(mlx_inst, player.circle);
}

void ray_cast(t_cub2d *cub2d, t_player *player)
{
    int hit;
    int x;

    x = -1;
    cub2d->rays = malloc(sizeof(t_rays) * WIN_WIDTH);
    //while (++x < WIN_WIDTH)
    for (x = 0; x < WIN_WIDTH; x += WIN_WIDTH / 5)
    {
        cameraX = 2 * x / (double)WIN_WIDTH - 1;
        rayDirX = player->dir_x + planeX * cameraX;
        rayDirY = player->dir_y + planeY * cameraX;

        cub2d->raycast.map_x = player->tile_x;
        cub2d->raycast.map_y = player->tile_y;
        cub2d->raycast.delta_x = fabs(1 / rayDirX);
        cub2d->raycast.delta_y = fabs(1 / rayDirY);
        hit = 0;
        if (rayDirX < 0)
        {
            cub2d->raycast.step_x = -1;
            cub2d->raycast.dist_x = (player->circle.mid_x - (cub2d->raycast.map_x * TILE_SIZE)) * cub2d->raycast.delta_x;
        }
        else
        {
            cub2d->raycast.step_x = 1;
            cub2d->raycast.dist_x = ((cub2d->raycast.map_x + 1) * TILE_SIZE - player->circle.mid_x) * cub2d->raycast.delta_x;
        }
        if (rayDirY < 0)
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
                }
                else if (cub2d->raycast.side == 1)
                {
                    cub2d->raycast.dist_y -= cub2d->raycast.delta_y * TILE_SIZE;
                    cub2d->raycast.len = cub2d->raycast.dist_y;
                    cub2d->rays[x].len = cub2d->raycast.dist_y;
                }
            }
        }
        draw_direction(cub2d);
        t_rect square = {.x = (cub2d->raycast.map_x * TILE_SIZE) + 1, .y = cub2d->raycast.map_y * TILE_SIZE + 1, .width = TILE_SIZE - 1, .heigth = TILE_SIZE - 1, .color = 0xFF0000};
        draw_rect(&cub2d->mlx_inst, square);
        printf("dir_x: %f | dir_y: %f | planeX: %f | planeY: %f | rayDirX: %f | rayDirY: %f | cameraX: %f\n", player->dir_x, player->dir_y, planeX, planeY, rayDirX, rayDirY, cameraX);
    }
    printf("-\n");
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

void    put_diagnostics(t_cub2d *cub2d)
{
    // NOT ALLOWED: TO BE REMOVED FOR CORRECTION
    char buf[100];

    /*
    mlx_string_put(cub2d->mlx_inst.mlx, cub2d->mlx_inst.win, 500, 100, 0xFFFF00, "Delta X:");
    mlx_string_put(cub2d->mlx_inst.mlx, cub2d->mlx_inst.win, 500, 120, 0xFFFF00, "Delta Y:");
    mlx_string_put(cub2d->mlx_inst.mlx, cub2d->mlx_inst.win, 500, 140, 0xFFFF00, "Delta X (px):");
    mlx_string_put(cub2d->mlx_inst.mlx, cub2d->mlx_inst.win, 500, 160, 0xFFFF00, "Delta Y (px):");
    mlx_string_put(cub2d->mlx_inst.mlx, cub2d->mlx_inst.win, 500, 180, 0xFFFF00, "Dist X:");
    mlx_string_put(cub2d->mlx_inst.mlx, cub2d->mlx_inst.win, 500, 200, 0xFFFF00, "Dist Y:");
    mlx_string_put(cub2d->mlx_inst.mlx, cub2d->mlx_inst.win, 500, 220, 0xFFFF00, "Lenght:");
    */

    mlx_string_put(cub2d->mlx_inst.mlx, cub2d->mlx_inst.win, 500, 260, 0xFF0000, "Angle:");
    mlx_string_put(cub2d->mlx_inst.mlx, cub2d->mlx_inst.win, 500, 280, 0xFF0000, "Dir X [cos(angle)]:");
    mlx_string_put(cub2d->mlx_inst.mlx, cub2d->mlx_inst.win, 500, 300, 0xFF0000, "Dir Y [sin(angle)]:");

    /*
    mlx_string_put(cub2d->mlx_inst.mlx, cub2d->mlx_inst.win, 650, 100, 0xFFFF00, gcvt(cub2d->raycast.delta_x, 5, buf));
    mlx_string_put(cub2d->mlx_inst.mlx, cub2d->mlx_inst.win, 650, 120, 0xFFFF00, gcvt(cub2d->raycast.delta_y, 5, buf));
    mlx_string_put(cub2d->mlx_inst.mlx, cub2d->mlx_inst.win, 650, 140, 0xFFFF00, gcvt(cub2d->raycast.delta_x * TILE_SIZE, 5, buf));
    mlx_string_put(cub2d->mlx_inst.mlx, cub2d->mlx_inst.win, 650, 160, 0xFFFF00, gcvt(cub2d->raycast.delta_y * TILE_SIZE, 5, buf));
    mlx_string_put(cub2d->mlx_inst.mlx, cub2d->mlx_inst.win, 650, 180, 0xFFFF00, gcvt(cub2d->raycast.dist_x, 5, buf));
    mlx_string_put(cub2d->mlx_inst.mlx, cub2d->mlx_inst.win, 650, 200, 0xFFFF00, gcvt(cub2d->raycast.dist_y, 5, buf));
    mlx_string_put(cub2d->mlx_inst.mlx, cub2d->mlx_inst.win, 650, 220, 0xFFFF00, gcvt(cub2d->raycast.len, 5, buf));
    */

    mlx_string_put(cub2d->mlx_inst.mlx, cub2d->mlx_inst.win, 650, 260, 0xFF0000, ft_itoa(cub2d->player.angle));
    mlx_string_put(cub2d->mlx_inst.mlx, cub2d->mlx_inst.win, 650, 280, 0xFF0000, gcvt(cub2d->player.dir_x, 5, buf));
    mlx_string_put(cub2d->mlx_inst.mlx, cub2d->mlx_inst.win, 650, 300, 0xFF0000, gcvt(cub2d->player.dir_y, 5, buf));
}

void    game_loop_2d(t_cub2d *cub2d)
{
    draw_cub2d(cub2d, &cub2d->mlx_inst);
    ray_cast(cub2d, &cub2d->player);
    //draw_direction(cub2d);
    mlx_put_image_to_window(cub2d->mlx_inst.mlx, cub2d->mlx_inst.win, cub2d->mlx_inst.img, 0, 0);
    put_diagnostics(cub2d);
}

void    player_mvmt(int keycode, t_cub2d *cub2d)
{
    if (keycode == MAIN_W)
    {
        cub2d->player.circle.mid_x += 2 * cub2d->player.dir_x;
        cub2d->player.circle.mid_y += 2 * cub2d->player.dir_y;
    }
    if (keycode == MAIN_S)
    {
        cub2d->player.circle.mid_x -= 2 * cub2d->player.dir_x;
        cub2d->player.circle.mid_y -= 2 * cub2d->player.dir_y;
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

void handle_2d(void)
{
    t_cub2d cub2d;

    cub2d.mlx_inst = mlx_inst_init(&cub2d);
    game_loop_2d(&cub2d);
    hook_handler(&cub2d);
    mlx_loop(cub2d.mlx_inst.mlx);
}

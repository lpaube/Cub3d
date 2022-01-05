/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_2d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <laube@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 19:15:44 by laube             #+#    #+#             */
/*   Updated: 2022/01/03 00:22:27 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "mlx.h"
#include "cub3d.h"

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
    {'1','0','0','0','0','0','0','0','N','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
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
int player_x = 8;
int player_y = 11;
char    player_orien = 'N';

double  deg_to_rad(int deg)
{
    return deg * (M_PI / 180);
}

void    update_vectors(t_player *player)
{
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
    if (player->orien == 'O')
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

void    draw_direction(t_mlx *mlx_inst, t_player player)
{
    t_line  line;

    line.x1 = player.circle.mid_x;
    line.y1 = player.circle.mid_y;
    line.x2 = player.circle.mid_x + player.dir_x * (TILE_SIZE * 50);
    line.y2 = player.circle.mid_y + player.dir_y * (TILE_SIZE * 50);
    line.color = 0xFFFFFF;
    draw_line(mlx_inst, line);
}

void    draw_player(t_mlx *mlx_inst, t_player player)
{
    draw_direction(mlx_inst, player);
    draw_circle(mlx_inst, player.circle);
}

void ray_cast(t_cub2d *cub2d, t_player *player)
{
    double  delta_x;
    double  delta_y;
    double  side_x;
    double  side_y;
    int hit;
    int side;
    int step_x;
    int step_y;
    int map_x;
    int map_y;
    int counter = 0;

    map_x = player->tile_x;
    map_y = player->tile_y;
    printf("player->dir_x: %f\n", player->dir_x);
    delta_x = fabs(1 / player->dir_x);
    delta_y = fabs(1 / player->dir_y);
    hit = 0;
    if (player->dir_x < 0)
    {
        step_x = -1;
        side_x = (player->circle.mid_x - (map_x * TILE_SIZE)) * delta_x;
    }
    else
    {
        step_x = 1;
        side_x = ((map_x + 1) * TILE_SIZE - player->circle.mid_x) * delta_x;
    }
    if (player->dir_y < 0)
    {
        step_y = -1;
        side_y = (player->circle.mid_y - (map_y * TILE_SIZE)) * delta_y;
    }
    else
    {
        step_y = 1;
        side_y = ((player->tile_y + 1) * TILE_SIZE - player->circle.mid_y) * delta_y;
    }
    //char test = 'c';
    while (hit == 0)
    {
        //scanf("%c", &test);
        if (side_x < side_y)
        {
            side_x += delta_x * TILE_SIZE;
            map_x += step_x;
            side = 0;
        }
        else
        {
            side_y += delta_y * TILE_SIZE;
            map_y += step_y;
            side = 1;
        }
        if (map[map_y][map_x] == '1')
        {
            //printf("map_x: %d | map_y: %d\n", map_x, map_y);
            t_rect square = {.x = map_x * TILE_SIZE, .y = map_y * TILE_SIZE, .width = TILE_SIZE, .heigth = TILE_SIZE, .color = 0xFF0000};
            draw_rect(&cub2d->mlx_inst, square);
            hit = 1;
        }
        //printf("count: %d | side_x: %f | side_y: %f | delta_x: %f | delta_y: %f | step_x: %d\n", counter, side_x, side_y, delta_x, delta_y, step_x);
        counter++;
    }
    (void)side;
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
    ray_cast(cub2d, &cub2d->player);
}

void    draw_game_2d(t_cub2d *cub2d)
{
    draw_cub2d(cub2d, &cub2d->mlx_inst);
    mlx_put_image_to_window(cub2d->mlx_inst.mlx, cub2d->mlx_inst.win, cub2d->mlx_inst.img, 0, 0);
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
        //ray_cast(cub2d, &cub2d->player);
    }
    draw_game_2d(cub2d);
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
    draw_game_2d(&cub2d);
    hook_handler(&cub2d);
    mlx_loop(cub2d.mlx_inst.mlx);
}

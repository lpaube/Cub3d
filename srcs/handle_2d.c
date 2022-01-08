/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_2d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <laube@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 19:15:44 by laube             #+#    #+#             */
/*   Updated: 2022/01/07 21:31:10 by laube            ###   ########.fr       */
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

void	my_pixel_put(t_mlx *mlx_inst, int x, int y, int color)
{
    char *pxl;

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

void handle_2d(void)
{
    t_cub2d cub2d;

    cub2d.mlx_inst = mlx_inst_init(&cub2d);
    game_loop_2d(&cub2d);
    hook_handler(&cub2d);
    mlx_loop(cub2d.mlx_inst.mlx);
}

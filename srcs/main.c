/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <marvin@42quebec.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:30:50 by laube             #+#    #+#             */
/*   Updated: 2021/12/10 11:59:15 by laube            ###   ########.fr       */
/*   Updated: 2021/12/07 18:59:55 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "mlx.h"
#include "cub3d.h"

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

t_mlx mlx_inst_init(void)
{
	t_mlx mlx_inst;

	mlx_inst.mlx = mlx_init();
	mlx_inst.win = mlx_new_window(mlx_inst.mlx, WIN_WIDTH, WIN_HEIGTH, "Cub3d");
	mlx_inst.img = mlx_new_image(mlx_inst.mlx, WIN_WIDTH, WIN_HEIGTH);
	mlx_inst.addr = mlx_get_data_addr(mlx_inst.img, &mlx_inst.bits_per_pixel,
			&mlx_inst.line_len, &mlx_inst.endian);
	return (mlx_inst);
}

void	my_pixel_put(t_mlx *mlx_inst, int x, int y, int color)
{
	char *pxl;

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
	int		i;
	int		steps;
	float	xinc;
	float	yinc;

	steps = abs(line.x2 - line.x1);
	if (abs(line.y2 - line.y1) > abs(line.x2 - line.x1))
		steps = abs(line.y2 - line.y1);
	xinc = (line.x2 - line.x1) / steps;
	yinc = (line.y2 - line.y1) / steps;
	i = -1;
	while (++i < steps)
	{
		my_pixel_put(mlx_inst, line.x1, line.y1, line.color);
		line.x1 = round(line.x1 + xinc);
		line.y1 = round(line.y1 + yinc);
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

void	draw_map(t_mlx *mlx_inst)
{
    t_rect	rect;
    t_line  line;
    t_circle    circle;
    int i;
    int j;

    // Map background
    rect.x = 0;
    rect.y = 0;
    rect.width = 20 * map_width;
    rect.heigth = 20 * map_height;
    rect.color = 0xFFFFFF;
    draw_rect(mlx_inst, rect);

    // Reading map; creating blocks and player
    j = -1;
    while (++j < map_height)
    {
        i = -1;
        while (++i < map_width)
        {
            rect.x = 20 * i;
            rect.y = 20 * j;
            rect.width = 20;
            rect.heigth = 20;
            if (map[j][i] == '1')
            {
                rect.color = 0x0000FF;
                draw_rect(mlx_inst, rect);
            }
            else if (map[j][i] == 'N')
            {
                circle.mid_x = 20 * i + 10;
                circle.mid_y = 20 * j + 10;
                circle.radius = 10;
                circle.color = 0x00FF00;
                draw_circle(mlx_inst, circle);
            }
            else
            {
                rect.color = 0xFFFFFF;
                draw_rect(mlx_inst, rect);
            }
        }
    }

    // Horizontal lines
    i = -1;
    while (++i <= map_height)
    {
        line.x1 = 0;
        line.x2 = 20 * map_width;
        line.y1 = 20 * i;
        line.y2 = 20 * i;
        line.color = 0xFF0000;
        draw_line(mlx_inst, line);
    }
    
    // Vertical lines
    i = -1;
    while (++i <= map_width)
    {
        line.x1 = 20 * i;
        line.x2 = 20 * i;
        line.y1 = 0;
        line.y2 = 20 * map_height;
        line.color = 0xFF0000;
        draw_line(mlx_inst, line);
    }
}

int main(void)
{
        t_cub2d cub2d;

	cub2d.mlx_inst = mlx_inst_init();
	draw_map(&cub2d.mlx_inst);
	mlx_put_image_to_window(cub2d.mlx_inst.mlx, cub2d.mlx_inst.win, cub2d.mlx_inst.img, 0, 0);
        mlx_key_hook(cub2d.mlx_inst.win, hook_handler, &cub2d);
	mlx_loop(cub2d.mlx_inst.mlx);
	return (0);
}

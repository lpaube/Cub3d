/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 22:31:20 by laube             #+#    #+#             */
/*   Updated: 2022/03/09 13:38:55 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "raycasting.h"

void	my_pixel_put(t_mlx *mlx_inst, int x, int y, int color)
{
	char	*pxl;

	// printf("y: %d\n", y);
	if (x >= mlx_inst->win_width || x < 0 || y >= mlx_inst->win_height || y < 0)
	{
		return ;
	}
	pxl = mlx_inst->addr + (y * mlx_inst->line_len)
		+ x * (mlx_inst->bits_per_pixel / 8);
	*(unsigned int *)pxl = color;
}

void	draw_rect(t_mlx *mlx_inst, t_rect rect)
{
	int	j;
	int	i;

	j = -1;
	while (++j < rect.heigth)
	{
		i = -1;
		while (++i < rect.width)
		{
			my_pixel_put(mlx_inst, rect.x + i, rect.y + j, rect.color);
		}
	}
}

void	draw_line(t_mlx *mlx_inst, t_line line)
{
	int		i;
	int		steps;
	float	xinc;
	float	yinc;

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

void	draw_circle(t_mlx *mlx_inst, t_circle circle)
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
			my_pixel_put(mlx_inst, circle.mid_x + x,
				round(circle.mid_y) + j, circle.color);
			my_pixel_put(mlx_inst, circle.mid_x - x,
				round(circle.mid_y) + j, circle.color);
		}
	}
}

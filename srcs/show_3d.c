/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 00:12:02 by laube             #+#    #+#             */
/*   Updated: 2022/03/09 12:10:11 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/graphics.h"
#include "../includes/raycasting.h"

void	show_3d(t_cub2d *cub2d)
{
	put_background(&cub2d->mlx_inst, cub2d->screen);
	put_textures(cub2d);
	mlx_put_image_to_window(cub2d->mlx_inst.mlx, cub2d->mlx_inst.win,
				cub2d->mlx_inst.img, 0, 0);
	if (cub2d->debug == 2)
	{
		draw_map(cub2d);
		draw_player(&cub2d->mlx_inst, cub2d->player);
		draw_direction(cub2d);
		for (int x = 0; x < cub2d->ray_num; x++)
		{
			// if ((x + 1) % (cub2d->mlx_inst.win_width / 10) == 0 || x == 0 || x == cub2d->mlx_inst.win_width - 1)
			// {
				if (cub2d->debug == 2)
					draw_rays(cub2d, x);
			// }
			if (cub2d->debug == 2)
				draw_seen_square(cub2d, x);
		}
		mlx_put_image_to_window(cub2d->mlx_inst.mlx, cub2d->mlx_inst.win,
					cub2d->mlx_inst.img, 0, 0);
	}

}

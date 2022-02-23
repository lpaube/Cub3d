/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 00:12:02 by laube             #+#    #+#             */
/*   Updated: 2022/02/22 11:43:00 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "graphics.h"
#include "raycasting.h"

void	show_3d(t_cub2d *cub2d)
{
	put_background(&cub2d->mlx_inst, cub2d->screen);
	put_textures(cub2d);
	mlx_put_image_to_window(cub2d->mlx_inst.mlx, cub2d->mlx_inst.win,
				cub2d->mlx_inst.img, 0, 0);
	//	printf("i: %d | height: %d | top: %d | bottom: %d | face: %c | hitpos: %f\n", i, cub2d->rays[i].height, cub2d->rays[i].draw_top, cub2d->rays[i].draw_bottom, cub2d->rays[i].face, cub2d->rays[i].hit_pos);
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
	//	mlx_put_image_to_window(cub2d->mlx_inst.mlx, cub2d->mlx_inst.win,
	//				cub2d->mlx_inst.img, 0, 0);
	}

}

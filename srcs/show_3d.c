/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 00:12:02 by laube             #+#    #+#             */
/*   Updated: 2022/02/11 14:17:24 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "graphics.h"

void	show_3d(t_cub2d *cub2d)
{
	put_background(&cub2d->mlx_inst, cub2d->screen);
	put_textures(cub2d);
	mlx_put_image_to_window(cub2d->mlx_inst.mlx, cub2d->mlx_inst.win,
				cub2d->mlx_inst.img, 0, 0);
	//	printf("i: %d | height: %d | top: %d | bottom: %d | face: %c | hitpos: %f\n", i, cub2d->rays[i].height, cub2d->rays[i].draw_top, cub2d->rays[i].draw_bottom, cub2d->rays[i].face, cub2d->rays[i].hit_pos);

}

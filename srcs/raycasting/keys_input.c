/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 01:29:51 by laube             #+#    #+#             */
/*   Updated: 2022/03/14 16:35:44 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "raycasting.h"

int	key_press(int keycode, t_cub2d *cub2d)
{
	if (keycode == MAIN_ESC)
	{
		free_map(cub2d->map_ptr);
		destroy_mlx(cub2d);
		exit(0);
	}
	else if (keycode == MAIN_W)
		cub2d->player.vel_u = 1;
	else if (keycode == MAIN_S)
		cub2d->player.vel_d = 1;
	else if (keycode == MAIN_A)
		cub2d->player.vel_l = 1;
	else if (keycode == MAIN_D)
		cub2d->player.vel_r = 1;
	else if (keycode == ARROW_LEFT)
		cub2d->player.rot_l = 1;
	else if (keycode == ARROW_RIGHT)
		cub2d->player.rot_r = 1;
	return (0);
}

int	key_release(int keycode, t_cub2d *cub2d)
{
	if (keycode == MAIN_W)
		cub2d->player.vel_u = 0;
	if (keycode == MAIN_S)
		cub2d->player.vel_d = 0;
	if (keycode == MAIN_A)
		cub2d->player.vel_l = 0;
	if (keycode == MAIN_D)
		cub2d->player.vel_r = 0;
	if (keycode == ARROW_LEFT)
		cub2d->player.rot_l = 0;
	if (keycode == ARROW_RIGHT)
		cub2d->player.rot_r = 0;
	return (0);
}

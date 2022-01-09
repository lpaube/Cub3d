/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <laube@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 21:49:30 by laube             #+#    #+#             */
/*   Updated: 2022/01/08 21:14:42 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "raycasting.h"

int	key_press(int keycode, t_cub2d *cub2d)
{
	if (keycode == MAIN_ESC)
		exit(0);
	else if (keycode == MAIN_W || keycode == MAIN_A
		|| keycode == MAIN_S || keycode == MAIN_D)
	{
		player_mvmt(keycode, cub2d);
		update_vectors(&cub2d->player);
	}
	game_loop_2d(cub2d);
	return (0);
}

int	click_close(void *param)
{
	(void)param;
	exit(0);
}

int	hook_handler(t_cub2d *cub2d)
{
	mlx_hook(cub2d->mlx_inst.win, 2, 1L << 0, key_press, cub2d);
	mlx_hook(cub2d->mlx_inst.win, 17, 0, click_close, cub2d);
	return (0);
}

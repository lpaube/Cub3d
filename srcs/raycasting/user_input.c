/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 21:49:30 by laube             #+#    #+#             */
/*   Updated: 2022/02/25 15:28:34 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "raycasting.h"

/*void	free_map(t_map *map_info)
{
	ft_free_tab(map_info->map);
	ft_free_tab(map_info->texture);
	free(map_info->floor);
	free(map_info->ceilling);
}*/

int	key_press(int keycode, t_cub2d *cub2d)
{
	if (keycode == MAIN_ESC)
	{
		//free_map(&cub2d->map);
		exit(0);
	}
	else if (keycode == MAIN_W || keycode == MAIN_A
		|| keycode == MAIN_S || keycode == MAIN_D)
	{
		player_mvmt(keycode, cub2d);
		update_vectors(cub2d, &cub2d->player);
	}
	game_loop(cub2d);
	return (0);
}

int	click_close(void *param)
{
	t_cub2d	*cub2d;

	cub2d = param;
	//free_map(&cub2d->map);
	(void)param;
	exit(0);
}

int	mouse_mvmt(int x, int y, t_cub2d *cub2d)
{
	cub2d->mouse_x = x;
	cub2d->mouse_y = y;
	return (0);
}

int	hook_handler(t_cub2d *cub2d)
{
	mlx_hook(cub2d->mlx_inst.win, 6, 1L << 6, mouse_mvmt, cub2d);
	mlx_hook(cub2d->mlx_inst.win, 2, 1L << 0, key_press, cub2d);
	mlx_hook(cub2d->mlx_inst.win, 17, 0, click_close, cub2d);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 21:49:30 by laube             #+#    #+#             */
/*   Updated: 2022/03/04 17:28:53 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "raycasting.h"

void	free_map(t_map *map_info, t_cub2d *cub2d)
{
	t_graph	*screen;

	screen = cub2d->screen;
	ft_free_tab(map_info->map);
	ft_free_tab(map_info->texture);
	free(map_info->floor);
	free(map_info->ceilling);
	free(map_info);
	mlx_destroy_window(cub2d->mlx_inst.mlx, cub2d->mlx_inst.win);
	mlx_destroy_image(cub2d->mlx_inst.mlx, cub2d->mlx_inst.img);
	mlx_destroy_image(cub2d->mlx_inst.mlx, screen->wall_n.img);
	mlx_destroy_image(cub2d->mlx_inst.mlx, screen->wall_e.img);
	mlx_destroy_image(cub2d->mlx_inst.mlx, screen->wall_s.img);
	mlx_destroy_image(cub2d->mlx_inst.mlx, screen->wall_w.img);
}

int	key_press(int keycode, t_cub2d *cub2d)
{
	if (keycode == MAIN_ESC)
	{
		free_map(cub2d->map_ptr, cub2d);
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
	free_map(cub2d->map_ptr, cub2d);
	(void)param;
	(void)cub2d;
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

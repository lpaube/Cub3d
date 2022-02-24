/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 21:22:04 by laube             #+#    #+#             */
/*   Updated: 2022/02/23 15:12:46 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_mlx   mlx_inst_init(void);
void    init_vectors(t_cub2d *cub2d, t_player *player);
void    update_vectors(t_cub2d *cub2d, t_player *player);
 
void	draw_rect(t_mlx *mlx_inst, t_rect rect);
void	draw_circle(t_mlx *mlx_inst, t_circle circle);
void	draw_line(t_mlx *mlx_inst, t_line line);
void	draw_direction(t_cub2d *cub2d);
void    draw_rays(t_cub2d *cub2d, int x);
void	draw_seen_square(t_cub2d *cub2d, int x);
void	draw_map(t_cub2d *cub2d);
void	draw_player(t_mlx *mlx_inst, t_player player);

void    ray_cast(t_cub2d *cub2d);
int     hook_handler(t_cub2d *cub2d);
void    game_loop(t_cub2d *cub2d);

void	player_mvmt(int keycode, t_cub2d *cub2d);
void	put_diagnostics(t_cub2d *cub2d);
t_player	init_player(t_cub2d *cub2d);

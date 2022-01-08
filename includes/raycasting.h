/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <laube@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 21:22:04 by laube             #+#    #+#             */
/*   Updated: 2022/01/07 23:03:52 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern int map_width;
extern int map_height;
extern int player_x;
extern int player_y;
extern char    player_orien;
extern char map[24][24];

t_mlx   mlx_inst_init(t_cub2d *cub2d);
void    init_vectors(t_player *player);
void    update_vectors(t_player *player);
 
void	draw_rect(t_mlx *mlx_inst, t_rect rect);
void	draw_circle(t_mlx *mlx_inst, t_circle circle);
void	draw_line(t_mlx *mlx_inst, t_line line);
void	draw_cub2d(t_cub2d *cub2d, t_mlx *mlx_inst);
void	draw_direction(t_cub2d *cub2d);
void    draw_rays(t_cub2d *cub2d);

void    ray_cast(t_cub2d *cub2d, t_player *player);
int     hook_handler(t_cub2d *cub2d);
void    game_loop_2d(t_cub2d *cub2d);

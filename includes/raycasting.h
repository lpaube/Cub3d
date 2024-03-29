#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "cub3d.h"

t_mlx		mlx_inst_init(void);
void		init_vectors(t_cub2d *cub2d, t_player *player);
void		update_vectors(t_cub2d *cub2d, t_player *player);
void		draw_rect(t_mlx *mlx_inst, t_rect rect);
void		draw_circle(t_mlx *mlx_inst, t_circle circle);
void		draw_line(t_mlx *mlx_inst, t_line line);
void		draw_direction(t_cub2d *cub2d);
void		draw_rays(t_cub2d *cub2d, int x);
void		draw_seen_square(t_cub2d *cub2d, int x);
void		draw_map(t_cub2d *cub2d);
void		draw_player(t_mlx *mlx_inst, t_player player);
t_mlx		mlx_inst_init(void);
void		init_vectors(t_cub2d *cub2d, t_player *player);
void		update_vectors(t_cub2d *cub2d, t_player *player);	
void		draw_rect(t_mlx *mlx_inst, t_rect rect);
void		draw_circle(t_mlx *mlx_inst, t_circle circle);
void		draw_line(t_mlx *mlx_inst, t_line line);
void		draw_direction(t_cub2d *cub2d);
void		draw_rays(t_cub2d *cub2d, int x);
void		draw_seen_square(t_cub2d *cub2d, int x);
void		draw_map(t_cub2d *cub2d);
void		draw_player(t_mlx *mlx_inst, t_player player);	
void		ray_cast(t_cub2d *cub2d);
int			hook_handler(t_cub2d *cub2d);
void		game_loop(t_cub2d *cub2d);
void		player_mvmt(t_cub2d *cub2d);
t_player	init_player(t_cub2d *cub2d);
void		inc_ray_len(t_cub2d *cub2d);
void		get_ray_side(t_cub2d *cub2d, int x);
void		get_ray_data(t_cub2d *cub2d, int x);
double		deg_to_rad(int deg);
void		offset_x(t_cub2d *cub2d);
void		offset_y(t_cub2d *cub2d);
void		dist_offset(t_cub2d *cub2d);
int			key_press(int keycode, t_cub2d *cub2d);
int			key_release(int keycode, t_cub2d *cub2d);

#endif

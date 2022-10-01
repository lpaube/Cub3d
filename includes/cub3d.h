#ifndef CUB3D_H
# define CUB3D_H

# ifdef _LINUX
#  include "key_codes_linux.h"
# else
#  include "key_codes_mac.h"
# endif

# define TILE_SIZE	20
# define WIN_WIDTH	1280
# define WIN_HEIGHT	720

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include "mlx.h"
# include "../libft/libft.h"
# include "parsing.h"
# include "graphics.h"

// x and y represent the center of the circle
typedef struct s_circle
{
	double	mid_x;
	double	mid_y;
	int		radius;
	int		color;
}	t_circle;

typedef struct s_player
{
	t_circle	circle;
	double		vel_u;
	double		vel_d;
	double		vel_l;
	double		vel_r;
	int			rot_l;
	int			rot_r;
	char		orien;
	int			tile_y;
	int			tile_x;
	int			angle;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		mvmt;
	double		fov;
}	t_player;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
	int		win_width;
	int		win_height;
	int		game_width;
}	t_mlx;

typedef struct s_raycast
{
	int		side;
	double	dist_x;
	double	dist_y;
	double	len;
	double	delta_x;
	double	delta_y;
	int		step_x;
	int		step_y;
	int		map_x;
	int		map_y;
	double	ray_dir_x;
	double	ray_dir_y;
	double	camera_x;
	double	offset_x;
	double	offset_y;
}	t_raycast;

typedef struct s_rays
{
	double	len;
	int		height;
	int		draw_top;
	int		draw_bottom;
	char	face;
	double	hit_pos;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
}	t_rays;

typedef struct s_cub2d
{
	t_map		map;
	t_map		*map_ptr;
	t_mlx		mlx_inst;
	t_player	player;
	t_raycast	raycast;
	t_rays		*rays;
	t_graph		*screen;
	int			ray_num;
	int			tile_size;
	int			mouse_x;
	int			mouse_y;
	int			prev_mouse_x;
	int			prev_mouse_y;
	int			debug;
	int			count;
}	t_cub2d;

typedef struct s_line
{
	int	x1;
	int	y1;
	int	x2;
	int	y2;
	int	color;
}	t_line;

// x and y represent the top-left corner of the rect
typedef struct s_rect
{
	int	x;
	int	y;
	int	width;
	int	heigth;
	int	color;
}	t_rect;

void	game_context(int debug, t_map *map);
void	handle_2d(void);
void	my_pixel_put(t_mlx *mlx_inst, int x, int y, int color);
void	destroy_mlx(t_cub2d *cub2d);
void	free_map(t_map *map_info);

#endif

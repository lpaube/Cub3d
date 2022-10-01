#ifndef GRAPHICS_H
# define GRAPHICS_H

# include <stdbool.h>
# include <stddef.h>
# include "cub3d.h"

# define OFFSET 100

typedef struct s_texture
{
	void	*img;
	void	*addr;
	int		img_width;
	int		img_height;
	int		bpp;
	int		line_len;
	int		endian;
}	t_texture;

typedef struct s_graph
{
	t_texture	wall_n;
	t_texture	wall_e;
	t_texture	wall_s;
	t_texture	wall_w;
	int			rgb_floor;
	int			rgb_ceilling;
}	t_graph;

typedef struct s_cub2d	t_cub2d;
typedef struct s_mlx	t_mlx;
typedef struct s_rays	t_rays;

t_graph		background_converter(t_map *map_info);
void		put_background(t_mlx *mlx_inst, t_graph *screen);
void		show_3d(t_cub2d *cub2d);
bool		textures_converter(t_graph *s, t_mlx *mlx, char **txtr);
void		put_textures(t_cub2d *cub2d);
t_texture	get_face_asset(char face, t_graph *screen);
int			get_end_height(t_rays ray);
int			get_starting_height(t_rays ray);

#endif

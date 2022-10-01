#include "../includes/cub3d.h"
#include "../includes/graphics.h"
#include "../includes/raycasting.h"

void	show_3d(t_cub2d *cub2d)
{
	void	*img;

	put_background(&cub2d->mlx_inst, cub2d->screen);
	put_textures(cub2d);
	img = cub2d->mlx_inst.img;
	mlx_put_image_to_window(cub2d->mlx_inst.mlx, cub2d->mlx_inst.win,
		img, 0, 0);
}

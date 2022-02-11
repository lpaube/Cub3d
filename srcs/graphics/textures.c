/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:34:02 by mafortin          #+#    #+#             */
/*   Updated: 2022/02/11 14:21:18 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "cub3d.h"
#include "graphics.h"

//get all the img and the addr of the texture with the mlx functions
//Return false if the mlx functions return NULL
t_texture	get_asset(char *texture, t_mlx *mlx_inst)
{
	t_texture asset;
	
	asset.img = mlx_xpm_file_to_image(mlx_inst->mlx, texture,
			&asset.img_width, &asset.img_height);
	asset.addr = mlx_get_data_addr(asset.img, &asset.bpp, &asset.line_len,
			&asset.endian);
	return (asset);
}

//Get the textures info for the 4 assets (north,east,south,west wall texture)
//Return false if the mlx functions return NULL
bool	textures_converter(t_graph *screen, t_mlx *mlx_inst, char **textures)
{
	screen->wall_n = get_asset(textures[0], mlx_inst);
	screen->wall_e = get_asset(textures[1], mlx_inst);
	screen->wall_s = get_asset(textures[2], mlx_inst);
	screen->wall_w = get_asset(textures[3], mlx_inst);
	return (true);
}

int	get_asset_color(t_texture asset, int x, int y)
{
	int	color;

	color = *(unsigned int *)(asset.addr
			+ (y * asset.line_len + x * (asset.bpp / 8)));
	return (color);
}

void	put_texture_ray(t_cub2d *cub2d, t_rays ray, t_texture asset, int x)
{
	int	pixel_skip;
	int		color;

	pixel_skip = ray.height / 60;
	while (pixel_skip < WIN_HEIGTH)
	{
		color = get_asset_color(asset, x, pixel_skip);
		my_pixel_put(&cub2d->mlx_inst, x, pixel_skip, color);
		pixel_skip += pixel_skip;
	}
	(void)ray;
	(void)cub2d;
	(void)asset;
	(void)x;
	(void)color;
}

void	put_textures(t_cub2d *cub2d)
{
	int	i;

	i = 0;
	while (i <= cub2d->ray_num)
	{
		put_texture_ray(cub2d, cub2d->rays[i], cub2d->screen->wall_n, i);
		i++;
	}
	(void)cub2d;
}

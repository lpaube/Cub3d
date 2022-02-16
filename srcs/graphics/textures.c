/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:34:02 by mafortin          #+#    #+#             */
/*   Updated: 2022/02/16 14:23:02 by mafortin         ###   ########.fr       */
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

void	put_texture_ray(t_cub2d *cub2d, t_texture asset, int y, double skip)
{
	int		color;
	int		start;
	int		end;
	int		spray;
	
	start = get_starting_height(cub2d->rays[y]);
	end = get_end_height(cub2d->rays[y]);
	spray = (cub2d->rays[y].hit_pos * (asset.img_width + 100) / 100);
	while (start < end)
	{
		//if (skip < asset.img_width)
			//color = get_asset_color(asset, skip, spray);
		if (start > 0 && start < WIN_HEIGTH)
			my_pixel_put(&cub2d->mlx_inst, y, start, 0xFF0000);
		start++;
		skip += skip;
	}
	(void)cub2d;
	(void)asset;
	(void)color;
	(void)y;
	(void)skip;
	(void)spray;
}

void	put_textures(t_cub2d *cub2d)
{
	int				y;
	double			skip;
	t_texture		asset;

	y = 0;
	while (y < cub2d->ray_num)
	{
		asset = get_face_asset(cub2d->rays[y].face, cub2d->screen);
		skip = asset.img_height / cub2d->rays[y].height + 100;
		//while (skip < asset.img_width)
		//{
			put_texture_ray(cub2d, asset, y, skip);
			y++;
			skip += skip;
		//}
	}
	(void)cub2d;
	(void)asset;
}

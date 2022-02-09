/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:34:02 by mafortin          #+#    #+#             */
/*   Updated: 2022/02/09 17:41:12 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "cub3d.h"
#include "graphics.h"

//get all the img and the addr of the texture with the mlx functions
//Return false if the mlx functions return NULL
bool	get_asset(char *texture, t_texture asset, t_mlx *mlx_inst)
{
	asset.img = mlx_xpm_file_to_image(mlx_inst->mlx, texture,
			&asset.img_width, &asset.img_height);
	asset.addr = mlx_get_data_addr(asset.img, &asset.bpp, &asset.line_len,
			&asset.endian);
	if (!asset.img || !asset.addr)
		return (false);
	return (true);
}

//Get the textures info for the 4 assets (north,east,south,west wall texture)
//Return false if the mlx functions return NULL
bool	textures_converter(t_graph *screen, t_mlx *mlx_inst, char **textures)
{
	if (get_asset(textures[0], screen->wall_n, mlx_inst) == false
		|| get_asset(textures[1], screen->wall_e, mlx_inst) == false
		|| get_asset(textures[2], screen->wall_s, mlx_inst) == false
		|| get_asset(textures[3], screen->wall_w, mlx_inst) == false)
		return (false);
	return (true);
}

int	get_asset_color(t_texture asset, int x, int y)
{
	int	color;

	color = *(unsigned int *)(asset.addr
			+ (y * asset.line_len + x * (asset.bpp / 8)));
	return (color);
}

void	put_texture_ray(t_cub2d cub2d, t_rays ray)
{
	int	pixel_skip;

	pixel_skip = 0;
	(void)ray;
	(void)cub2d;
	//calculate the pixel skip rate (to wrap the texture).
}

void	put_textures(t_cub2d cub2d)
{
	int	i;

	i = 0;
	while (i <= cub2d.ray_num)
	{
		//put_texture_ray();
		i++;
	}
	(void)cub2d;
}

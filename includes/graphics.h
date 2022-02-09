/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:35:08 by mafortin          #+#    #+#             */
/*   Updated: 2022/02/07 18:43:08 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H

#include <stdbool.h>
#include <stddef.h>
#include "cub3d.h"

typedef struct s_graph
{
	void	*wall_1;
	void	*wall_2;
	void	*wall_3;
	void	*wall_4;
	int		rgb_floor;
	int		rgb_ceilling;
}	t_graph;

typedef struct	s_cub2d t_cub2d;
typedef struct	s_mlx	t_mlx;

void	background_converter(t_map *map_info, t_graph *screen);
void	put_background(t_mlx *mlx_inst, t_graph *screen);
void	show_3d(t_cub2d *cub2d);

#endif
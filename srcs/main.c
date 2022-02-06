/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 15:17:16 by laube             #+#    #+#             */
/*   Updated: 2022/02/06 13:37:35 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parsing.h"
#include "raycasting.h"

int	main(int argc, char **argv)
{
	t_mlx	mlx_main;
	int	debug;
	int	i;
	t_map *map_info;
	t_rays	*rays;
	
	
	debug = 0;
	mlx_main = mlx_inst_init();
	map_info = malloc(sizeof(t_map));
	if (ft_strcmp(argv[1], "-2d") == 0)
	{
		debug = 2;
		i = 0;
		while (argv[++i])
			argv[i] = argv[i + 1];
		argc--;
	}
	if (cb_parsing_main(argc, argv, map_info) == false)
		return (1);
	rays = context_2d(debug, map_info, mlx_main);
	(void)rays;
	return (0);
}

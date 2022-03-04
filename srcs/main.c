/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 15:17:16 by laube             #+#    #+#             */
/*   Updated: 2022/03/04 17:18:04 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parsing.h"
#include "raycasting.h"

int	main(int argc, char **argv)
{
	int	debug;
	int	i;
	t_map *map_info;
	
	debug = 0;
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
	game_context(debug, map_info);
	//free(map_info);
	return (0);
}

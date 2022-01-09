/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <laube@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 15:17:16 by laube             #+#    #+#             */
/*   Updated: 2022/01/09 15:21:47 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "raycasting.h"

int	main(int argc, char **argv)
{
	int	debug;
	int	i;

	debug = 0;
	if (ft_strcmp(argv[1], "-2d") == 0)
	{
		debug = 2;
		i = 0;
		while (argv[++i])
			argv[i] = argv[i + 1];
		argc--;
	}
	// MAFORTIN: ADD YOUR MAP PARSING HERE



	// MAFORTIN: ADD YOUR MAP PARSING ABOVE
	context_2d(debug);
	return (0);
}

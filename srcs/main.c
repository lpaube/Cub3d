/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:30:50 by laube             #+#    #+#             */
/*   Updated: 2022/01/06 15:37:57 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parsing.h"
#include <stdlib.h>

int main(int argc, char **argv)
{
	t_map *map_info;

	map_info = malloc(sizeof(t_map));
	if (cb_parsing_main(argc, argv, map_info) == false)
		return (1);
	handle_2d();
	free(map_info);
	return (0);
}

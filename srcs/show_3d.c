/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 00:12:02 by laube             #+#    #+#             */
/*   Updated: 2022/02/02 17:51:10 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	show_3d(t_cub2d *cub2d)
{
	int i;

	i = 0;
	while (i < cub2d->ray_num)
	{
		printf("i: %d | height: %d | top: %d | bottom: %d | face: %c\n", i, cub2d->rays[i].height, cub2d->rays[i].draw_top, cub2d->rays[i].draw_bottom, cub2d->rays[i].face);
		i++;
	}
}

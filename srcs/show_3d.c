/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 00:12:02 by laube             #+#    #+#             */
/*   Updated: 2022/01/30 17:09:31 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	show_3d(t_cub2d *cub2d)
{
	int i;

	i = 0;
	while (i < cub2d->ray_num)
	{
		printf("i: %d | len: %f | face: %c\n", i, cub2d->rays[i].len, cub2d->rays[i].face);
		i++;
	}
}

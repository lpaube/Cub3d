/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <laube@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 00:12:02 by laube             #+#    #+#             */
/*   Updated: 2022/01/29 00:16:52 by laube            ###   ########.fr       */
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

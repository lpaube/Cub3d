/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <laube@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 21:22:04 by laube             #+#    #+#             */
/*   Updated: 2022/01/07 21:45:22 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern int map_width;
extern int map_height;
extern int player_x;
extern int player_y;
extern char    player_orien;

t_mlx mlx_inst_init(t_cub2d *cub2d);
void    init_vectors(t_player *player);
void    update_vectors(t_player *player);

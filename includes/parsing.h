/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 11:36:21 by mafortin          #+#    #+#             */
/*   Updated: 2021/12/10 15:51:42 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

typedef struct s_map
{
	char	**map;
	char	**texture;
	char	*ceiling;
	char	*floor;
	char	orientation;
	int		map_width;
	int		map_height;
	int		player_x;
	int		player_y;
}	t_map;

bool	cb_parsing_main(char *file, t_map *map_info);
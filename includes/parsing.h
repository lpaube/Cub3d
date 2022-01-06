/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 11:36:21 by mafortin          #+#    #+#             */
/*   Updated: 2022/01/06 15:37:39 by mafortin         ###   ########.fr       */
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

bool	cb_parsing_main(int argc, char **argv, t_map *map_info);
int		cb_nbline_file(char *file);
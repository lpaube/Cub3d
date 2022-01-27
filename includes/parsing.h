/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 11:36:21 by mafortin          #+#    #+#             */
/*   Updated: 2022/01/27 14:25:07 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

#include <stdbool.h>
#include <stddef.h>

# define DIRECTION "NSEW"

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
bool	cb_map_parsing(char **content, t_map *map_info);
int		cb_line_type(char *string);
bool	cb_valid_tile(char c);
int		cb_map_end(char **content, int start, int j, t_map *map_info);
char	**cb_add_mapline(t_map *map_info, char *string);
char	*cb_line_dup(const char *s1, size_t len);
int		cb_mapwidth(char **content, int i, int depth);
bool	cb_wall_vert(t_map *map_info, int i, int i2, int j);
bool	cb_wall_hor(t_map *map_info, int i, int j2, int j);

#endif

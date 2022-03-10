/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 11:36:21 by mafortin          #+#    #+#             */
/*   Updated: 2022/03/08 16:41:15 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdbool.h>
# include <stddef.h>

# define DIRECTION "NSEW"

//Texture:
//Index 0 = North Texture
//Index 1 = East Texture
//Index 2 = South Texture
//Index 3 = West Texture
//Floor and ceilling color:
//Index 0 = R
//Index 1 = G
//Index 2 = B
typedef struct s_map
{
	char	**map;
	char	**texture;
	char	orientation;
	int		map_width;
	int		map_height;
	int		player_x;
	int		player_y;
	int		*floor;
	int		*ceilling;
	int		time;
}	t_map;

bool	cb_parsing_main(char **argv, t_map *map_info);
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
bool	cb_valid_content(char **content);
bool	cb_texture_parsing(char **content, t_map *map_info);
bool	cb_color_parsing(char **content, t_map *map_info, char type);
bool	cb_closedmap(t_map *map_info, int i, int j);
int		cb_valid_mapline(char *string, int i, int start);
bool	free_color(char **numbers);
bool	cb_cubfile(char *file);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <marvin@42quebec.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 17:54:22 by laube             #+#    #+#             */
/*   Updated: 2021/12/09 23:45:29 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// These are the attributes that I need for the 2d part
typedef struct s_map_placeholder
{
    char **map;
    int map_width;
    int map_height;
    char    orientation;
} t_map_placeholder;

typedef struct s_mlx
{
    void *mlx;
    void *win;
    void *img;
    char *addr;
    int bits_per_pixel;
    int	line_len;
    int	endian;
}	t_mlx;

typedef struct s_player
{
    int pos_x;
    int pos_y;
}

typedef struct s_line
{
    int	x1;
    int	y1;
    int	x2;
    int	y2;
    int	color;
} t_line;

// x and y represent the top-left corner of the rect
typedef struct s_rect
{
    int	x;
    int	y;
    int	width;
    int	heigth;
    int	color;
}	t_rect;

// x and y represent the center of the circle
typedef struct	s_circle
{
    int	mid_x;
    int	mid_y;
    int radius;
    int color;
}	t_circle;

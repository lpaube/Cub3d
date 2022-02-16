//HEADER

#include "parsing.h"
#include "cub3d.h"
#include "graphics.h"

//Give the vertical pixel where the line of a ray/texture should start.
int	get_starting_height(t_rays ray)
{
	return ((WIN_HEIGTH / 2) - (ray.height / 2));
}

int	get_end_height(t_rays ray)
{
	return ((WIN_HEIGTH / 2) + (ray.height / 2));
}

t_texture get_face_asset(char face, t_graph *screen)
{
	if (face == 'N')
		return (screen->wall_n);
	if (face == 'E')
		return (screen->wall_e);
	if (face == 'S')
		return (screen->wall_s);
	return (screen->wall_w);
}
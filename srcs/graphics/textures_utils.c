//HEADER

#include "parsing.h"
#include "cub3d.h"
#include "graphics.h"

//Give the vertical pixel where the line of a ray/texture should start.
int	get_starting_height(t_rays ray)
{
	return ((WIN_HEIGTH / 2) + (ray.height / 2));
}
#include "cub3d.h"
#include "parsing.h"
#include "raycasting.h"

void	init_map(t_map *map_info)
{
	map_info->map = NULL;
	map_info->texture = NULL;
	map_info->floor = NULL;
	map_info->ceilling = NULL;
}

void	free_map(t_map *map_info)
{
	if (map_info->map)
		ft_free_tab(map_info->map);
	if (map_info->texture)
		ft_free_tab(map_info->texture);
	if (map_info->floor)
		free(map_info->floor);
	if (map_info->ceilling)
		free(map_info->ceilling);
	free(map_info);
}

void	destroy_mlx(t_cub2d *cub2d)
{
	t_graph	*screen;

	screen = cub2d->screen;
	mlx_destroy_window(cub2d->mlx_inst.mlx, cub2d->mlx_inst.win);
	mlx_destroy_image(cub2d->mlx_inst.mlx, cub2d->mlx_inst.img);
	mlx_destroy_image(cub2d->mlx_inst.mlx, screen->wall_n.img);
	mlx_destroy_image(cub2d->mlx_inst.mlx, screen->wall_e.img);
	mlx_destroy_image(cub2d->mlx_inst.mlx, screen->wall_s.img);
	mlx_destroy_image(cub2d->mlx_inst.mlx, screen->wall_w.img);
}

int	main(int argc, char **argv)
{
	t_map	*map_info;

	if (argc != 2)
	{
		printf("Error\nInvalid # of argument\n");
		return (1);
	}
	if (cb_cubfile(argv[1]) == false)
	{
		printf("Error\nInvalid file type\n");
		return (1);
	}
	map_info = malloc(sizeof(t_map));
	init_map(map_info);
	if (cb_parsing_main(argv, map_info) == false)
		return (1);
	game_context(0, map_info);
	free_map(map_info);
	return (0);
}

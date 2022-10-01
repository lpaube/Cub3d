#include "cub3d.h"
#include "raycasting.h"

t_player	init_player(t_cub2d *cub2d)
{
	t_player	player;
	t_circle	circle;

	circle.mid_x = (cub2d->tile_size * cub2d->map.player_x)
		+ (cub2d->tile_size / 2);
	circle.mid_y = (cub2d->tile_size * cub2d->map.player_y)
		+ (cub2d->tile_size / 2);
	circle.radius = cub2d->tile_size / 4;
	circle.color = 0x00FF00;
	player.circle = circle;
	player.orien = cub2d->map.orientation;
	player.mvmt = cub2d->tile_size / 10;
	player.fov = 66;
	player.vel_u = 0;
	player.vel_d = 0;
	player.vel_l = 0;
	player.vel_r = 0;
	player.rot_l = 0;
	player.rot_r = 0;
	init_vectors(cub2d, &player);
	return (player);
}

void	init_vectors(t_cub2d *cub2d, t_player *player)
{
	if (player->orien == 'N')
	{
		player->angle = 90;
	}
	if (player->orien == 'S')
	{
		player->angle = 270;
	}
	if (player->orien == 'E')
	{
		player->angle = 0;
	}
	if (player->orien == 'W')
	{
		player->angle = 180;
	}
	update_vectors(cub2d, player);
}

t_mlx	mlx_inst_init(void)
{
	t_mlx	mlx_inst;

	mlx_inst.win_width = 1280;
	mlx_inst.win_height = 720;
	mlx_inst.game_width = mlx_inst.win_width - 200;
	mlx_inst.game_width = mlx_inst.win_width - 200;
	mlx_inst.mlx = mlx_init();
	mlx_inst.win = mlx_new_window(mlx_inst.mlx, mlx_inst.win_width,
			mlx_inst.win_height, "Cub3d");
	mlx_inst.img = mlx_new_image(mlx_inst.mlx, mlx_inst.win_width,
			mlx_inst.win_height);
	mlx_inst.addr = mlx_get_data_addr(mlx_inst.img, &mlx_inst.bits_per_pixel,
			&mlx_inst.line_len, &mlx_inst.endian);
	return (mlx_inst);
}

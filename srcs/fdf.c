/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <lubrun@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/14 01:54:46 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/23 13:14:40 by lubrun      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		on_key_pressed2(int key, void **param)
{
	t_map_info *map_info;

	map_info = *param;
	if (key == 19)
		switch_proj(&map_info, 1);
	else if (key == 20)
		switch_proj(&map_info, 2);
	else if (key == 53)
		close_me(&map_info);
	return (1);
}

int		on_key_pressed(int key, void **param)
{
	t_map_info *game_info;

	game_info = *param;
	if (key == 124)
		move_right(&game_info);
	else if (key == 123)
		move_left(&game_info);
	else if (key == 125)
		move_up(&game_info);
	else if (key == 126)
		move_down(&game_info);
	else if (key == 69)
		rescale(&game_info, 1.5);
	else if (key == 78)
		rescale(&game_info, 0.5);
	else if (key == 49)
		rescale_z(&game_info, 1.3);
	else if (key == 51)
		rescale_z(&game_info, 0.7);
	else if (key == 21)
		rotate180(&game_info);
	else if (key == 18)
		switch_proj(&game_info, 0);
	return (on_key_pressed2(key, param));
}

void	init_env(t_map_info **amap_info, void *mlx_ptr)
{
	t_map_info *map_info;

	map_info = (*amap_info);
	map_info->mlx_ptr = mlx_ptr;
	map_info->win_ptr = mlx_new_window(mlx_ptr, map_info->win_size_x,
	map_info->win_size_y, "Lubrun | FDF");
	map_info->zero = new_point_3d(0, 0, 0);
	map_info->x_vector = new_vector_2d(10, 4);
	map_info->y_vector = new_vector_2d(-10, 4);
	map_info->z_vector = new_vector_2d(0, -5.8);
	map_info->scale = 5;
	map_info->z_scale = 5;
	map_info->img = new_image(map_info);
}

int		main(int ac, char **av)
{
	t_map_info *map_info;

	if (ac != 2)
		return (write(1, "usage:./fdf map.fdf\n", 20));
	if (parse_map(open(av[1], O_RDONLY), &map_info) == -1)
		return (write(1, "error\n", 6));
	init_env(&map_info, mlx_init());
	place_points(map_info);
	mlx_key_hook(map_info->win_ptr, on_key_pressed, &map_info);
	mlx_loop(map_info->mlx_ptr);
	return (0);
}

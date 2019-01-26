/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   control.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/21 16:09:14 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/23 13:14:35 by lubrun      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	move_right(t_map_info **amap_info)
{
	t_map_info	*map_info;

	map_info = *amap_info;
	mlx_destroy_image(map_info->mlx_ptr, map_info->img->ptr);
	free(map_info->img);
	map_info->img = new_image(map_info);
	map_info->zero.x -= 100;
	place_points(map_info);
}

void	move_left(t_map_info **amap_info)
{
	t_map_info	*map_info;

	map_info = *amap_info;
	mlx_destroy_image(map_info->mlx_ptr, map_info->img->ptr);
	free(map_info->img);
	map_info->img = new_image(map_info);
	map_info->zero.x += 100;
	place_points(map_info);
}

void	move_up(t_map_info **amap_info)
{
	t_map_info	*map_info;

	map_info = *amap_info;
	mlx_destroy_image(map_info->mlx_ptr, map_info->img->ptr);
	free(map_info->img);
	map_info->img = new_image(map_info);
	map_info->zero.y -= 100;
	place_points(map_info);
}

void	move_down(t_map_info **amap_info)
{
	t_map_info	*map_info;

	map_info = *amap_info;
	mlx_destroy_image(map_info->mlx_ptr, map_info->img->ptr);
	free(map_info->img);
	map_info->img = new_image(map_info);
	map_info->zero.y += 100;
	place_points(map_info);
}

void	rescale(t_map_info **amap_info, float scale)
{
	t_map_info	*map_info;

	map_info = *amap_info;
	mlx_destroy_image(map_info->mlx_ptr, map_info->img->ptr);
	free(map_info->img);
	map_info->img = new_image(map_info);
	map_info->scale *= scale;
	map_info->z_scale *= scale;
	place_points(map_info);
}

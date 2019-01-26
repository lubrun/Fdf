/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   bonus.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <lubrun@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/19 15:15:00 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/23 13:00:15 by lubrun      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	switch_proj(t_map_info **amap_info, int index)
{
	t_map_info	*map_info;

	map_info = *amap_info;
	mlx_destroy_image(map_info->mlx_ptr, map_info->img->ptr);
	free(map_info->img);
	map_info->img = new_image(map_info);
	if (index == 0)
	{
		map_info->x_vector = new_vector_2d(10, 4);
		map_info->y_vector = new_vector_2d(-10, 4);
		map_info->z_vector = new_vector_2d(0, -5.8);
	}
	else if (index == 1)
	{
		map_info->x_vector = new_vector_2d(10, 0);
		map_info->y_vector = new_vector_2d(0, 4);
		map_info->z_vector = new_vector_2d(0, -5.8);
	}
	else if (index == 2)
	{
		map_info->x_vector = new_vector_2d(10, 0);
		map_info->y_vector = new_vector_2d(0, 10);
		map_info->z_vector = new_vector_2d(0, 0);
	}
	place_points(map_info);
}

void	rescale_z(t_map_info **amap_info, float dif)
{
	t_map_info	*map_info;

	map_info = *amap_info;
	mlx_destroy_image(map_info->mlx_ptr, map_info->img->ptr);
	free(map_info->img);
	map_info->img = new_image(map_info);
	map_info->z_scale *= dif;
	place_points(map_info);
}

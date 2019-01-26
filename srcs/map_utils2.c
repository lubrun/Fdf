/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_utils2.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/08 14:03:27 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/23 13:00:50 by lubrun      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		check_line(t_point_3d point, t_point_2d proj, t_map_info *map_info)
{
	t_point_3d new_3d;

	if (point.x + 1 < map_info->map_size_x)
	{
		new_3d = new_point_3d(point.x + 1, point.y,
		map_info->map[point.y][point.x + 1]);
		draw_line(map_info, proj, calc_proj(map_info, new_3d), 0xFFFFFF);
	}
	if (point.y + 1 < map_info->map_size_y)
	{
		new_3d = new_point_3d(point.x, point.y + 1,
		map_info->map[point.y + 1][point.x]);
		draw_line(map_info, proj, calc_proj(map_info, new_3d), 0xFFFFFF);
	}
}

void		rotate180(t_map_info **amap_info)
{
	t_map_info	*map_info;

	map_info = (t_map_info *)*amap_info;
	mlx_destroy_image(map_info->mlx_ptr, map_info->img->ptr);
	free(map_info->img);
	map_info->img = new_image(map_info);
	map_info->x_vector = new_vector_2d(-map_info->x_vector.x,
			-map_info->x_vector.y);
	map_info->y_vector = new_vector_2d(-map_info->y_vector.x,
			-map_info->y_vector.y);
	place_points(map_info);
}

t_point_2d	calc_proj(t_map_info *map_info, t_point_3d point)
{
	t_point_2d	proj;

	proj = new_point_2d(map_info->zero.x + (
	point.x * (map_info->scale * map_info->x_vector.x) +
	point.y * (map_info->scale * map_info->y_vector.x) +
	point.z * (map_info->z_scale * map_info->z_vector.x)),
	map_info->zero.y + (point.x * (map_info->scale * map_info->x_vector.y) +
	point.y * (map_info->scale * map_info->y_vector.y) +
	point.z * (map_info->z_scale * map_info->z_vector.y)));
	return (proj);
}

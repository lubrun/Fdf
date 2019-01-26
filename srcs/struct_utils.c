/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   struct_utils.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <lubrun@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/14 03:27:39 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/22 11:54:01 by lubrun      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_img		*new_image(t_map_info *map_info)
{
	t_img	*img;

	img = ft_memalloc(sizeof(t_img));
	img->ptr = mlx_new_image(map_info->mlx_ptr, map_info->win_size_x,
	map_info->win_size_y);
	img->img = (int *)mlx_get_data_addr(img->ptr, &(img->bpp),
	&(img->szl), &(img->endian));
	return (img);
}

t_point_3d	new_point_3d(int x, int y, int z)
{
	t_point_3d	point;

	point.x = x;
	point.y = y;
	point.z = z;
	return (point);
}

t_point_2d	new_point_2d(float x, float y)
{
	t_point_2d	point;

	point.x = x;
	point.y = y;
	return (point);
}

t_vector_2d	new_vector_2d(float x, float y)
{
	t_vector_2d	vector;

	vector.x = x;
	vector.y = y;
	return (vector);
}

t_map_info	*new_map_info(void)
{
	t_map_info	*new;

	if (!(new = ft_memalloc(sizeof(t_map_info))))
		return (NULL);
	new->map = NULL;
	new->win_size_x = 1500;
	new->win_size_y = 1500;
	new->map_size_x = 0;
	new->map_size_y = 0;
	return (new);
}

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_utils2.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/08 14:03:27 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/21 17:29:03 by lubrun      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	free_map(int **map, int size)
{
	int		index;

	index = 0;
	while (index < size)
	{
		free(map[index]);
		index++;
	}
	free(map);
}

void		free_map_info(t_map_info **amap_info)
{
	t_map_info	*map_info;

	map_info = *amap_info;
	free(map_info->mlx_ptr);
	free(map_info->win_ptr);
	free_map(map_info->map, map_info->map_size_y);
	free(map_info->img);
	free(map_info);
}

void		close_me(t_map_info **amap_info)
{
	t_map_info		*map_info;

	map_info = *amap_info;
	mlx_destroy_image(map_info->mlx_ptr, map_info->img->ptr);
	free_map_info(amap_info);
	exit(0);
}

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_utils.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <lubrun@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/16 18:06:37 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/22 14:56:09 by lubrun      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	set_line(t_point_2d *step, t_point_2d src, t_point_2d dst)
{
	step->x = dst.x - src.x;
	step->y = dst.y - src.y;
}

static void	new_point(t_point_2d *pos, t_point_2d src, int i, t_point_2d step)
{
	pos->x = src.x + i * step.x;
	pos->y = src.y + i * step.y;
}

static int	calc_step(t_point_2d *step)
{
	float			tmp;
	float			tmp1;
	int				n;

	tmp = ABS(step->x);
	tmp1 = ABS(step->y);
	if (tmp > tmp1)
	{
		n = ABS(step->x);
		step->y /= ABS(step->x);
		step->x /= ABS(step->x);
	}
	else
	{
		n = ABS(step->y);
		step->x /= ABS(step->y);
		step->y /= ABS(step->y);
	}
	return (n);
}

void		draw_line(t_map_info *map_info, t_point_2d src,
	t_point_2d dst, int color)
{
	t_point_2d		step;
	t_point_2d		pos;
	int				n;
	int				i;

	i = -1;
	set_line(&step, src, dst);
	n = calc_step(&step);
	while (++i < n)
	{
		new_point(&pos, src, i, step);
		if ((pos.x >= 0 && pos.x < map_info->win_size_x) &&
		(pos.y >= 0 && pos.y < map_info->win_size_y))
		{
			map_info->img->img[((int)pos.y *
			map_info->win_size_y + (int)pos.x)] = color;
		}
	}
}

void		place_points(t_map_info *map_info)
{
	t_point_3d	point;
	t_point_2d	proj;

	point = new_point_3d(0, 0, 0);
	while (point.y < map_info->map_size_y)
	{
		point.x = 0;
		while (point.x < map_info->map_size_x)
		{
			point.z = map_info->map[point.y][point.x];
			proj = calc_proj(map_info, point);
			check_line(point, proj, map_info);
			point.x++;
		}
		point.y++;
	}
	mlx_put_image_to_window(map_info->mlx_ptr,
	map_info->win_ptr, map_info->img->ptr, 0, 0);
}

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <lubrun@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/14 01:45:22 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/22 11:55:53 by lubrun      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define ABS(x)  ( (x<0) ? -(x) : x )

# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <stdio.h>
# include <fcntl.h>

typedef struct			s_img
{
	void				*ptr;
	int					*img;
	int					bpp;
	int					szl;
	int					endian;
}						t_img;

typedef struct			s_point_3d
{
	int					x;
	int					y;
	int					z;
}						t_point_3d;

typedef struct			s_point_2d
{
	float				x;
	float				y;
}						t_point_2d;

typedef struct			s_vector_2d
{
	float				x;
	float				y;
}						t_vector_2d;

typedef struct			s_map_info
{
	void				*mlx_ptr;
	void				*win_ptr;
	int					**map;
	struct s_img		*img;
	struct s_point_3d	zero;
	struct s_vector_2d	x_vector;
	struct s_vector_2d	y_vector;
	struct s_vector_2d	z_vector;
	int					win_size_y;
	int					win_size_x;
	int					map_size_y;
	int					map_size_x;
	float				z_scale;
	float				scale;
}						t_map_info;

t_map_info				*new_map_info();
t_img					*new_image(t_map_info *map_info);
t_point_3d				new_point_3d(int x, int y, int z);
t_point_2d				new_point_2d(float x, float y);
t_point_2d				calc_proj(t_map_info *map_info, t_point_3d point);
t_vector_2d				new_vector_2d(float x, float y);
int						parse_map(int fd, t_map_info **amap);
void					place_points(t_map_info *map_info);
void					rotate_iso(t_map_info **amap_info);
void					move_right(t_map_info **amap_info);
void					move_left(t_map_info **amap_info);
void					move_up(t_map_info **amap_info);
void					move_down(t_map_info **amap_info);
void					rescale(t_map_info **amap_info, float scale);
void					rescale_z(t_map_info **amap_info, float mult);
void					rotate180(t_map_info **amap_info);
void					switch_proj(t_map_info **amap_info, int index);
void					check_line(t_point_3d point, t_point_2d proj,
		t_map_info *map_info);
void					draw_line(t_map_info *map_info, t_point_2d src,
		t_point_2d dst, int color);
void					free_map_info(t_map_info **amap_info);
void					close_me(t_map_info **amap_info);

#endif

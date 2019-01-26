/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parser.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <lubrun@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/14 02:56:30 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/23 13:10:38 by lubrun      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	fill_tab(t_map_info **amap, char ***asplit, int index)
{
	t_map_info	*map_inf;
	char		**split;
	int			index1;

	map_inf = *amap;
	split = *asplit;
	index1 = 0;
	map_inf->map[index] = ft_newint_tab(map_inf->map_size_x, 0);
	while (split[index1])
	{
		map_inf->map[index][index1] = ft_atoi(split[index1]);
		index1++;
	}
}

int		parse_tab(char **tab, t_map_info **amap)
{
	t_map_info	*map_inf;
	char		**split;
	int			index;
	int			index1;

	map_inf = *amap;
	index = 0;
	index1 = 0;
	while (tab[index])
	{
		split = ft_strsplit(tab[index], ' ');
		index1 = 0;
		if (index == 0)
		{
			map_inf->map_size_x = ft_tablen((void **)split);
			map_inf->map = ft_memalloc(sizeof(int*) * (*amap)->map_size_y);
		}
		else if ((int)ft_tablen((void **)split) != (*amap)->map_size_x)
			return (-1);
		fill_tab(amap, &split, index);
		index++;
		ft_2dstrdel(&split);
	}
	ft_2dstrdel(&tab);
	return (1);
}

int		parse_map(int fd, t_map_info **amap)
{
	char	*line;
	char	*tmp;
	int		len;
	int		ret;

	line = NULL;
	tmp = ft_strnew(0);
	len = 0;
	ret = 0;
	if (fd < 0)
		return (-1);
	(*amap) = new_map_info();
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		tmp = ft_strjoin(tmp, line, 3);
		tmp = ft_strjoin(tmp, ft_strdup("|"), 3);
		len++;
	}
	(*amap)->map_size_y = len;
	if (ret == -1)
		return (ret);
	parse_tab(ft_strsplit(tmp, '|'), amap);
	ft_strdel(&tmp);
	return (1);
}

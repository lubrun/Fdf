/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_newint_tab.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/07 14:46:12 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/07 15:23:04 by lubrun      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		*ft_newint_tab(int size, int value)
{
	int		*tab;
	int		index;

	if (!(tab = ft_memalloc(sizeof(int) * size)))
		return (NULL);
	index = 0;
	while (index < size)
	{
		tab[index] = value;
		index++;
	}
	return (tab);
}

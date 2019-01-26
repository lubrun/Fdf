/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lltoa_base.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <lubrun@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/24 01:13:31 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2018/12/05 12:05:31 by lubrun      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int static	get_len(long long nb, int base)
{
	int		len;
	long	n;

	len = 0;
	n = nb;
	if (nb < 0)
		n = nb * -1;
	while (n > 0)
	{
		n  /= base;
		len++;
	}
	return (len);
}

char		*ft_lltoa_base(long long nb, int base)
{
	char	*str;
	int		len;

	len = get_len(nb, base);
	if (!(str = ft_strnew(len + 1)))
		return (NULL);
	str[len--] = '\0';
	if (nb < 0)
	{
		str[0] = '-';
		nb *= -1;
	}
	if (nb == 0)
	{
		str[0] = 48;
		return (str);
	}
	while (nb > 0)
	{
		if (nb % base >= 10)
			str[len] = ('a' - 10) + (nb % base);
		else
			str[len] = '0' + (nb % base);
		nb /= base;
		len--;
	}
	return (str);
}
/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_unbrlen.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lubrun <lubrun@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/19 15:53:22 by lubrun       #+#   ##    ##    #+#       */
/*   Updated: 2018/11/27 13:13:38 by lubrun      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int     ft_unbrlen(unsigned long long nbr, int base)
{
    int     len;

    len = 0;
    if (nbr == 0)
        return (1);
    while (nbr >= (unsigned int)base)
    {
        len++;
        nbr /= base;
    }
    if (nbr > 0)
        len++;
    return (len);
}
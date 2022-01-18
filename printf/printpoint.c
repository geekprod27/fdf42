/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printpoint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 12:06:06 by nfelsemb          #+#    #+#             */
/*   Updated: 2021/12/02 16:51:13 by nfelsemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print2(char *res, int i)
{
	int	j;

	j = 0;
	while (res[i] == '0')
		i++;
	while (i < 9 && res[i])
	{
		ft_putchar (res[i++]);
		j++;
	}
	return (j);
}

int	printpoint(void *s)
{
	unsigned long	adr;
	char const		*base;
	char			res[9];
	int				i;

	adr = (unsigned long) s;
	if (adr == 0)
		return (ft_putstr("0"));
	base = "0123456789abcdef";
	i = 8;
	if (adr == 0)
		return (ft_putstr("0"));
	while ((adr / 16) > 0 || i >= 8)
	{
		res[i] = base[(adr % 16)];
		adr /= 16;
		i--;
	}
	res[i] = base[(adr % 16)];
	return (print2(res, i));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:15:01 by nfelsemb          #+#    #+#             */
/*   Updated: 2021/12/03 11:32:04 by nfelsemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	spe(char c, va_list ap)
{
	if (c == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (c == 'd')
		return (ft_putnbr(va_arg(ap, int), 0));
	else if (c == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (c == 'p')
	{
		ft_putstr("0x");
		return (2 + printpoint(va_arg(ap, void *)));
	}
	else if (c == 'i')
		return (ft_putnbr(va_arg(ap, int), 0));
	else if (c == 'u')
		return (ft_putunnbr(va_arg(ap, unsigned int), 0));
	else if (c == 'x')
		return (exa(va_arg(ap, unsigned int)));
	else if (c == 'X')
		return (mexa(va_arg(ap, unsigned int)));
	else if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	va_list	ap;
	int		cc;

	va_start(ap, s);
	i = 0;
	cc = 0;
	while (s[i] != '\0' )
	{
		while (s[i] != '%' && s[i] != '\0')
		{
			ft_putchar(s[i]);
			i++;
			cc++;
		}
		if ((s[i] == 's' || s[i] == 'c' || s[i] == 'p' || s[i] == 'd'
				|| s[i] == 'i' || s[i] == 'u' || s[i] == 'x'
				|| s[i] == 'X' || s[i] == '%' ) && s[++i] != '\0')
			cc = cc + spe(s[i], ap);
		if (s[i])
			i++;
	}
	va_end(ap);
	return (cc);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:22:29 by nfelsemb          #+#    #+#             */
/*   Updated: 2021/12/02 16:52:53 by nfelsemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdarg.h>

int		ft_putchar(char c);
int		ft_printf(const char *s, ...);
int		ft_putnbr(int n, int i);
int		ft_putunnbr(unsigned int n, int i);
int		ft_putstr(char *s);
int		printpoint(void *s);
int		mexa(unsigned int nb);
int		exa(unsigned int nb);
int		print2(char *res, int i);

#endif

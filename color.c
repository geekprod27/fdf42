/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.frn>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 17:25:07 by nfelsemb          #+#    #+#             */
/*   Updated: 2022/01/23 10:06:27 by nfelsemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	colorplus(t_point p, t_mlx *ptr)
{
	mlx_clear_window(ptr->mlx_ptr, ptr->mlx_win);
	ptr->color = ptr->color + 100;
	if (ptr->color >= 16777215)
		ptr->color = 0;
	ft_printf("Couleur actuel : %X\n", ptr->color);
	close(ptr->fd);
	ptr->fd = open(ptr->file, O_RDONLY);
	start(ptr->fd, *ptr, p);
}

void	colormoin(t_point p, t_mlx *ptr)
{
	mlx_clear_window(ptr->mlx_ptr, ptr->mlx_win);
	ptr->color = ptr->color - 100;
	if (ptr->color <= 0)
		ptr->color = 16777215;
	ft_printf("Couleur actuel : %X\n", ptr->color);
	close(ptr->fd);
	ptr->fd = open(ptr->file, O_RDONLY);
	start(ptr->fd, *ptr, p);
}
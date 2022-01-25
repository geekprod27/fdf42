/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 17:25:07 by nfelsemb          #+#    #+#             */
/*   Updated: 2022/01/25 14:19:29 by nfelsemb         ###   ########.fr       */
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

void	reset(t_point p, t_mlx *ptr)
{
	mlx_clear_window(ptr->mlx_ptr, ptr->mlx_win);
	ptr->x = 750;
	ptr->y = 50;
	p.x = 750;
	p.y = 50;
	ptr->taille = 0;
	ptr->color = 0xFFFFFF;
	ptr->mul = 1;
	close(ptr->fd);
	ptr->fd = open(ptr->file, O_RDONLY);
	start(ptr->fd, *ptr, p);
}

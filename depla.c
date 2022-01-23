/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   depla.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.frn>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 13:22:10 by nfelsemb          #+#    #+#             */
/*   Updated: 2022/01/22 17:10:01 by nfelsemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	haut(t_point p, t_mlx *ptr)
{
	mlx_clear_window(ptr->mlx_ptr, ptr->mlx_win);
	ptr->y = ptr->y - 10;
	close(ptr->fd);
	ptr->fd = open(ptr->file, O_RDONLY);
	start(ptr->fd, *ptr, p);
}

void	bas(t_point p, t_mlx *ptr)
{
	mlx_clear_window(ptr->mlx_ptr, ptr->mlx_win);
	ptr->y = ptr->y + 10;
	close(ptr->fd);
	ptr->fd = open(ptr->file, O_RDONLY);
	start(ptr->fd, *ptr, p);
}

void	gauche(t_point p, t_mlx *ptr)
{
	mlx_clear_window(ptr->mlx_ptr, ptr->mlx_win);
	ptr->x = ptr->x - 10;
	close(ptr->fd);
	ptr->fd = open(ptr->file, O_RDONLY);
	start(ptr->fd, *ptr, p);
}

void	droite(t_point p, t_mlx *ptr)
{
	mlx_clear_window(ptr->mlx_ptr, ptr->mlx_win);
	ptr->x = ptr->x + 10;
	close(ptr->fd);
	ptr->fd = open(ptr->file, O_RDONLY);
	start(ptr->fd, *ptr, p);
}

void	dezoom(t_point p, t_mlx *ptr)
{
	mlx_clear_window(ptr->mlx_ptr, ptr->mlx_win);
	ptr->taille = ptr->taille - 2;
	close(ptr->fd);
	ptr->fd = open(ptr->file, O_RDONLY);
	start(ptr->fd, *ptr, p);
}

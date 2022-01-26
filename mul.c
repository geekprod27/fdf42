/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mul.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:37:40 by nfelsemb          #+#    #+#             */
/*   Updated: 2022/01/26 14:35:47 by nfelsemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	mulmoin(t_point p, t_mlx *ptr)
{
	mlx_clear_window(ptr->mlx_ptr, ptr->mlx_win);
	ptr->mul = ptr->mul - 1;
	close(ptr->fd);
	ptr->fd = open(ptr->file, O_RDONLY);
	start(ptr->fd, *ptr, p);
}

void	mulplus(t_point p, t_mlx *ptr)
{
	mlx_clear_window(ptr->mlx_ptr, ptr->mlx_win);
	ptr->mul = ptr->mul + 1;
	close(ptr->fd);
	ptr->fd = open(ptr->file, O_RDONLY);
	start(ptr->fd, *ptr, p);
}

void	zoom(t_point p, t_mlx *ptr)
{
	mlx_clear_window(ptr->mlx_ptr, ptr->mlx_win);
	ptr->taille = ptr->taille + 2;
	close(ptr->fd);
	ptr->fd = open(ptr->file, O_RDONLY);
	start(ptr->fd, *ptr, p);
}

void	uno(t_mlx *ptr, t_point *un, t_point *de, t_point d)
{
	int	e;

	e = d.x;
	d.x = e * 2;
	d.y = d.y * 2;
	while (1)
	{
		mlx_pixel_put(ptr->mlx_ptr, ptr->mlx_win, un->x, un->y, ptr->color);
		un->x = un->x + 1;
		if (un->x == de->x)
			break ;
		e = e - d.y;
		if (e < 0)
		{
			un->y = un->y + 1;
			e = e + d.x;
		}
	}
}

void	deux(t_mlx *ptr, t_point *un, t_point *de, t_point d)
{
	int	e;

	e = d.y;
	d.y = e * 2;
	d.x = d.x * 2;
	while (1)
	{
		mlx_pixel_put(ptr->mlx_ptr, ptr->mlx_win, un->x, un->y, ptr->color);
		un->y = un->y + 1;
		if (un->y == de->y)
			break ;
		e = e - d.x;
		if (e < 0)
		{
			un->x = un->x + 1;
			e = e + d.y;
		}
	}
}

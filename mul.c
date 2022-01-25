/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mul.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:37:40 by nfelsemb          #+#    #+#             */
/*   Updated: 2022/01/24 16:59:00 by nfelsemb         ###   ########.fr       */
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

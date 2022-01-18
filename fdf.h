/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.frn>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:05:23 by nfelsemb          #+#    #+#             */
/*   Updated: 2022/01/14 13:08:53 by nfelsemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "minilibx/mlx.h"
#include "printf/ft_printf.h"
#include "gnl/get_next_line.h"
#include "libft/libft.h"
#include <fcntl.h>

void	segment(int x1, int y1, int x2, int y2, void *mlx_ptr, void *mlx_win);

#endif

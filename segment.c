/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segment.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.frn>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 13:00:44 by nfelsemb          #+#    #+#             */
/*   Updated: 2022/01/22 17:24:03 by nfelsemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	seg(t_point un, t_point de, t_mlx ptr)
{
	int	dx;
	int	dy;
	int	e;

	dx = de.x - un.x;
	dy = de.y - un.y;
	if (dx != 0)
	{
		if (dx > 0)
		{
			if (dy != 0)
			{
				if (dy > 0)
				{
					if (dx >= dy)
					{
						e = dx;
						dx = e * 2;
						dy = dy * 2;
						while (1)
						{
							mlx_pixel_put(ptr.mlx_ptr, ptr.mlx_win, un.x, un.y, ptr.color);
							un.x = un.x + 1;
							if (un.x == de.x)
								break ;
							e = e - dy;
							if (e < 0)
							{
								un.y = un.y + 1;
								e = e + dx;
							}
						}
					}
					else
					{
						e = dy;
						dy = e * 2;
						dx = dx * 2;
						while (1)
						{
							mlx_pixel_put(ptr.mlx_ptr, ptr.mlx_win, un.x, un.y, ptr.color);
							un.y = un.y + 1;
							if (un.y == de.y)
								break ;
							e = e - dx;
							if (e < 0)
							{
								un.x = un.x + 1;
								e = e + dy;
							}
						}
					}
				}
				else
				{
					if (dx >= -dy)
					{
						e = dx;
						dx = e * 2;
						dy = dy * 2;
						while (1)
						{
							mlx_pixel_put(ptr.mlx_ptr, ptr.mlx_win, un.x, un.y, ptr.color);
							un.x = un.x + 1;
							if (un.x == de.x)
								break ;
							e = e + dy;
							if (e < 0)
							{
								un.y = un.y - 1;
								e = e + dx;
							}
						}
					}
					else
					{
						e = dy;
						dy = e * 2;
						dx = dx * 2;
						while (1)
						{
							mlx_pixel_put(ptr.mlx_ptr, ptr.mlx_win, un.x, un.y, ptr.color);
							un.y = un.y - 1;
							if (un.y == de.y)
								break ;
							e = e + dx;
							if (e > 0)
							{
								un.x = un.x + 1;
								e = e + dy;
							}
						}
					}
				}
			}
			else
			{
				while (un.x != de.x)
				{
					mlx_pixel_put(ptr.mlx_ptr, ptr.mlx_win, un.x, un.y, ptr.color);
					un.x = un.x + 1;
				}
			}
		}
		else
		{
			if (dy != 0)
			{
				if (dy > 0)
				{
					if (-dx >= dy)
					{
						e = dx;
						dx = dx * 2;
						dy = dy * 2;
						while (1)
						{
							mlx_pixel_put(ptr.mlx_ptr, ptr.mlx_win, un.x, un.y, ptr.color);
							un.x = un.x - 1;
							if (un.x == de.x)
								break ;
							e = e + dy;
							if (e >= 0)
							{
								un.y = un.y + 1;
								e = e + dx;
							}
						}
					}
					else
					{
						e = dy;
						dy = e * 2;
						dx = dx * 2;
						while (1)
						{
							mlx_pixel_put(ptr.mlx_ptr, ptr.mlx_win, un.x, un.y, ptr.color);
							un.y = un.y + 1;
							if (un.y == de.y)
								break ;
							e = e + dx;
							if (e <= 0)
							{
								un.x = un.x - 1;
								e = e + dy;
							}
						}
					}
				}
				else
				{
					if (dx <= dy)
					{
						e = dy;
						dy = e * 2;
						dx = dx * 2;
						while (1)
						{
							mlx_pixel_put(ptr.mlx_ptr, ptr.mlx_win, un.x, un.y, ptr.color);
							un.x = un.x - 1;
							if (un.x == de.x)
								break ;
							e = e - dy;
							if (e >= 0)
							{
								un.y = un.y - 1;
								e = e + dx;
							}
						}
					}
					else
					{
						e = dy;
						dy = e * 2;
						dx = dx * 2;
						while (1)
						{
							mlx_pixel_put(ptr.mlx_ptr, ptr.mlx_win, un.x, un.y, ptr.color);
							un.y = un.y - 1;
							if (un.y == de.y)
								break ;
							e = e - dx;
							if (e >= 0)
							{
								un.x = un.x - 1;
								e = e + dy;
							}
						}
					}
				}
			}
			else
			{
				while (un.x != de.x)
				{
					mlx_pixel_put(ptr.mlx_ptr, ptr.mlx_win, un.x, un.y, ptr.color);
					un.x = un.x - 1;
				}
			}
		}
	}
	else
	{
		dy = de.y - un.y;
		if (dy != 0)
		{
			if (dy > 0)
			{
				while (un.y != de.y)
				{
					mlx_pixel_put(ptr.mlx_ptr, ptr.mlx_win, un.x, un.y, ptr.color);
					un.y = un.y + 1;
				}
			}
			else
			{
				while (un.y != de.y)
				{
					mlx_pixel_put(ptr.mlx_ptr, ptr.mlx_win, un.x, un.y, ptr.color);
					un.y = un.y - 1;
				}
			}
		}
	}
	mlx_pixel_put(ptr.mlx_ptr, ptr.mlx_win, de.x, de.y, ptr.color);
}

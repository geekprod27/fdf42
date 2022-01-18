/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segment.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.frn>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 13:00:44 by nfelsemb          #+#    #+#             */
/*   Updated: 2022/01/17 08:35:24 by nfelsemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	segment(int x1, int y1, int x2, int y2, void *mlx_ptr, void *mlx_win)
{
	int dx;
	int dy;
	int e;

	dx = x2 - x1;
	dy = y2 - y1;
	if (dx != 0)
	{
		if (dx > 0)
		{
			if(dy != 0)
			{
				if(dy > 0)
				{
					if(dx >= dy)
					{
						e = dx;
						dx = e * 2;
						dy = dy * 2;
						while (1)
						{
							mlx_pixel_put(mlx_ptr, mlx_win, x1, y1, 0xFFFFFF);
							x1 = x1 + 1;
							if(x1 == x2)
								break;
							e = e - dy;
							if (e < 0)
							{
								y1 = y1 + 1;
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
							mlx_pixel_put(mlx_ptr, mlx_win, x1, y1, 0xFFFFFF);
							y1 = y1 + 1;
							if (y1 == y2)
								break;
							e = e - dx;
							if (e < 0)
							{
								x1 = x1 + 1;
								e = e + dy;
							}
						}
					}
				}
				else
				{
					if(dx >= -dy)
					{
						e = dx;
						dx = e * 2;
						dy = dy * 2;
						while (1)
						{
							mlx_pixel_put(mlx_ptr, mlx_win, x1, y1, 0xFFFFFF);
							x1 = x1 + 1;
							if (x1 == x2)
								break;
							e = e + dy;
							if (e < 0)
							{
								y1 = y1 - 1;
								e = e + dx;
							} 
						}
					}
					else
					{
						e = dy;
						dy = e *2;
						dx = dx * 2;
						while (1)
						{
							mlx_pixel_put(mlx_ptr, mlx_win, x1, y1, 0xFFFFFF);
							y1 = y1 - 1;
							if (y1 == y2)
								break;
							e = e + dx;
							if(e > 0)
							{
								x1 = x1 + 1;
								e = e + dy;
							}
						}
					}
				}
			}
			else
			{
				while(x1 != x2)
				{
					mlx_pixel_put(mlx_ptr, mlx_win, x1, y1, 0xFFFFFF);
					x1 = x1 + 1;
				}
			}
		}
		else
		{
			if(dy != 0)
			{
				if(dy > 0)
				{
					if(-dx >= dy)
					{
						e = dx;
						dx = dx * 2;
						dy = dy * 2;
						while (1)
						{
							mlx_pixel_put(mlx_ptr, mlx_win, x1, y1, 0xFFFFFF);
							x1 = x1 - 1;
							if (x1 == x2)
								break;
							e = e + dy;
							if(e >= 0)
							{
								y1 = y1 + 1;
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
							mlx_pixel_put(mlx_ptr, mlx_win, x1, y1, 0xFFFFFF);
							y1 = y1 + 1;
							if (y1 == y2)
								break;
							e = e + dx;
							if (e <= 0)
							{
								x1 = x1 - 1;
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
							mlx_pixel_put(mlx_ptr, mlx_win, x1, y1, 0xFFFFFF);
							x1 = x1 - 1;
							if (x1 == x2)
								break;
							e = e - dy;
							if (e >= 0)
							{
								y1 = y1 - 1;
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
							mlx_pixel_put(mlx_ptr, mlx_win, x1, y1, 0xFFFFFF);
							y1 = y1 - 1;
							if (y1 == y2)
								break;
							e = e - dx;
							if (e >= 0)
							{
								x1 = x1 - 1;
								e = e + dy;
							}
						}
					}
				}
			}
			else
			{
				while(x1 != x2)
				{
					mlx_pixel_put(mlx_ptr, mlx_win, x1, y1, 0xFFFFFF);
					x1 = x1 - 1;
				}
			}
		}
	}
	else
	{
		dy = y2 - y1;
		if(dy != 0)
		{
			if (dy > 0)
			{
				while(y1 != y2)
				{
					mlx_pixel_put(mlx_ptr, mlx_win, x1, y1, 0xFFFFFF);
					y1 = y1 + 1;
				}
			}
			else
			{
				while(y1 != y2)
				{
					mlx_pixel_put(mlx_ptr, mlx_win, x1, y1, 0xFFFFFF);
					y1 = y1 - 1;
				}
			}
		}
	}
	mlx_pixel_put(mlx_ptr, mlx_win, x2, y2, 0xFFFFFF);
}

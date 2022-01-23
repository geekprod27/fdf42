/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.frn>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:05:23 by nfelsemb          #+#    #+#             */
/*   Updated: 2022/01/22 17:30:49 by nfelsemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "minilibx/mlx.h"
# include "printf/ft_printf.h"
# include "gnl/get_next_line.h"
# include "libft/libft.h"
# include <fcntl.h>

typedef struct s_mlx	t_mlx;
struct s_mlx
{
	void	*mlx_ptr;
	void	*mlx_win;
	int		fd;
	int		x;
	int		y;
	char	*file;
	int		taille;
	int		color;
};

typedef struct s_point	t_point;
struct s_point
{
	int		x;
	int		y;
	int		t;
};

void	seg(t_point un, t_point de, t_mlx ptr);
void	start(int fd, t_mlx ptr, t_point p);
int		comppoint(char *str);
t_point	firstline(int *tab, t_point p, t_mlx t);
void	line(char *line, int *tab, t_point p, t_mlx t);
t_point	autreline(int *tab, t_point p, t_mlx t, int *tab2);
int		*ft_intdup(int *tab);
int		*getint(char *line);
void	haut(t_point p, t_mlx *ptr);
void	bas(t_point p, t_mlx *ptr);
void	gauche(t_point p, t_mlx *ptr);
void	droite(t_point p, t_mlx *ptr);
void	dezoom(t_point p, t_mlx *ptr);
void	colormoin(t_point p, t_mlx *ptr);
void	colorplus(t_point p, t_mlx *ptr);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.frn>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:56:39 by nfelsemb          #+#    #+#             */
/*   Updated: 2022/01/22 17:39:17 by nfelsemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom(t_point p, t_mlx *ptr)
{
	mlx_clear_window(ptr->mlx_ptr, ptr->mlx_win);
	ptr->taille = ptr->taille + 2;
	close(ptr->fd);
	ptr->fd = open(ptr->file, O_RDONLY);
	start(ptr->fd, *ptr, p);
}

int	receptext(int key, void *param)
{
	t_mlx	*ptr;
	t_point	p;

	ptr = (t_mlx *) param;
	p.x = ptr->x;
	p.y = ptr->y;
	if (key == 65307)
		exit(3);
	else if (key == 65362)
		haut(p, ptr);
	else if (key == 65364)
		bas(p, ptr);
	else if (key == 65361)
		gauche(p, ptr);
	else if (key == 65363)
		droite(p, ptr);
	else if (key == 115)
		dezoom(p, ptr);
	else if (key == 122)
		zoom(p, ptr);
	else if (key == 97)
		mlx_clear_window(ptr->mlx_ptr, ptr->mlx_win);
	else if (key == 111)
		colorplus(p, ptr);
	else if (key == 112)
		colormoin(p, ptr);
	return (0);
}

t_mlx	initptr(int ret, char *file)
{
	t_mlx	ptr;

	ptr.mlx_ptr = mlx_init();
	ptr.mlx_win = mlx_new_window(ptr.mlx_ptr, 1500, 1300, "FDF");
	ptr.fd = ret;
	ptr.x = 750;
	ptr.y = 50;
	ptr.taille = 0;
	ptr.file = file;
	ptr.color = 0xFFFFFF;
	return (ptr);
}

int	main(int argc, char **argv)
{
	t_mlx	ptr;
	t_mlx	*la;
	int		ret;
	t_point	p;

	if (argc != 2)
	{
		ft_printf("/!\\ Erreur d'argument /!\\\n");
		exit(1);
	}
	ret = open(argv[1], O_RDONLY);
	if (ret == -1)
	{
		ft_printf("/!\\ L\'ouverture du fichier : \"%s\"", argv[1]);
		ft_printf(", a rencontrer une erreur /!\\\n");
		exit(10);
	}
	p.x = 750;
	p.y = 50;
	ptr = initptr(ret, argv[1]);
	la = &ptr;
	mlx_key_hook(ptr.mlx_win, receptext, la);
	start(ret, ptr, p);
	mlx_do_key_autorepeaton(ptr.mlx_ptr);
	mlx_loop(ptr.mlx_ptr);
}

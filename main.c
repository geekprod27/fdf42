/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:56:39 by nfelsemb          #+#    #+#             */
/*   Updated: 2022/01/26 13:34:38 by nfelsemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	recepsou(int key, int x, int y, void *param)
{
	t_mlx	*ptr;
	t_point	p;

	if (key == M_CLK_L)
	{
		ptr = (t_mlx *) param;
		mlx_clear_window(ptr->mlx_ptr, ptr->mlx_win);
		ptr->x = x;
		ptr->y = y;
		p.x = ptr->x;
		p.y = ptr->y;
		close(ptr->fd);
		ptr->fd = open(ptr->file, O_RDONLY);
		start(ptr->fd, *ptr, p);
	}
	return (0);
}

void	recpetext2(int key, t_mlx *ptr, t_point p)
{
	if (key == K_O)
		colorplus(p, ptr);
	else if (key == K_P)
		colormoin(p, ptr);
	else if (key == K_M)
		mulmoin(p, ptr);
	else if (key == K_K)
		mulplus(p, ptr);
	else if (key == K_R)
		reset(p, ptr);
	else if (key == K_S)
		dezoom(p, ptr);
	else if (key == K_Z)
		zoom(p, ptr);
}

int	receptext(int key, void *param)
{
	t_mlx	*ptr;
	t_point	p;

	ptr = (t_mlx *) param;
	p.x = ptr->x;
	p.y = ptr->y;
	if (key == K_ESC)
	{
		mlx_destroy_window(ptr->mlx_ptr, ptr->mlx_win);
		free(ptr->mlx_ptr);
		exit(3);
	}
	else if (key == K_AR_U)
		haut(p, ptr);
	else if (key == K_AR_D)
		bas(p, ptr);
	else if (key == K_AR_L)
		gauche(p, ptr);
	else if (key == K_AR_R)
		droite(p, ptr);
	else
		recpetext2(key, ptr, p);
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
	ptr.mul = 1;
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
	mlx_mouse_hook(ptr.mlx_win, recepsou, la);
	start(ret, ptr, p);
	mlx_loop(ptr.mlx_ptr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:56:39 by nfelsemb          #+#    #+#             */
/*   Updated: 2022/01/20 15:11:31 by nfelsemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	start(int fd, t_mlx ptr, int tai, int y);

int	receptext(int key, void *param)
{
	if (key == 65307)
		exit(3);
	(void) param;
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx	ptr;
	int		ret;

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
	ptr.mlx_ptr = mlx_init();
	ptr.mlx_win = mlx_new_window(ptr.mlx_ptr, 2200, 1300, "mlx test410");
	mlx_key_hook(ptr.mlx_win, receptext, (void *)0);
	start(ret, ptr, 0, 0);
	mlx_loop(ptr.mlx_ptr);
}

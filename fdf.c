/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.frn>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1001/01/11 07:00:00 by  by nfelsem       #+#    #+#             */
/*   Updated: 2022/01/18 09:53:26 by nfelsemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void * win_ptr;
void * ptr_mlx;

int	receptext(int key, void *param)
{
	if (key == 65307)
		exit(3);
	else if(key == 119)
	{

	}
	(void) param;
	return (0);
}

int	comppoint(char *str)
{
	int	i;
	int	cont;

	i = 0;
	cont = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		if (str[i] == ',')
		{
			while(str[i] != ' ' && str[i])
				i++;
		}
		else if (ft_isdigit(str[i]))
		{
			cont++;
			while (ft_isdigit(str[i]))
				i++;
		}
		else
			i++;
	}
	//ft_printf("%d\n", cont);
	return (cont);
}

int *getint(char *line)
{
	int *tab;
	int	i;

	i = 0;
	tab = malloc(sizeof(int) * ((comppoint(line) + 1)));
	while(*line != '\n' && *line)
	{
		tab[i] = ft_atoi(line);
		i++;
		while(ft_isdigit(*line) && *line)
			line++;
		if (*line == ',')
		{
			while(*line != ' ' && *line)
				line++;
		}
		while(!ft_isdigit(*line) && *line)
			line++;
		//ft_printf("%d\n", i);
		
	}
	tab[i] = 10585510;
	return (tab);
}

int *ft_intdup(int *tab)
{
	int *ret;
	int i;

	i = 0;
	while (tab[i] != 10585510)
		i++;
	ret = malloc(sizeof(int) * (i + 1));
	i = 0;
	while (tab[i] != 10585510)
	{
		ret[i] = tab[i];
		i++;
	}
	ret[i] = 10585510;
	return (ret);
}

void	start(int fd, void *mlx_ptr, void *mlx_win)
{
	char 	*line;
	int 	i;
	int		x;
	int		y;
	int		*tab;
	int		*tab2;
	int		taille;

	line = get_next_line(fd);
	taille = 1000 / (comppoint(line) * 2);
	x = 500;
	y = 100;
	i = 0;
	tab = getint(line);
	while (tab[i] != 10585510)
	{
		if (tab[i + 1] != 10585510)
			segment(x, y - tab[i], x + taille, y + (taille/2) - tab[i + 1], mlx_ptr, mlx_win);
		x = x + taille;
		y = y + (taille/2);
		i++;
	}
	line = get_next_line(fd);
	tab2 = ft_intdup(tab);
	while (line)
	{
		
		x = (x - (taille * comppoint(line))) - taille;
		y = (y - ((taille/2) * comppoint(line))) + (taille/2);
		i = 0;
		if (tab)
			free(tab);
		tab = getint(line);
		while (tab[i] != 10585510)
		{
			if (tab[i + 1] != 10585510)
				segment(x, y - tab[i], x + taille, y + (taille/2) - tab[i + 1], mlx_ptr, mlx_win);
			segment(x, y - tab[i], x + taille, y - (taille/2) - tab2[i], mlx_ptr, mlx_win);
			x = x + taille;
			y = y + (taille/2);
			i++;
		}
		free(line);
		free(tab2);
		tab2 = ft_intdup(tab);
		line = get_next_line(fd);
	}
}

int	mouse_hook(int but, int x, int y, void *param)
{
	static int x1;
	static int y1;
	static int x2;
	static int y2;

	//ft_printf("%d\n", but);
	if (but == 1)
	{
		x1 = x;
		y1 = y;
	}
	else if (but == 3)
	{
		x2 = x;
		y2 = y;

		ft_printf("x1=%d\ny1=%d\nx2=%d\ny2=%d\n\n\n", x1, y1, x2, y2);
		segment(x1, y1, x2, y2, ptr_mlx, win_ptr);
	}
	(void) param;
	return (0);
}

int main(int argc, char **argv)
{
	void	*mlx_ptr;
	void	*mlx_win;
	int		ret;

	if (argc != 2)
	{
		ft_printf("/!\\ Erreur d'argument /!\\\n");
		exit(1);
	}
	ret = open(argv[1], O_RDONLY);
	if (ret == -1)
	{
		ft_printf("/!\\ L\'ouverture du fichier : \"%s\", a rencontrer une erreur /!\\\n");
		exit(10);
	}
	mlx_ptr = mlx_init();
	mlx_win = mlx_new_window(mlx_ptr, 1000, 1000, "mlx test410");
	mlx_key_hook(mlx_win, receptext, (void *)0);
	ptr_mlx = mlx_ptr;
	win_ptr = mlx_win;
	mlx_mouse_hook(mlx_win, mouse_hook, (void *) 0);
	start(ret, mlx_ptr, mlx_win);
	mlx_loop(mlx_ptr);
}
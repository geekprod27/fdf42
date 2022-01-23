/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.frn>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1001/01/11 07:00:00 by  by nfelsem       #+#    #+#             */
/*   Updated: 2022/01/23 10:10:33 by nfelsemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
			while (str[i] != ' ' && str[i])
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
	return (cont);
}

int	*getint(char *line)
{
	int	*tab;
	int	i;

	i = 0;
	tab = malloc(sizeof(int) * ((comppoint(line) + 1)));
	while (*line != '\n' && *line)
	{
		tab[i] = ft_atoi(line);
		line++;
		i++;
		while (ft_isdigit(*line) && *line)
			line++;
		if (*line == ',')
		{
			while (*line != ' ' && *line)
				line++;
		}
		while ((!ft_isdigit(*line) && *line != '-') && *line)
			line++;
	}
	tab[i] = 10585510;
	return (tab);
}

int	*ft_intdup(int *tab)
{
	int	*ret;
	int	i;

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

void	start(int fd, t_mlx ptr, t_point p)
{
	char	*linne;
	int		tai;
	int		*tab;

	p.t = ptr.taille;
	linne = get_next_line(fd);
	tai = (1000 / (comppoint(linne))) + ptr.taille;
	if (tai <= 1)
		tai = 2;
	ptr.taille = tai;
	p.t = tai;
	tab = getint(linne);
	p = firstline(tab, p, ptr);
	line(linne, tab, p, ptr);
	free(linne);
	linne = get_next_line(fd);
	mlx_string_put(ptr.mlx_ptr, ptr.mlx_win, 10, 10, ptr.color, "Zoom : z");
	mlx_string_put(ptr.mlx_ptr, ptr.mlx_win, 10, 20, ptr.color, "Dezoom : s");
	mlx_string_put(ptr.mlx_ptr, ptr.mlx_win, 10, 30, ptr.color,
		"Deplacement : fleches directionnel");
	mlx_string_put(ptr.mlx_ptr, ptr.mlx_win, 10, 40, ptr.color,
		"Changement de couleur : o / p");
	mlx_string_put(ptr.mlx_ptr, ptr.mlx_win, 10, 50, ptr.color,
		"Quitter : Echap");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.frn>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1001/01/11 07:00:00 by  by nfelsem       #+#    #+#             */
/*   Updated: 2022/01/19 10:44:40 by nfelsemb         ###   ########.fr       */
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
	//ft_printf("%d\n", cont);
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
		i++;
		while (ft_isdigit(*line) && *line)
			line++;
		if (*line == ',')
		{
			while (*line != ' ' && *line)
				line++;
		}
		while (!ft_isdigit(*line) && *line)
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

void	start(int fd, t_mlx ptr, int tai, int y)
{
	char	*line;
	int		i;
	int		x;
	int		*tab2;
	int		*tab;

	line = get_next_line(fd);
	tai = 500 / (comppoint(line));
	if (tai == 1)
		tai = 2;
	x = 500;
	y = 50;
	i = 0;
	tab = getint(line);
	while (tab[i] != 10585510)
	{
		if (tab[i + 1] != 10585510)
			seg(x, y - tab[i], x + tai, y + (tai / 2) - tab[i + 1], ptr);
		x = x + tai;
		y = y + (tai / 2);
		i++;
	}
	free(line);
	line = get_next_line(fd);
	while (line)
	{
		tab2 = ft_intdup(tab);
		x = (x - (tai * comppoint(line))) - (tai);
		y = (y - ((tai / 2) * comppoint(line))) + (tai / 2);
		i = 0;
		if (tab)
			free(tab);
		tab = getint(line);
		while (tab[i] != 10585510)
		{
			if (tab[i + 1] != 10585510)
				seg(x, y - tab[i], x + tai, y + (tai / 2) - tab[i + 1], ptr);
			seg(x, y - tab[i], x + tai, y - (tai / 2) - tab2[i], ptr);
			x = x + tai;
			y = y + (tai / 2);
			i++;
		}
		free(line);
		line = get_next_line(fd);
	}
}

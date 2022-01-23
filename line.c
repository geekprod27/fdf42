/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.frn>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 12:12:03 by nfelsemb          #+#    #+#             */
/*   Updated: 2022/01/22 17:17:54 by nfelsemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	firstline(int *tab, t_point p, t_mlx t)
{
	int		i;
	t_point	un;
	t_point	de;

	i = 0;
	while (tab[i] != 10585510)
	{
		un.x = p.x;
		un.y = p.y - tab[i];
		if (tab[i + 1] != 10585510)
		{
			de.x = p.x + p.t;
			de.y = p.y + (p.t / 2) - tab[i + 1];
			if (un.x <= 1600 && un.x >= -100 && de.x <= 1600 && de.x >= -100
				&& un.y <= 1400 && un.y >= -100 && de.y <= 1400 && de.y >= -100)
				seg(un, de, t);
		}
		p.x = p.x + p.t;
		p.y = p.y + (p.t / 2);
		i++;
	}
	return (p);
}

t_point	autreline(int *tab, t_point p, t_mlx t, int *tab2)
{
	int		i;
	t_point	un;
	t_point	de;

	i = 0;
	while (tab[i] != 10585510)
	{
		un.x = p.x;
		un.y = p.y - tab[i];
		if (tab[i + 1] != 10585510)
		{
			de.x = p.x + p.t;
			de.y = p.y + (p.t / 2) - tab[i + 1];
			if (un.x <= 1600 && un.x >= -100 && de.x <= 1600 && de.x >= -100
				&& un.y <= 1400 && un.y >= -100 && de.y <= 1400 && de.y >= -100)
				seg(un, de, t);
		}
		de.x = p.x + p.t;
		de.y = p.y - (p.t / 2) - tab2[i];
		seg(un, de, t);
		p.x = p.x + p.t;
		p.y = p.y + (p.t / 2);
		i++;
	}
	return (p);
}

void	line(char *line, int *tab, t_point p, t_mlx t)
{
	int	*tab2;

	while (line)
	{
		tab2 = ft_intdup(tab);
		p.x = (p.x - (p.t * comppoint(line))) - (p.t);
		p.y = (p.y - ((p.t / 2) * comppoint(line))) + (p.t / 2);
		if (tab)
			free(tab);
		tab = getint(line);
		p = autreline(tab, p, t, tab2);
		line = get_next_line(t.fd);
	}
}

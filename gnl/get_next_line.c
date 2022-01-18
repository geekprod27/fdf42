/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.frn>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 12:34:06 by nfelsemb          #+#    #+#             */
/*   Updated: 2022/01/12 07:32:19 by nfelsemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*cleanbuf(char *buf, char	*ret)
{
	int	j;
	int	i;

	i = 0;
	j = len(buf);
	if (buf[j] == '\n')
		++j;
	while (buf[j])
	{
		buf[i] = buf[j];
		++i;
		++j;
	}
	while (buf[i])
	{
		buf[i] = 0;
		++i;
	}
	return (ret);
}

char	*freeline(char *ret)
{
	if (!ret)
		return (0);
	free(ret);
	return (0);
}

char	*get_next_line(int fd)
{
	static char		buf[BUFFER_SIZE + 1];
	int				i;
	char			*ret;

	if (BUFFER_SIZE <= 0 || read(fd, buf, 0) == -1)
		return (0);
	ret = ft_strdupgnl("");
	ret = ft_strjoingnl(ret, buf);
	i = 1;
	while (i > 0 && !isnn(buf))
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i == -1)
			return (freeline(ret));
		if (i)
		{
			buf[i] = 0;
			ret = ft_strjoingnl(ret, buf);
		}
		else if (i == 0 && buf[0])
			return (cleanbuf(buf, ret));
		else
			return (freeline(ret));
	}
	return (cleanbuf(buf, ret));
}

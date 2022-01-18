/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 12:34:06 by nfelsemb          #+#    #+#             */
/*   Updated: 2021/12/08 14:34:36 by nfelsemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char		buf[1024][BUFFER_SIZE + 1];
	int				i;
	char			*ret;

	if (BUFFER_SIZE <= 0 || read(fd, buf[fd], 0) == -1)
		return (0);
	ret = ft_strdup("");
	ret = ft_strjoin(ret, buf[fd]);
	i = 1;
	while (i > 0 && !isnn(buf[fd]))
	{
		i = read(fd, buf[fd], BUFFER_SIZE);
		if (i == -1)
			return (freeline(ret));
		if (i)
		{
			buf[fd][i] = 0;
			ret = ft_strjoin(ret, buf[fd]);
		}
		else if (i == 0 && buf[fd][0])
			return (cleanbuf(buf[fd], ret));
		else
			return (freeline(ret));
	}
	return (cleanbuf(buf[fd], ret));
}

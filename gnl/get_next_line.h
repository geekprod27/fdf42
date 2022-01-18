/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.frn>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 12:33:59 by nfelsemb          #+#    #+#             */
/*   Updated: 2022/01/12 07:32:26 by nfelsemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# define BUFFER_SIZE 10

char	*get_next_line(int fd);
char	*ft_strjoingnl(char *s1, char *s2);
char	*ft_strdupgnl(char *s);
int		isnn(char	*str);
int		len(char *str);

#endif
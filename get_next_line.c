/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpikkuma <jpikkuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 11:16:57 by jpikkuma          #+#    #+#             */
/*   Updated: 2021/12/14 00:10:16 by jpikkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int	ft_strnchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		++i;
	}
	if (s[i] == c)
		return (1);
	return (0);
}

static int	ft_join_buff(int fd, char **buff, char *c)
{
	char	*tmp;

	tmp = ft_strjoin(buff[fd], c);
	if (!tmp)
	{
		ft_strdel(&buff[fd]);
		return (0);
	}
	else
	{
		free(buff[fd]);
		buff[fd] = tmp;
		return (1);
	}
}

static int	ft_set_line(int fd, char **buff, char **line)
{
	char	*tmp;
	size_t	i;
	int		status;

	status = 1;
	i = 0;
	while ((buff[fd][i] != '\n') && (buff[fd][i] != '\0'))
		++i;
	if (buff[fd][i] == '\n')
	{
		*line = ft_strsub(buff[fd], 0, i);
		tmp = ft_strdup(&buff[fd][i + 1]);
		if (!*line || !tmp)
			status = 0;
		ft_strdel(&buff[fd]);
		buff[fd] = tmp;
	}
	else
	{
		*line = ft_strdup(buff[fd]);
		if (!*line)
			status = 0;
		ft_strdel(&buff[fd]);
	}
	return (status);
}

static int	ft_return_line(int fd, char **buff, char **line, ssize_t len)
{
	if (len < 0)
	{
		ft_strdel(&buff[fd]);
		return (-1);
	}
	if (buff[fd][0] == '\0')
	{
		ft_strdel(&buff[fd]);
		return (0);
	}
	if (!ft_set_line(fd, buff, line))
		return (-1);
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	static char	*buff[FD_BUFF + 1];
	char		c[BUFF_SIZE + 1];
	ssize_t		len;

	if (fd < 0 || FD_BUFF < 1 || BUFF_SIZE < 1 || fd > FD_BUFF)
		return (-1);
	if (!buff[fd])
		buff[fd] = ft_strdup("");
	if (!buff[fd])
		return (-1);
	if (ft_strnchr(buff[fd], '\n'))
		return (ft_return_line(fd, buff, line, 0));
	while (1)
	{
		len = read(fd, c, BUFF_SIZE);
		if (len <= 0)
			return (ft_return_line(fd, buff, line, len));
		c[len] = '\0';
		if (!ft_join_buff(fd, buff, c))
			return (-1);
		if (ft_strnchr(c, '\n'))
			return (ft_return_line(fd, buff, line, len));
	}
}

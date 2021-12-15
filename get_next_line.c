/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpikkuma <jpikkuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 11:16:57 by jpikkuma          #+#    #+#             */
/*   Updated: 2021/12/15 11:20:53 by jpikkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

static size_t	ft_linelen(int fd, char **buff)
{
	size_t	i;

	i = 0;
	while ((buff[fd][i] != '\n') && (buff[fd][i] != '\0'))
		++i;
	return (i);
}

static int	ft_set_line(int fd, char **buff, char **line, size_t i)
{
	char	*tmp;

	if (buff[fd][i] == '\n')
	{
		*line = ft_strsub(buff[fd], 0, i);
		tmp = ft_strdup(&buff[fd][i + 1]);
		if (!*line || !tmp)
		{
			ft_strdel(&tmp);
			ft_strdel(line);
			return (0);
		}
		ft_strdel(&buff[fd]);
		buff[fd] = tmp;
		if (buff[fd][0] == '\0')
			ft_strdel(&buff[fd]);
	}
	else
	{
		*line = ft_strdup(buff[fd]);
		if (!*line)
			return (0);
		ft_strdel(&buff[fd]);
	}
	return (1);
}

static int	ft_return_line(int fd, char **buff, char **line, ssize_t len)
{
	size_t	i;

	if (buff[fd])
		i = ft_linelen(fd, buff);
	if (len < 0)
	{
		ft_strdel(&buff[fd]);
		return (-1);
	}
	else if (len == 0 && !buff[fd])
		return (0);
	else if (!ft_set_line(fd, buff, line, i))
		return (-1);
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	static char	*buff[FD_BUFF + 1];
	char		c[BUFF_SIZE + 1];
	ssize_t		len;

	if (fd < 0 || FD_BUFF < 1 || BUFF_SIZE < 1 || fd > FD_BUFF || !line)
		return (-1);
	if (buff[fd])
		if (ft_strchr(buff[fd], '\n'))
			return (ft_return_line(fd, buff, line, 0));
	len = read(fd, c, BUFF_SIZE);
	while (len > 0)
	{
		if (!buff[fd])
			buff[fd] = ft_strdup("");
		if (!buff[fd])
			return (-1);
		c[len] = '\0';
		if (!ft_join_buff(fd, buff, c))
			return (-1);
		if (ft_strchr(c, '\n'))
			break ;
		len = read(fd, c, BUFF_SIZE);
	}
	return (ft_return_line(fd, buff, line, len));
}

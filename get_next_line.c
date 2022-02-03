/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpikkuma <jpikkuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 11:16:57 by jpikkuma          #+#    #+#             */
/*   Updated: 2022/02/03 19:22:10 by jpikkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_join_buffer(int fd, char **buffer, char *c)
{
	char	*temp;

	temp = ft_strjoin(buffer[fd], c);
	if (!temp)
	{
		ft_strdel(&buffer[fd]);
		return (0);
	}
	else
	{
		free(buffer[fd]);
		buffer[fd] = temp;
		return (1);
	}
}

static int	ft_set_line(int fd, char **buffer, char **line, size_t i)
{
	char	*temp;

	if (buffer[fd][i] == '\n')
	{
		*line = ft_strsub(buffer[fd], 0, i);
		temp = ft_strdup(&buffer[fd][i + 1]);
		if (!*line || !temp)
		{
			ft_strdel(&temp);
			ft_strdel(line);
			return (0);
		}
		ft_strdel(&buffer[fd]);
		buffer[fd] = temp;
		if (buffer[fd][0] == '\0')
			ft_strdel(&buffer[fd]);
	}
	else
	{
		*line = ft_strdup(buffer[fd]);
		if (!*line)
			return (0);
		ft_strdel(&buffer[fd]);
	}
	return (1);
}

static int	ft_return_line(int fd, char **buffer, char **line, ssize_t ret)
{
	size_t	i;

	i = 0;
	if (buffer[fd])
	{
		while ((buffer[fd][i] != '\n') && (buffer[fd][i] != '\0'))
		++i;
	}
	if (ret < 0)
	{
		ft_strdel(&buffer[fd]);
		return (-1);
	}
	else if (ret == 0 && !buffer[fd])
		return (0);
	else if (!ft_set_line(fd, buffer, line, i))
		return (-1);
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	static char	*buffer[FD_BUFF + 1];
	char		temp[BUFF_SIZE + 1];
	ssize_t		ret;

	if (fd < 0 || FD_BUFF < 1 || BUFF_SIZE < 1 || fd > FD_BUFF || !line)
		return (-1);
	if (buffer[fd])
		if (ft_strchr(buffer[fd], '\n'))
			return (ft_return_line(fd, buffer, line, 0));
	ret = read(fd, temp, BUFF_SIZE);
	while (ret > 0)
	{
		if (!buffer[fd])
			buffer[fd] = ft_strdup("");
		if (!buffer[fd])
			return (-1);
		temp[ret] = '\0';
		if (!ft_join_buffer(fd, buffer, temp))
			return (-1);
		if (ft_strchr(temp, '\n'))
			break ;
		ret = read(fd, temp, BUFF_SIZE);
	}
	return (ft_return_line(fd, buffer, line, ret));
}

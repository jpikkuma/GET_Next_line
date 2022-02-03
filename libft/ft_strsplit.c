/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpikkuma <jpikkuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 18:36:17 by jpikkuma          #+#    #+#             */
/*   Updated: 2021/12/24 09:59:10 by jpikkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_w_count(const char *s, char c)
{
	size_t	wc;

	if (!s[0])
		return (0);
	wc = 0;
	if (*s && *s != c)
		wc++;
	while (*s)
	{
		if (*(s - 1) == c && *s != c)
			wc++;
		s++;
	}
	return (wc);
}

static void	ft_get_str(const char **str, size_t *len, char c)
{
	size_t	i;

	*str += *len;
	*len = 0;
	i = 0;
	while (**str && **str == c)
		(*str)++;
	while ((*str)[i])
	{
		if ((*str)[i] == c)
			return ;
		(*len)++;
		i++;
	}
}

static char	**ft_freemem(char **splitted)
{
	while (*splitted)
	{
		free(*splitted);
		splitted++;
	}
	free(*splitted);
	return (NULL);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**splitted;
	size_t	len;
	size_t	wc;
	size_t	i;

	if (!s)
		return (NULL);
	wc = ft_w_count(s, c);
	splitted = (char **)ft_memalloc(sizeof(char *) * (wc + 1));
	if (!splitted)
		return (NULL);
	i = 0;
	len = 0;
	while (i < wc)
	{
		ft_get_str(&s, &len, c);
		splitted[i] = ft_strnew(len + 1);
		if (!splitted[i])
			return (ft_freemem(splitted));
		ft_memcpy(splitted[i++], s, len);
	}
	splitted[i] = NULL;
	return (splitted);
}

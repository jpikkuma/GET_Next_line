/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpikkuma <jpikkuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 18:36:17 by jpikkuma          #+#    #+#             */
/*   Updated: 2021/12/14 00:25:33 by jpikkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_w_count(const char *s, char c)
{
	size_t	wc;
	size_t	i;

	if (!s[0])
		return (0);
	wc = 0;
	i = 0;
	if (s[i] && s[i] != c)
		wc++;
	i++;
	while (s[i])
	{
		if (s[i - 1] == c && s[i] != c)
		{
			wc++;
			i++;
		}
		else
			i++;
	}
	return (wc);
}

static void	ft_get_str(char **str, size_t *len, char c)
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
	size_t	i;

	i = 0;
	while (splitted[i])
	{
		free(splitted[i]);
		i++;
	}
	free(splitted);
	return (NULL);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**splitted;
	char	*str;
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
	str = (char *)s;
	len = 0;
	while (i < wc)
	{
		ft_get_str(&str, &len, c);
		splitted[i] = ft_strnew(len + 1);
		if (!splitted[i])
			return (ft_freemem(splitted));
		ft_memcpy(splitted[i++], str, len);
	}
	splitted[i] = NULL;
	return (splitted);
}

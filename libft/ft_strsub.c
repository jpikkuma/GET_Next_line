/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpikkuma <jpikkuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 13:37:25 by jpikkuma          #+#    #+#             */
/*   Updated: 2021/12/14 00:25:42 by jpikkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*fresh;
	size_t	i;

	if (!s)
		return (0);
	fresh = ft_strnew(len);
	if (!fresh)
		return (NULL);
	if (start + len > ft_strlen(s))
		return (ft_strdup(""));
	i = 0;
	while (s[start] && i < len)
	{
		fresh[i] = s[start];
		i++;
		start++;
	}
	return (fresh);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpikkuma <jpikkuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 18:37:03 by jpikkuma          #+#    #+#             */
/*   Updated: 2021/12/23 02:08:38 by jpikkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*fresh;
	size_t	s1len;
	size_t	s2len;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	if (!s1 || !s2)
		return (NULL);
	fresh = ft_strnew(s1len + s2len);
	if (!fresh)
		return (NULL);
	ft_memcpy((void *)fresh, (void *)s1, s1len);
	ft_memcpy((void *)(fresh + s1len), (void *)s2, s2len + 1);
	return (fresh);
}

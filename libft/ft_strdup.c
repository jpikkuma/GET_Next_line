/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpikkuma <jpikkuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 08:18:38 by jpikkuma          #+#    #+#             */
/*   Updated: 2021/12/22 23:41:34 by jpikkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	len;

	len = ft_strlen(s);
	dup = (char *)ft_memalloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	ft_memcpy((void *)dup, (const void *)s, len + 1);
	return (dup);
}

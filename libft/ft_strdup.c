/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpikkuma <jpikkuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 08:18:38 by jpikkuma          #+#    #+#             */
/*   Updated: 2021/12/14 00:24:28 by jpikkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;

	dup = (char *)ft_memalloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!dup)
		return (NULL);
	ft_strcpy(dup, s);
	return (dup);
}

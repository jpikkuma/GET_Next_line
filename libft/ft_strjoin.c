/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpikkuma <jpikkuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 18:37:03 by jpikkuma          #+#    #+#             */
/*   Updated: 2021/12/14 00:24:38 by jpikkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*fresh;

	if (!s1 || !s2)
		return (NULL);
	fresh = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (!fresh)
		return (NULL);
	ft_strcpy(fresh, s1);
	return (ft_strcat(fresh, s2));
}

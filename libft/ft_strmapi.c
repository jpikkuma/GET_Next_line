/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpikkuma <jpikkuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 18:36:48 by jpikkuma          #+#    #+#             */
/*   Updated: 2021/12/14 00:24:58 by jpikkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*fresh;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	fresh = ft_strnew(ft_strlen(s));
	if (!fresh)
		return (NULL);
	i = 0;
	while (s[i])
	{
		fresh[i] = f(i, s[i]);
		i++;
	}
	return (fresh);
}

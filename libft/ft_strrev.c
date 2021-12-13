/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpikkuma <jpikkuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 18:40:28 by jpikkuma          #+#    #+#             */
/*   Updated: 2021/11/19 14:56:47 by jpikkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"includes/libft.h"

char	*ft_strrev(char *s)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s);
	if (len)
		len--;
	while (i < len)
	{
		s[i] ^= s[len];
		s[len] ^= s[i];
		s[i] ^= s[len];
		i++;
		len--;
	}
	return (s);
}

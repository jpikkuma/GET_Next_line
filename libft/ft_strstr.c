/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpikkuma <jpikkuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 19:13:34 by jpikkuma          #+#    #+#             */
/*   Updated: 2021/12/14 00:25:37 by jpikkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!needle[0])
		return ((char *)haystack);
	while (haystack[i])
	{
		j = 0;
		while (needle[j] == haystack[i + j] && haystack[i + j])
		{
			j++;
			if (!needle[j])
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}

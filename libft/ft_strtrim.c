/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpikkuma <jpikkuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 18:35:54 by jpikkuma          #+#    #+#             */
/*   Updated: 2021/12/14 00:25:46 by jpikkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_iswspace(char c)
{
	return (c == 9 || c == 10 || c == 32);
}

char	*ft_strtrim(char const *s)
{
	char	*trimmed;
	int		start;
	int		end;
	int		i;

	start = 0;
	i = 0;
	if (!s)
		return (NULL);
	end = (int)ft_strlen(s) - 1;
	if (end + 1 < 0)
		return (NULL);
	while (ft_iswspace(s[start]) && s[start])
		start++;
	while (ft_iswspace(s[end]) && end >= 0)
		end--;
	if (start > end++)
		return (ft_strdup(""));
	trimmed = ft_strnew((size_t)(end - start));
	if (!trimmed)
		return (NULL);
	while (start < end)
		trimmed[i++] = s[start++];
	return (trimmed);
}

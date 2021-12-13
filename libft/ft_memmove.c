/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpikkuma <jpikkuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 00:30:46 by jpikkuma          #+#    #+#             */
/*   Updated: 2021/11/19 14:54:47 by jpikkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*stmp;
	char	*dtmp;

	if (!dest && !src)
		return (NULL);
	stmp = (char *)src;
	dtmp = (char *)dest;
	if (dtmp > stmp)
	{
		while (n-- > 0)
			dtmp[n] = stmp[n];
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}

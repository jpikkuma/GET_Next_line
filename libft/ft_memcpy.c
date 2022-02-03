/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpikkuma <jpikkuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 00:30:16 by jpikkuma          #+#    #+#             */
/*   Updated: 2021/12/22 23:32:17 by jpikkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	uint64_t		*d;
	uint64_t		*s;
	size_t			cr[2];
	unsigned char	*d1;
	unsigned char	*s1;

	if (n == 0 || src == dest)
		return (dest);
	d = (uint64_t *)dest;
	s = (uint64_t *)src;
	cr[0] = n / sizeof(uint64_t);
	cr[1] = n % sizeof(uint64_t);
	while (cr[0]--)
		*d++ = *s++;
	d1 = (unsigned char *)d;
	s1 = (unsigned char *)s;
	while (cr[1]--)
		*d1++ = *s1++;
	return (dest);
}

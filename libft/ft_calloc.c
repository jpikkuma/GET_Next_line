/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpikkuma <jpikkuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 17:14:25 by jpikkuma          #+#    #+#             */
/*   Updated: 2021/12/14 00:21:58 by jpikkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*fresh;

	if (nmemb * size > 2147483647)
		return (NULL);
	if (!nmemb || !size)
	{
		fresh = ft_memalloc(1);
		if (!fresh)
			return (NULL);
		return (fresh);
	}
	fresh = ft_memalloc(nmemb * size);
	if (!fresh)
		return (NULL);
	return (fresh);
}

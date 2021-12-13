/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpikkuma <jpikkuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 18:38:25 by jpikkuma          #+#    #+#             */
/*   Updated: 2021/12/14 00:23:00 by jpikkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*fresh;

	fresh = (void *)malloc(sizeof(void) * size);
	if (!fresh)
		return (NULL);
	ft_memset(fresh, 0, size);
	return (fresh);
}

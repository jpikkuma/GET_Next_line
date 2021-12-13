/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpikkuma <jpikkuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 21:34:08 by jpikkuma          #+#    #+#             */
/*   Updated: 2021/11/19 14:56:37 by jpikkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnew(size_t size)
{
	char	*new;

	new = (char *)ft_memalloc(sizeof(char) * (size + 1));
	if (!new)
		return (NULL);
	return (new);
}

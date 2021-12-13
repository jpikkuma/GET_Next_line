/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpikkuma <jpikkuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 18:38:31 by jpikkuma          #+#    #+#             */
/*   Updated: 2021/12/14 00:22:32 by jpikkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_intlen(int n)
{
	size_t	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*fresh;
	size_t	i;
	long	number;

	i = ft_intlen(n);
	number = n;
	fresh = ft_strnew(i);
	if (!fresh)
		return (NULL);
	if (number == 0)
		fresh[0] = '0';
	if (number < 0)
	{
		fresh[0] = '-';
		number *= -1;
	}
	--i;
	while (number > 0)
	{
		fresh[i] = (char)(number % 10) + '0';
		number /= 10;
		--i;
	}
	return (fresh);
}

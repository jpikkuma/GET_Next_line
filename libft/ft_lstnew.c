/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpikkuma <jpikkuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 19:32:54 by jpikkuma          #+#    #+#             */
/*   Updated: 2021/12/14 00:22:56 by jpikkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*fresh;

	fresh = (t_list *)ft_memalloc(sizeof(t_list));
	if (!fresh)
		return (NULL);
	if (!content)
	{
		fresh->content = NULL;
		fresh->content_size = 0;
	}
	else
	{
		fresh->content = (void *)ft_memalloc(sizeof(void) * content_size);
		if (!fresh->content)
		{
			free(fresh);
			return (NULL);
		}
		fresh->content_size = content_size;
		ft_memcpy(fresh->content, content, content_size);
	}
	fresh->next = NULL;
	return (fresh);
}

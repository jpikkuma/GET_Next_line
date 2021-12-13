/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpikkuma <jpikkuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 19:32:34 by jpikkuma          #+#    #+#             */
/*   Updated: 2021/12/14 00:22:40 by jpikkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*link;
	t_list	*next;

	if (!del || !*alst)
		return ;
	link = *alst;
	while (link)
	{
		next = link->next;
		del(link->content, link->content_size);
		free(link);
		link = next;
	}
	*alst = NULL;
}

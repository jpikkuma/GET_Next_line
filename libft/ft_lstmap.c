/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpikkuma <jpikkuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 19:32:50 by jpikkuma          #+#    #+#             */
/*   Updated: 2021/12/14 00:22:52 by jpikkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*fresh;
	t_list	*start;

	fresh = ft_lstnew(f(lst)->content, f(lst)->content_size);
	if (!fresh)
		return (NULL);
	start = fresh;
	while (lst->next)
	{
		lst = lst->next;
		fresh->next = ft_lstnew(f(lst)->content, f(lst)->content_size);
		if (!fresh->next)
			return (NULL);
		fresh = fresh->next;
	}
	return (start);
}

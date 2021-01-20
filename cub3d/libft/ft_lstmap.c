/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gim <gim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 19:19:31 by gim               #+#    #+#             */
/*   Updated: 2020/10/01 12:56:44 by gim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*elem;
	t_list	*temp;

	if (lst == NULL || f == NULL)
		return (NULL);
	elem = NULL;
	while (lst)
	{
		if (!(temp = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&elem, del);
			return (NULL);
		}
		ft_lstadd_back(&elem, temp);
		temp = temp->next;
		lst = lst->next;
	}
	return (elem);
}

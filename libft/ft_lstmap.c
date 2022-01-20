/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 21:59:17 by mbenkhat          #+#    #+#             */
/*   Updated: 2021/11/13 10:52:39 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*hold;
	t_list	*nex;
	t_list	*new;

	if (!lst || !f)
		return (NULL);
	new = ft_lstnew((*f)(lst->content));
	if (!new)
		ft_lstclear(&new, del);
	if (!new)
		return (NULL);
	hold = new;
	lst = lst->next;
	while (lst)
	{
		nex = ft_lstnew((*f)(lst->content));
		if (!nex)
			ft_lstclear(&hold, del);
		if (!nex)
			return (NULL);
		new->next = nex;
		new = nex;
		lst = lst->next;
	}
	return (hold);
}

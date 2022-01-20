/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 20:19:47 by mbenkhat          #+#    #+#             */
/*   Updated: 2021/11/13 09:56:31 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*hold;
	t_list	*head;

	head = *lst;
	if (!del || !lst || !*lst)
		return ;
	while (*lst && lst)
	{
		hold = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = hold;
	}
	head = NULL;
}

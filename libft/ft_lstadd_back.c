/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 17:46:24 by mbenkhat          #+#    #+#             */
/*   Updated: 2021/11/12 21:12:01 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*hold;

	if (!(*lst) || !(new))
		*lst = new;
	else
	{
		hold = *lst;
		while (hold->next != NULL)
		{
			hold = hold->next;
		}
		hold->next = new;
	}
}

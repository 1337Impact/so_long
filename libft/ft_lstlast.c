/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 16:50:33 by mbenkhat          #+#    #+#             */
/*   Updated: 2021/11/11 17:07:23 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*hold;

	if (lst == NULL)
		return (NULL);
	hold = lst;
	while (hold->next != NULL)
	{
		hold = hold->next;
	}
	return (hold);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 21:22:11 by mbenkhat          #+#    #+#             */
/*   Updated: 2021/11/09 11:55:17 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int		a;
	char	*cdst;
	char	*csrc;

	a = len - 1;
	cdst = (char *)dst;
	csrc = (char *)src;
	if (len == 0)
		return (dst);
	if (cdst == NULL && csrc == NULL)
		return (NULL);
	if (cdst > csrc)
	{
		while (a >= 0)
		{
			cdst[a] = csrc[a];
			a--;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}

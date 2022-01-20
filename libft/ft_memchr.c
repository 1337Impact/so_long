/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 20:55:53 by mbenkhat          #+#    #+#             */
/*   Updated: 2021/11/09 12:45:38 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*cs;
	unsigned char	uc;
	size_t			i;

	cs = (unsigned char *)s;
	uc = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (cs[i] == uc)
		{
			return ((void *)&cs[i]);
		}
		i++;
	}
	return (0);
}

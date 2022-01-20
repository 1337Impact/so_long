/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 18:23:26 by mbenkhat          #+#    #+#             */
/*   Updated: 2021/11/08 11:52:56 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	a;

	a = (char)c;
	while (*s != a && *s)
	{
		s++;
	}
	if (*s == '\0')
	{
		if (a == '\0')
		{
			return ((char *)s);
		}
		return (NULL);
	}
	return ((char *)s);
}

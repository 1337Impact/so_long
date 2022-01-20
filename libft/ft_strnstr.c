/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:28:58 by mbenkhat          #+#    #+#             */
/*   Updated: 2021/11/10 18:49:54 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	a;

	i = 0;
	if (needle[0] == '\0')
	{
		return ((char *)haystack);
	}
	while (i < len && haystack[i])
	{
		a = 0;
		while (haystack[i + a] == needle[a] && needle[a] && a + i < len)
		{
			a++;
		}
		if (needle[a] == '\0')
		{
			return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}

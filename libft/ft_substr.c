/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 10:59:33 by mbenkhat          #+#    #+#             */
/*   Updated: 2021/11/12 19:11:59 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	if (!s)
		return (0);
	substr = (char *)malloc(len + 1);
	if (substr == NULL)
		return (NULL);
	i = 0;
	if (start < ft_strlen(s))
	{
		while (i < len && s[i + start])
		{
			substr[i] = s[i + start];
			i++;
		}
	}
	substr[i] = 0;
	return (substr);
}

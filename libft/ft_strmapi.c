/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 11:50:33 by mbenkhat          #+#    #+#             */
/*   Updated: 2021/11/12 20:50:41 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*out;
	int		size;

	i = 0;
	if (!s || !f)
		return (0);
	size = ft_strlen(s);
	out = (char *)malloc(size + 1);
	if (!out)
		return (NULL);
	while (s[i])
	{
		out[i] = (*f)(i, s[i]);
		i++;
	}
	out[size] = 0;
	return (out);
}

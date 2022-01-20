/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 13:00:08 by mbenkhat          #+#    #+#             */
/*   Updated: 2021/11/12 20:10:20 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	checker(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		x;
	char	*trim;

	i = 0;
	if (!s1 || !set)
		return (0);
	while (checker((char *)set, (char)s1[i]) && s1[i])
		i++;
	j = ft_strlen(s1) - 1;
	while (checker((char *)set, (char)s1[j]) && j > i)
		j--;
	trim = (char *)malloc(j - i + 2);
	if (trim == NULL)
		return (NULL);
	x = 0;
	while (i <= j && ((*s1) || (*set)))
	{
		trim[x++] = s1[i++];
	}
	trim[x] = 0;
	return (trim);
}

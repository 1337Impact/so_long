/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 19:42:23 by mbenkhat          #+#    #+#             */
/*   Updated: 2021/11/08 11:51:36 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	int		i;
	int		a;
	char	*array;

	array = (char *)s;
	i = 0;
	a = (int)n;
	while (i < a)
	{
		array[i] = '\0';
		i++;
	}
}

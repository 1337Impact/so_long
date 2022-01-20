/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 21:25:18 by mbenkhat          #+#    #+#             */
/*   Updated: 2021/11/08 11:52:37 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int		i;
	int		lim;
	char	*array;

	i = 0;
	lim = (int)len;
	array = (char *) b;
	while (i < lim)
	{
		array[i] = c;
		i++;
	}
	return ((void *) array);
}

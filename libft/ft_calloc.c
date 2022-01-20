/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 19:48:15 by mbenkhat          #+#    #+#             */
/*   Updated: 2021/11/09 11:19:05 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*out;

	out = malloc(count * size);
	if (out == NULL)
	{
		return (NULL);
	}
	ft_bzero(out, count * size);
	return ((void *)out);
}

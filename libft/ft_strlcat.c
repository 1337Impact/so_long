/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 18:27:59 by mbenkhat          #+#    #+#             */
/*   Updated: 2021/11/13 10:54:58 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	int	i;
	int	dst_len;
	int	src_len;
	int	idstsize;

	i = 0;
	idstsize = (int)dstsize;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (idstsize == 0)
	{
		return (src_len);
	}
	if (idstsize < dst_len)
	{
		return (src_len + idstsize);
	}
	while (i < idstsize - dst_len - 1 && src[i])
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 17:42:16 by mbenkhat          #+#    #+#             */
/*   Updated: 2021/11/12 16:11:49 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	sizeofn(long int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void	fill(char *s, long int n, int size)
{
	int	x;
	int	a;

	x = size - 1;
	a = 0;
	if (n < 0)
	{
		s[0] = '-';
		n = -n;
		a = 1;
	}
	while (x >= a)
	{
		s[x] = (n % 10) + '0';
		n = n / 10;
		x--;
	}
}

char	*ft_itoa(int n)
{
	char		*out;
	long int	ln;
	int			i;
	int			size;

	i = 0;
	ln = n;
	if (ln == -0 || ln == 0)
	{
		out = malloc (sizeof(char) * 2);
		if (out == NULL)
		{
			return (NULL);
		}
		out[0] = 0 + '0';
		out[1] = '\0';
		return (out);
	}
	size = sizeofn(ln);
	out = (char *)malloc(size + 1);
	if (out == NULL)
		return (NULL);
	fill(out, ln, size);
	out[size] = 0;
	return (out);
}

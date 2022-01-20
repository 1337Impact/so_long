/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 13:38:44 by mbenkhat          #+#    #+#             */
/*   Updated: 2021/11/12 19:19:06 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putn(long int n, int fd)
{
	long int	ln;

	ln = n;
	if (ln == 0)
		ft_putchar_fd(ln + '0', fd);
	if (ln < 0)
	{
		ft_putchar_fd('-', fd);
		ln = -ln;
	}
	if (ln <= 9 && ln)
	{
		ft_putchar_fd(ln + '0', fd);
	}
	if (ln > 9)
	{
		ft_putn(ln / 10, fd);
		ln = ln % 10;
		ft_putchar_fd(ln + '0', fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	ft_putn(n, fd);
}

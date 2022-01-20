/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 12:45:47 by mbenkhat          #+#    #+#             */
/*   Updated: 2021/11/12 12:32:44 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	char	end;

	end = '\n';
	if (!s)
		return ;
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
	write(fd, &end, 1);
}

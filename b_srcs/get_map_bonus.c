/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 15:00:43 by mbenkhat          #+#    #+#             */
/*   Updated: 2022/01/08 17:04:39 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

char	*get_next_line(int fd)
{
	char	*str;
	char	*buff;

	str = malloc(1);
	if (!str)
		return (0);
	str[0] = 0;
	buff = malloc(2);
	if (!str)
		return (0);
	if (read(fd, NULL, 0) == -1)
		return (0);
	while (read(fd, buff, 1))
	{
		str = ft_strjoin(str, buff);
		if (!str)
			return (0);
		free(buff);
		buff = malloc(2);
	}
	free((void *)buff);
	return (str);
}

int	check_nl(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\n')
		return (0);
	while (str[i])
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
			return (0);
		i++;
	}
	if (str[i - 1] == '\n')
		return (0);
	return (1);
}

char	**get_map(char *file)
{
	int		fd;
	char	**map;
	char	*str;

	fd = open(file, O_RDONLY);
	str = get_next_line(fd);
	if (!str)
		exit(0);
	if (!check_nl(str))
	{
		ft_putstr_fd("Error\nMap not rectangular\n", 1);
		exit(0);
	}
	map = ft_split(str, '\n');
	if (!map)
		exit(0);
	close(fd);
	return (map);
}

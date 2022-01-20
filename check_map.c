/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 15:20:33 by mbenkhat          #+#    #+#             */
/*   Updated: 2022/01/05 17:51:10 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_walls(char **map)
{
	int	i;
	int	last;

	i = 0;
	while (map[0][i])
		if (map[0][i++] != '1')
			return (0);
	i = 0;
	last = (map_height(map) - 1);
	while (map[last][i])
		if (map[last][i++] != '1')
			return (0);
	i = 0;
	while (map[i])
		if (map[i++][0] != '1')
			return (0);
	i = 0;
	last = (ft_strlen(map[0]) - 1);
	while (map[i])
		if (map[i++][last] != '1')
			return (0);
	return (1);
}

int	check_caracters(char **map)
{
	int	i;

	while (*map)
	{
		i = 0;
		while ((*map)[i])
		{
			if (((*map)[i] != '1') && ((*map)[i] != '0') && ((*map)[i] != 'C')
				&& ((*map)[i] != 'E') && ((*map)[i] != 'P'))
				return (0);
			i++;
		}
		map++;
	}
	return (1);
}

int	check_ecp(char **map)
{
	int	i;
	int	e;
	int	c;
	int	p;

	e = 0;
	c = 0;
	p = 0;
	while (*map)
	{
		i = -1;
		while ((*map)[++i])
		{
			if ((*map)[i] == 'E')
				e++;
			if ((*map)[i] == 'C')
				c++;
			if ((*map)[i] == 'P')
				p++;
		}
		map++;
	}
	if ((e == 0) || (c == 0) || (p != 1))
		return (0);
	return (1);
}

int	check_rectangular(char **map)
{
	int		i;
	size_t	len;

	i = 1;
	len = ft_strlen(map[0]);
	while (map[i])
		if (ft_strlen(map[i++]) != len)
			return (0);
	return (1);
}

int	check_map(char **map)
{
	if (!check_caracters(map))
	{
		ft_putstr_fd("Error\nUse of a forbiden character\n", 1);
		return (0);
	}
	if (!check_walls(map))
	{
		ft_putstr_fd("Error\nMap not surrounded by walls\n", 1);
		return (0);
	}
	if (!check_rectangular(map) || ((int)ft_strlen(map[1]) <= map_height(map)))
	{
		ft_putstr_fd("Error\nMap not rectangular\n", 1);
		return (0);
	}
	if (!check_ecp(map))
	{
		ft_putstr_fd("Error\nMap has a missing character", 1);
		ft_putstr_fd(" or more than one player\n", 1);
		return (0);
	}
	return (1);
}

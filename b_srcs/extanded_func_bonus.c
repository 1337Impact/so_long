/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extanded_func_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 13:22:14 by mbenkhat          #+#    #+#             */
/*   Updated: 2022/01/07 11:11:53 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

t_xy	get_char(char **map, char c)
{
	int		a;
	int		i;
	t_xy	xy;

	a = 0;
	xy.y = 0;
	while (map[a])
	{
		i = 0;
		xy.x = 0;
		while (map[a][i])
		{
			if (map[a][i++] == c)
				return (xy);
			xy.x++;
		}
		a++;
		xy.y++;
	}
	xy.x = 0;
	return (xy);
}

int	exit_program(t_data *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (i < 40000)
	{
		j = 0;
		while (j < 10000)
			j++;
		i++;
	}
	mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_win);
	exit(0);
}

int	map_height(char **map)
{
	int	i;

	i = 0;
	while (*(map++))
		i++;
	return (i);
}
